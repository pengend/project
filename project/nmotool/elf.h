/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T*/
/*  All Rights Reserved  */


#ifndef _SYS_ELF_H
#define_SYS_ELF_H

#pragma ident"@(#)elf.h1.7008/05/13 SMI"

#if !defined(__APPLE__)
#include <sys/elftypes.h>
#else /* is Apple Mac OS X */

#ifdef KERNEL
#ifndef _KERNEL
#define _KERNEL /* Solaris vs. Darwin */
#endif
#endif

#include "elftypes.h" /* In lieu of Solaris <sys/elftypes.h> */
#endif /* __APPLE__ */

#ifdef__cplusplus
extern "C" {
#endif

#defineELF32_FSZ_ADDR4
#defineELF32_FSZ_HALF2
#defineELF32_FSZ_OFF4
#defineELF32_FSZ_SWORD4
#defineELF32_FSZ_WORD4

#defineELF64_FSZ_ADDR8
#defineELF64_FSZ_HALF2
#defineELF64_FSZ_OFF8
#defineELF64_FSZ_SWORD4
#defineELF64_FSZ_WORD4
#defineELF64_FSZ_SXWORD 8
#defineELF64_FSZ_XWORD8

/*
 *"Enumerations" below use ...NUM as the number of
 *values in the list.  It should be 1 greater than the
 *highest "real" value.
 */

/*
 *ELF header
 */

#defineEI_NIDENT16

	typedef struct {
		unsigned chare_ident[EI_NIDENT];/* ident bytes */
		Elf32_Halfe_type;/* file type */
		Elf32_Halfe_machine;/* target machine */
		Elf32_Worde_version;/* file version */
		Elf32_Addre_entry;/* start address */
		Elf32_Offe_phoff;/* phdr file offset */
		Elf32_Offe_shoff;/* shdr file offset */
		Elf32_Worde_flags;/* file flags */
		Elf32_Halfe_ehsize;/* sizeof ehdr */
		Elf32_Halfe_phentsize;/* sizeof phdr */
		Elf32_Halfe_phnum;/* number phdrs */
		Elf32_Halfe_shentsize;/* sizeof shdr */
		Elf32_Halfe_shnum;/* number shdrs */
		Elf32_Halfe_shstrndx;/* shdr string index */
	} Elf32_Ehdr;

#if defined(_LP64) || defined(_LONGLONG_TYPE)
	typedef struct {
		unsigned chare_ident[EI_NIDENT];/* ident bytes */
		Elf64_Halfe_type;/* file type */
		Elf64_Halfe_machine;/* target machine */
		Elf64_Worde_version;/* file version */
		Elf64_Addre_entry;/* start address */
		Elf64_Offe_phoff;/* phdr file offset */
		Elf64_Offe_shoff;/* shdr file offset */
		Elf64_Worde_flags;/* file flags */
		Elf64_Halfe_ehsize;/* sizeof ehdr */
		Elf64_Halfe_phentsize;/* sizeof phdr */
		Elf64_Halfe_phnum;/* number phdrs */
		Elf64_Halfe_shentsize;/* sizeof shdr */
		Elf64_Halfe_shnum;/* number shdrs */
		Elf64_Halfe_shstrndx;/* shdr string index */
	} Elf64_Ehdr;
#endif/* defined(_LP64) || defined(_LONGLONG_TYPE) */


#defineEI_MAG00/* e_ident[] indexes */
#defineEI_MAG11
#defineEI_MAG22
#defineEI_MAG33
#defineEI_CLASS4/* File class */
#defineEI_DATA5/* Data encoding */
#defineEI_VERSION6/* File version */
#defineEI_OSABI7/* Operating system/ABI identification */
#defineEI_ABIVERSION8/* ABI version */
#defineEI_PAD9/* Start of padding bytes */

#defineELFMAG00x7f/* EI_MAG */
#defineELFMAG1'E'
#defineELFMAG2'L'
#defineELFMAG3'F'
#defineELFMAG"\177ELF"
#defineSELFMAG4

#defineELFCLASSNONE0/* EI_CLASS */
#defineELFCLASS321
#defineELFCLASS642
#defineELFCLASSNUM3

#defineELFDATANONE0/* EI_DATA */
#defineELFDATA2LSB1
#defineELFDATA2MSB2
#defineELFDATANUM3

#defineET_NONE0/* e_type */
#defineET_REL1
#defineET_EXEC2
#defineET_DYN3
#defineET_CORE4
#defineET_NUM5
#defineET_LOOS0xfe00/* OS specific range */
#defineET_LOSUNW0xfeff
#defineET_SUNWPSEUDO0xfeff
#defineET_HISUNW0xfeff
#defineET_HIOS0xfeff
#defineET_LOPROC0xff00/* processor specific range */
#defineET_HIPROC0xffff

#defineET_LOPROC0xff00/* processor specific range */
#defineET_HIPROC0xffff

#defineEM_NONE0/* e_machine */
#defineEM_M321/* AT&T WE 32100 */
#defineEM_SPARC2/* Sun SPARC */
#defineEM_3863/* Intel 80386 */
#defineEM_68K4/* Motorola 68000 */
#defineEM_88K5/* Motorola 88000 */
#defineEM_4866/* Intel 80486 */
#defineEM_8607/* Intel i860 */
#defineEM_MIPS8/* MIPS RS3000 Big-Endian */
#defineEM_S3709/* IBM System/370 Processor */
#defineEM_MIPS_RS3_LE10/* MIPS RS3000 Little-Endian */
#defineEM_RS600011/* RS6000 */
#defineEM_UNKNOWN1212
#defineEM_UNKNOWN1313
#defineEM_UNKNOWN1414
#defineEM_PA_RISC15/* PA-RISC */
#defineEM_PARISCEM_PA_RISC/* Alias: GNU compatibility */
#defineEM_nCUBE16/* nCUBE */
#defineEM_VPP50017/* Fujitsu VPP500 */
#defineEM_SPARC32PLUS18/* Sun SPARC 32+ */
#defineEM_96019/* Intel 80960 */
#defineEM_PPC20/* PowerPC */
#defineEM_PPC6421/* 64-bit PowerPC */
#defineEM_S39022/* IBM System/390 Processor */
#defineEM_UNKNOWN22EM_S390/* Alias: Older published name */
#defineEM_UNKssor */
#defineEM_ARC45/* Argonaut RISC Core, */
	/*Argonaut Technologies Inc. */
#defineEM_SP63/* Sony DSP Processor */
#defineEM_UNKNOWN6464
#defineEM_UNKNOWN6565
#defineM_MMIX80/* Donald Knuth's educational */
	/*64-bit processor */
#defineEM_HUANY81/* Harvard University */
	/*makard HP-UX */
#defineELFOSABI_NETBSD2/* NetBSD */
#defineELFOSABI_LIN flags */
	Elf32_Wordp_align;/* memory/file alignment */
} Elf32_Phdr;

