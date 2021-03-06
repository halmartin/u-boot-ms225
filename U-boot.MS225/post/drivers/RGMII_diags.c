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
#include <post.h>
#include <net.h>


#if CONFIG_POST & CONFIG_SYS_POST_RGMII
DECLARE_GLOBAL_DATA_PTR;

extern  IPaddr_t    NetPingIP;

static char localIPName[16]="ipaddr";
static char serverIPName[16]="serverip";

#define XMK_STR(x)	#x
#define MK_STR(x)	XMK_STR(x)

static  const char serverIP[] = {MK_STR(CONFIG_SERVERIP)};

extern int NetRxPacketLen;

int rgmii_post_test (int flags)
{
    int status=0;
	char *local_ip, *server_ip;

    post_log("\nRGMII diags starts!");

	/* get port5 config */
    local_ip = getenv(localIPName);
	if (local_ip == NULL)
	{
		post_log("\nLocal board ip address not defined");
		post_log("\nAdd ipaddr in the env\n");
		return -1;
	}
	server_ip = getenv(serverIPName);
	if (server_ip == NULL)
	{
		post_log("\nserver ip address not defined");
		post_log("\nadd serverip in the env\n");
		return -1;
	}

    if ( (flags & POST_AUTO) !=  POST_AUTO )
    {
        post_log("\nmake sure the host pc connected is configured to IP: %s",server_ip );
        post_getConfirmation("\nReady? (Y/N)");
        post_log("\nStrap pins are set to A1:FC  A2:00  A3:07  A4:0f  A5:28  A6:f6  A7:fff");
        post_getConfirmation("\nReady? (Y/N)");
    }
    else
    {
        post_set_strappins("A2 0%A3 7%A4 f%A5 38%A6 f6%");
    }	

    	NetPingIP = string_to_ip(server_ip);
    
	    if (NetLoop(PING) < 0)
	    {
	        post_log("Testfailed; host %s is not alive.\n", server_ip);
	        status = -1;
	    } else  {
	        post_log("host %s is alive, test passed \n", server_ip);
	    }
    
    return status;
}
#endif /* CONFIG_POST & CONFIG_SYS_POST_RGMII */
