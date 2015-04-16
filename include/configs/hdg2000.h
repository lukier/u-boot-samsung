/*
 * (C) Copyright 2002, 2003
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <garyj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 * Robert Lukierski <robert@lukierski.eu>
 *
 * Configuation settings for the MPL VCMA9 board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H


#define MACH_TYPE_HANTEK_HDG2000	5002

/*--------------------------------------------------------------------
 * High Level Configuration Options
 * --------------------------------------------------------------------
 */
/*#define CONFIG_SPL)*/

#define CONFIG_S3C24X0		/* This is a SAMSUNG S3C24x0-type SoC */
#define CONFIG_S3C2410		/* specifically a SAMSUNG S3C2410 SoC (well, S3C2416) */
#define CONFIG_HDG2002		/* on a Hantek HDG2000 Board  */
#define CONFIG_MACH_TYPE	MACH_TYPE_HANTEK_HDG2000 /* Machine type */

#define CONFIG_SYS_TEXT_BASE	0x32000000
#define CONFIG_SYS_GENERIC_BOARD
#define CONFIG_SYS_ARM_CACHE_WRITETHROUGH
#define CONFIG_SKIP_LOWLEVEL_INIT

/* input clock of PLL (VCMA9 has 12MHz input clock) */
#define CONFIG_SYS_CLK_FREQ	12000000

#define CONFIG_CMDLINE_TAG  /* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG

/* --------------------------------------------------------------------
 * Command line configuration.
 * (here as other things depend on it)
 * --------------------------------------------------------------------
 */
#include <config_cmd_default.h>

#define CONFIG_CMD_CACHE
/*#define CONFIG_CMD_EEPROM*/
/*#define CONFIG_CMD_I2C*/
#define CONFIG_CMD_USB
#define CONFIG_CMD_REGINFO
#define CONFIG_CMD_DATE
#define CONFIG_CMD_ELF
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PING
#define CONFIG_CMD_BSP
#define CONFIG_CMD_NAND

#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_CMDLINE_EDITING

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

/* --------------------------------------------------------------------
 * Physical Memory Map
 * --------------------------------------------------------------------
 */
#define CONFIG_NR_DRAM_BANKS        1          /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1                0x30000000 /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE           0x04000000 /* 64 MB */
#define PHYS_FLASH_1                0x00000000 /* Flash Bank #0 */
#define CONFIG_SYS_FLASH_BASE       PHYS_FLASH_1
#define CONFIG_SYS_SDRAM_BASE       PHYS_SDRAM_1
#define CONFIG_SYS_INIT_SP_ADDR     (CONFIG_SYS_SDRAM_BASE + 0x1000 - GENERATED_GBL_DATA_SIZE)

/* --------------------------------------------------------------------
 * Flash memory
 * --------------------------------------------------------------------
 */
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_FLASH_CFI_LEGACY
#define CONFIG_SYS_FLASH_LEGACY_1024Kx16
#define CONFIG_FLASH_SHOW_PROGRESS  45
#define CONFIG_SYS_MAX_FLASH_BANKS  1
#define CONFIG_SYS_FLASH_BANKS_LIST { CONFIG_SYS_FLASH_BASE }
#define CONFIG_SYS_MAX_FLASH_SECT   (35)

#define CONFIG_ENV_IS_IN_NAND       1
#define CONFIG_ENV_OFFSET           0x100000 /* 1M for u-boot.bin */
#define CONFIG_ENV_SIZE             0x80000  /* 512K for environment params */

/*
 * Size of malloc() pool
 * BZIP2 / LZO / LZMA need a lot of RAM
 */
#define CONFIG_SYS_MALLOC_LEN       (4 * 1024 * 1024)
#define CONFIG_SYS_MONITOR_LEN      (512 * 1024)
#define CONFIG_SYS_MONITOR_BASE     CONFIG_SYS_FLASH_BASE

/* --------------------------------------------------------------------
 * Hardware drivers
 * --------------------------------------------------------------------
 */
/* ETHERNET */
#define CONFIG_DRIVER_DM9000
#define CONFIG_DM9000_NO_SROM
#define CONFIG_DM9000_BASE  0x20000300
#define DM9000_IO           CONFIG_DM9000_BASE
#define DM9000_DATA         (CONFIG_DM9000_BASE+4)

/* SERIAL */
#define CONFIG_S3C24X0_SERIAL
#define CONFIG_SERIAL1		1	/* we use SERIAL 1 on VCMA9 */

/* USB  */
#define CONFIG_USB_OHCI
#define CONFIG_USB_OHCI_S3C24XX
#define CONFIG_USB_KEYBOARD
#define CONFIG_USB_STORAGE
#define CONFIG_DOS_PARTITION

/* RTC */
#define CONFIG_RTC_S3C24X0

/* NAND configuration */
#ifdef CONFIG_CMD_NAND
#define CONFIG_NAND_S3C2410
#define CONFIG_SYS_S3C2410_NAND_HWECC
#define CONFIG_SYS_MAX_NAND_DEVICE  1
#define CONFIG_SYS_NAND_BASE        0x4E000000
#define CONFIG_S3C24XX_CUSTOM_NAND_TIMING
#define CONFIG_S3C24XX_TACLS        1
#define CONFIG_S3C24XX_TWRPH0       5
#define CONFIG_S3C24XX_TWRPH1       3
#endif

/* --------------------------------------------------------------------
 * BOOTP options
 * --------------------------------------------------------------------
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME

/* --------------------------------------------------------------------
 * Miscellaneous configurable options
 * --------------------------------------------------------------------
 */
#define CONFIG_BAUDRATE         115200

#define CONFIG_BOOTDELAY            5
#define CONFIG_BOOT_RETRY_TIME      -1
#define CONFIG_RESET_TO_RETRY
#define CONFIG_ZERO_BOOTDELAY_CHECK

#define CONFIG_NETMASK              255.255.255.0
#define CONFIG_IPADDR               192.168.0.99
#define CONFIG_SERVERIP             192.168.0.1

#if defined(CONFIG_CMD_KGDB) /* speed to run kgdb serial port */
#define CONFIG_KGDB_BAUDRATE        115200
#endif

#define CONFIG_SYS_LONGHELP         /* undef to save memory */
#define CONFIG_SYS_PROMPT           "HDG2000 # "
#define CONFIG_SYS_CBSIZE           256
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE           (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)
#define CONFIG_SYS_MAXARGS          16
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE         CONFIG_SYS_CBSIZE

#define CONFIG_SYS_ALT_MEMTEST
#define CONFIG_SYS_LOAD_ADDR        0x30800000

#if 0
/* Ident */
/*#define VERSION_TAG "released"*/
#define VERSION_TAG "unstable"
#define CONFIG_IDENT_STRING "\n(c) 2003 - 2011 by MPL AG Switzerland, " "MEV-10080-001 " VERSION_TAG

#define MULTI_PURPOSE_SOCKET_ADDR	0x08000000
#endif

/* File system */
#define CONFIG_CMD_FAT
#define CONFIG_CMD_UBI
#define CONFIG_CMD_UBIFS
#define CONFIG_CMD_JFFS2
#define CONFIG_YAFFS2
#define CONFIG_RBTREE
#define CONFIG_MTD_DEVICE               /* needed for mtdparts commands */
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_LZO

/* support additional compression methods */
#define CONFIG_BZIP2
#define CONFIG_LZO
#define CONFIG_LZMA

#define CONFIG_BOARD_EARLY_INIT_F

#endif /* __CONFIG_H */
