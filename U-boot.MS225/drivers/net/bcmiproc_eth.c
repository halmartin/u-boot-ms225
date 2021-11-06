/*
 * Copyright (C) 2013, Broadcom Corporation. All Rights Reserved.
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <common.h>
#include <malloc.h>
#include <net.h>
#include <config.h>
#include <asm/arch/ethHw.h>
#include <asm/arch/ethHw_dma.h>

#include "bcmiproc_debug.h"

#define BCMIPROC_ETH_DEV_NAME           "bcmiproc_eth"
#define BCM_NET_MODULE_DESCRIPTION      "Broadcom BCM IPROC Ethernet driver"
#define BCM_NET_MODULE_VERSION          "0.1"

static const char banner[] = BCM_NET_MODULE_DESCRIPTION " " BCM_NET_MODULE_VERSION "\n";

/******************************************************************
 * u-boot net functions
 ******************************************************************/
static int
bcmiproc_eth_send(struct eth_device *dev, volatile void *packet, int length)
{
    int devid = dev->index;
    uint8_t *buf = (uint8_t *)packet;
    int rc = 0;

    NET_TRACE(("et%d: %s enter\n", devid, __FUNCTION__));

    /* Load buf and start transmit */
    rc = ethHw_dmaTx(devid, buf, length);
    if (rc) {
        NET_ERROR(("et%d: transmitted packet failed.\n", devid));
        return rc;
    }

    rc = ethHw_dmaTxWait(devid);
    if (rc) {
        NET_ERROR(("et%d: no transmitted notice.\n", devid));
        return rc;
    }

    NET_TRACE(("et%d: %s exit\n", devid, __FUNCTION__));
    return rc;
}

static int
bcmiproc_eth_recv(struct eth_device *dev)
{
    int devid = dev->index;
    uint8_t *buf = (uint8_t *)NetRxPackets[0];
    int length;
    int rc = 0;

    NET_TRACE(("et%d: %s enter\n", devid, __FUNCTION__));

    while(1) {
        rc = ethHw_dmaRx(devid, buf, (size_t *)&length);
        if (rc) {
            break;
        }

#ifdef UBOOT_MDK
        /* Send to MDK handler instead */
        mdk_rcv_handler(buf, length);
#else
        /* A packet has been received, so forward to uboot network handler */
        NetReceive(buf, length);
#endif
    }
    NET_TRACE(("et%d: %s exit\n", devid, __FUNCTION__));
    return rc;
}


static int
bcmiproc_eth_write_hwaddr(struct eth_device* dev)
{
    NET_TRACE(("et%d: %s enter\n", dev->index, __FUNCTION__));

    NET_TRACE(("%s Not going to change MAC address\n", __FUNCTION__));
    NET_TRACE(("et%d: %s exit\n", dev->index, __FUNCTION__));

    return 0;
}

static int
bcmiproc_eth_open(struct eth_device *dev, bd_t *bt)
{
    int devid = dev->index;

    NET_TRACE(("et%d: %s enter\n", devid, __FUNCTION__));

    /* Enable forwarding to internal port */
    ethHw_macEnableSet(devid, 1);

    /* enable tx and rx DMA */
    ethHw_dmaEnable(devid, DMA_RX);
    ethHw_dmaEnable(devid, DMA_TX);

    /* Check which port is connected and take PORT0 with priority */
    if (!ethHw_portLinkUp(devid)) {
        NET_ERROR(("et%d: ethernet external port is not connected\n", devid));
        return -1;
    }
    ethHw_portSpeedCheck(devid);

    NET_TRACE(("et%d: %s exit\n", devid, __FUNCTION__));
    return 0;
}


static void
bcmiproc_eth_close(struct eth_device *dev)
{
    int devid = dev->index;

    NET_TRACE(("et%d: %s enter\n", devid, __FUNCTION__));

    /* Disable DMA */
    ethHw_dmaDisable(devid, DMA_RX);
    ethHw_dmaDisable(devid, DMA_TX);

    /* Disable forwarding to internal port */
    ethHw_macEnableSet(devid, 0);

    NET_TRACE(("et%d: %s exit\n", devid, __FUNCTION__));
}

int
bcmiproc_miiphy_read(char *devname, unsigned int const addr,
   unsigned int const reg, unsigned short *const value)
{
    return ethHw_miiphy_read(addr, reg, value);
}


int
bcmiproc_miiphy_write(char *devname, unsigned int const addr,
   unsigned int const reg, unsigned short *const value)
{
    return ethHw_miiphy_write(addr, reg, value);
}


int
bcmiproc_eth_register(u8 devid)
{
    struct eth_device *dev;
    int rc;

    setup_i2c();

    NET_TRACE(("et%d: %s enter\n", devid, __FUNCTION__));

    if (devid >= CONFIG_GMAC_NUM) {
        NET_ERROR(("%s: device number error, %d.\n", __FUNCTION__, devid));
        return -1;
    }

    dev = (struct eth_device *)malloc(sizeof(struct eth_device));
    if (dev == NULL) {
        return -1;
    }
    memset(dev, 0, sizeof(*dev));
    dev->index = devid;
    sprintf(dev->name, "%s-%hu", BCMIPROC_ETH_DEV_NAME, devid);

    printf(banner);

    /* Initialization */
    NET_TRACE(("Ethernet initialization...\n"));

    rc = ethHw_Init((int)devid);
    if (rc) {;}
    NET_TRACE(("Ethernet initialization %s (rc=%i)\n",
                        (rc >= 0) ? "successful" : "failed", rc));

    dev->iobase = 0;
    dev->init = bcmiproc_eth_open;
    dev->halt = bcmiproc_eth_close;
    dev->send = bcmiproc_eth_send;
    dev->recv = bcmiproc_eth_recv;
    dev->write_hwaddr = bcmiproc_eth_write_hwaddr;

    eth_register(dev);

    NET_TRACE(("Ethernet Driver registered...\n"));

#ifdef CONFIG_CMD_MII
    miiphy_register(dev->name, bcmiproc_miiphy_read, bcmiproc_miiphy_write);
#endif

    NET_TRACE(("et%d: %s exit\n", devid, __FUNCTION__));
    return 0;
}