#if defined(_LP64) || defined(_LONGLONG_TYPE)
typedef struct {
	ElWIND


#definePT_LOSUNW0x6ffffffa
#32_Wordsh_link;/* misc info */
	Elf32_Wordsh_info;/* misc info */
	Elf32_Word12
#defineSHT_UNKNOWN1313
#defineSHT_INIsym0x6fffffff

#defineSHT_LOPROC0x70000000/* processor specific range */
#define access */
#define SHN_MACHO0xfffe/* Mach-o direct string access */
#endif /* __APPLE__ */
#defineSHN_XINDEX0xffff/* extended sect index *ND(info)((info) >> 4)
						  #defineELF32_ST_TYPE(info)((inSTV_SINGLETON5
						  #defineSTV_ELIMINATE6

						  #defineSTV_NUM7

/*
*Reloc32)
#defineELF64_R_TYPE(info)    ((Elf64_Word)(info))
#defineELsz;/* length of note's name */
	Elf64_Wordn_descsz;/* length ofm_stride;/* stride info */
} Elf64_Move;
#defineELF64_M_SYM(info)((info)>>8)
#defineELF64_M_SIZE(info)((unsSUNW_FPKNWN0x001/* use/non-use of fratatus_t<sys/procfs.h>*/
#defineELF64_M_INFO(sym, size)(((sym)<<8)+(unsigned char)(size))

