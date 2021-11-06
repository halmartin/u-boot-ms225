#
#   Copyright (C) 2013, Broadcom Corporation. All Rights Reserved. 
#    
#   Permission to use, copy, modify, and/or distribute this software for any 
#   purpose with or without fee is hereby granted, provided that the above 
#   copyright notice and this permission notice appear in all copies. 
#    
#   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES 
#   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF 
#   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY 
#   SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES 
#   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION 
#   OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
#   CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 
#
ifdef CONFIG_NAND_IPROC_BOOT
CONFIG_SYS_TEXT_BASE = 0x1C000000
else
CONFIG_SYS_TEXT_BASE = 0x1E000000
endif

ifdef CONFIG_IPROC_SPL
CONFIG_SYS_TEXT_BASE = 0x80000000
endif

ifdef CONFIG_NO_CODE_RELOC
ifdef CONFIG_SYS_BIG_ENDIAN
LDSCRIPT := $(SRCTREE)/board/$(BOARDDIR)/u-boot-nr-be.lds
else
LDSCRIPT := $(SRCTREE)/board/$(BOARDDIR)/u-boot-nr.lds
endif
else
ifdef CONFIG_SYS_BIG_ENDIAN
LDSCRIPT := $(SRCTREE)/board/$(BOARDDIR)/u-boot-l2c-be.lds
else
LDSCRIPT := $(SRCTREE)/board/$(BOARDDIR)/u-boot-l2c.lds
endif
endif

#PLATFORM_RELFLAGS += -DSVN_REVISION=' " $(SVN_REV)"'