#endif/* defined(_LP64) || defined(_LONGLONG_TYPE) */


/*
 *Hardware/Software capabilities entry
 */
#ifndef_ASM
typedef struct {
	Elf32_Wordc_tag;/* how to interpret value */
	union {
		Elf32_Wordc_val;
		Elf32_Addrc_ptr;
	} c_un;
} Elf32_Cap;

#if defined(_LP64) || defined(_LONGLONG_TYPE)
typedef struct {
	Elf64_Xwordc_tag;/* how to interpret value */
	union {
		Elf64_Xwordc_val;
		Elf64_Addrc_ptr;
	} c_un;
} Elf64_Cap;
#endif/* defined(_LP64) || defined(_LONGLONG_TYPE) */
#endif

#defineCA_SUNW_NULL0
#defineCA_SUNW_HW_11/* first hardware capabilities entry */
#defineCA_SUNW_SF_12/* first software capabilities entry */

/*
 * Define software capabilities (CA_SUNW_SF_1 values).  Note, hardware
 * capabilities (CA_SUNW_HW_1 values) are taken directly from sys/auxv_$MACH.h.
 */
#defineSF1_SUNW_FPKNWN0x001/* use/non-use of frame pointer is */
#defineSF1_SUNW_FPUSED0x002/*known, and frame pointer is */
/*in use */
#defineSF1_SUNW_MASK0x003/* known software capabilities mask */


/*
 *Known values for note entry types (e_type == ET_CORE)
 */

#defineNT_PRSTATUS1/* prstatus_t<sys/old_procfs.h>*/
#defineNT_PRFPREG2/* prfpregset_t<sys/old_procfs.h>*/
#defineNT_PRPSINFO3/* prpsinfo_t<sys/old_procfs.h>*/
#defineNT_PRXREG4/* prxregset_t<sys/procfs.h>*/
#defineNT_PLATFORM5/* string from sysinfo(SI_PLATFORM)*/
#defineNT_AUXV6/* auxv_t array<sys/auxv.h>*/
#defineNT_GWINDOWS7/* gwindows_tSPARC only*/
#defineNT_ASRS8/* asrset_tSPARC V9 only*/
#defineNT_LDT9/* ssd array<sys/sysi86.h> IA32 only */
#defineNT_PSTATUS10/* pstatus_t<sys/procfs.h>*/
#defineNT_PSINFO13/* psinfo_t<sys/procfs.h>*/
#defineNT_PRCRED14/* prcred_t<sys/procfs.h>*/
#defineNT_UTSNAME15/* struct utsname <sys/utsname.h>*/
#defineNT_LWPSTATUS16/* lwpstatus_t<sys/procfs.h>*/
#defineNT_LWPSINFO17/* lwpsinfo_t<sys/procfs.h>*/
#defineNT_PRPRIV18/* prpriv_t<sys/procfs.h>*/
#defineNT_PRPRIVINFO19/* priv_impl_info_t <sys/priv.h>*/
#defineNT_CONTENT20/* core_content_t <sys/corectl.h>*/
#defineNT_ZONENAME21/* string from getzonenamebyid(3C)*/
#defineNT_NUM21


#ifdef _KERNEL
/*
 * The following routine checks the processor-specific
 * fields of an ELF header.
 */
intelfheadcheck(unsigned char, Elf32_Half, Elf32_Word);
#endif

#ifdef__cplusplus
}
#endif

#if defined(ELF_TARGET_ALL) || defined(ELF_TARGET_SPARC)
#include <sys/elf_SPARC.h>
#endif

#if defined(ELF_TARGET_ALL) || defined(ELF_TARGET_386)

#if !defined(__APPLE__)
#include <sys/elf_386.h>
#else /* is Apple Mac OS X */
#include "elf_386.h" /* In lieu of Solaris <sys/elf_386.h> */
#endif /* __APPLE__ */
#endif

#if defined(ELF_TARGET_ALL) || defined(ELF_TARGET_AMD64)
#include <sys/elf_amd64.h>
#endif

#endif/* _SYS_ELF_H */
