# Floppy image file converter
Limited fork from "**HxC Floppy Emulator Project**" generic/universal floppy disk drive emulator.

Copyright (C) 2006-2021  Jean-François DEL NERO https://hxc2001.com


## License
GNU General Public License version 2.0 (GPLv2)


## Includes
* **libhxcadaptor**
System calls helper/wrapper library, for Windows, Linux and macOS.

* **libhxcfe**
The main HxC Floppy Emulator library, for Windows, Linux and macOS.

* **libusbhxcfe**
USB HxC Floppy Emulator driver/library, for Windows, Linux, macOS.

* **HxCFloppyEmulator_cmdline**
HxC Floppy Emulator command line software, for Windows, Linux, macOS.


## Changes
* Add static libraries build to default targets:
  * libhxcfe.a
  * libusbhxcfe.a
* Add static executable target "hxcfe.static"
* Fix macOS "libusbhxcfe.dylib" build bug
* Fix two functions with the same name "adjustrand()"


## Usage
```
$ hxcfe -help
HxC Floppy Emulator : Floppy image file converter v2.5.5.1
Copyright (C) 2006-2021 Jean-Francois DEL NERO
This program comes with ABSOLUTELY NO WARRANTY
This is free software, and you are welcome to redistribute it
under certain conditions;

libhxcfe version : 2.13.7.1

Options:
  -help                     : This help
  -license                  : Print the license
  -verbose                  : Verbose mode
  -script:[filename]        : Script file to execute
  -modulelist               : List modules in the libhxcfe [FORMAT]
  -rawlist                  : Disk layout list [DISKLAYOUT]
  -interfacelist		        : Floppy interfaces mode list [INTERFACE_MODE]
  -finput:[filename]        : Input file image
  -foutput:[filename]       : Output file image
  -conv:[FORMAT]            : Convert the input file
  -reffile:[filename]       : Sector to sector copy mode. To be used with -conv : specify the format reference image
  -uselayout:[DISKLAYOUT]   : Use the Layout [DISKLAYOUT]
  -usb:[DRIVE]              : start the usb floppy emulator
  -infos                    : Print informations about the input file
  -ifmode:[INTERFACE_MODE]  : Select the floppy interface mode
  -singlestep               : Force the single step mode
  -doublestep               : Force the double step mode
  -list                     : List the content of the floppy image
  -getfile:[FILE]           : Get a file from the floppy image
  -putfile:[FILE]           : Put a file to the floppy image

Stopping HxCFloppyEmulator...
```


## Example
Convert from .HFE to .DSK

`$ hxcfe -finput:disk_image.hfe  -conv:AMSTRADCPC_DSK  -foutput:disk_image.dsk`

Convert from .DSK to .HFE

`$ hxcfe -finput:disk_image.dsk  -conv:HXC_HFE         -foutput:disk_image.hfe `



## Raw Disk Layouts (69)
```
---------------------------------------------------------------------------
-                     libhxcfe Raw Disk Layout list                       -
---------------------------------------------------------------------------
Layout ID                          DESCRIPTION

ABB_320KB                       :  ABB/Asea 3"5 DD Floppy Disk (ABB IRB2000 S3 - Single sided)
ABB_328KB                       :  ABB/Asea 3"5 328KB DD Floppy Disk (ABB IRB)
ABB_640KB                       :  ABB/Asea 3"5 DD Floppy Disk
ACORN_ADFS_160K                 :  Acorn ADFS 160K Floppy Disk
ACORN_ADFM_320K                 :  Acorn ADFM 320K Floppy Disk
ACORN_ADFL_640K                 :  Acorn ADFL 640K Floppy Disk
AED 6200P Disk Layout           :  AED 6200P Floppy Disk Storage System Disk Layout
AKAIS950_HD_1600KB              :  Akai S950 3"5 HD Floppy Disk
AKAIS950_DD_800KB               :  Akai S900/S950 3"5 DD Floppy Disk
AKAIS3000_HD                    :  Akai S3000 3"5 HD Floppy Disk
AMSTRADCPC_DD                   :  Standard 3" Amstrad CPC Floppy Disk
AUTOMATIX_RAIL_DD_400KB         :  Automatix RAIL DD 400KB Floppy Disk
ATARIST_DD_720KB                :  Atari ST 3"5 DD Floppy Disk
BUNG_MGD2                       :  Bung Multi Game Doctor 2 / MGD2 1756KB
CASIOFZ1_HD_1M25                :  Casio FZ1 3"5 HD Floppy Disk
ROBOX_RC9400                    :  Coat-A-Matic 9400 / Robox RC9400
COMX35_SS_70KB                  :  COMX35 SS 70KB Floppy Disk
COMX35_DS_140KB                 :  COMX35 DS 140KB Floppy Disk
COMX35_SS_140KB                 :  COMX35 SS 140KB Floppy Disk
DEC_RX55                        :  Dec RX55 Floppy Disk
Didaktik_Spectrum_DD_720KB      :  Didaktik Spectrum DD Floppy Disk
DOS_DD_720KB                    :  Standard 3"5 DOS DD Floppy Disk
DOS_HD_1M44                     :  Standard 3"5 DOS HD Floppy Disk
DOS_ED_2M88                     :  Standard 3"5 DOS ED Floppy Disk
DOS_EXDD_2M5                    :  Special 2.5MB DOS EXHD Floppy Disk
DOS_EXHD_4M5                    :  Special 4.5MB DOS EXHD Floppy Disk
DOS_EXHD_6M78                   :  Special 6.78MB DOS EXHD Floppy Disk
DYNACORD_ADD_ONE                :  Dynacord Add-One Floppy Disk
DYNACORD_HD                     :  Dynacord HD 1.6MB Floppy Disk
ENSONIQ_DD_800KB                :  Ensoniq EPS 3"5 DD Floppy Disk
ENSONIQ_HD_1600KB               :  Ensoniq EPS 3"5 HD Floppy Disk
ENSONIQ_MIRAGE_440KB            :  Ensoniq Mirage 3"5 DD Floppy Disk
EXCELLON_CNC6                   :  Excellon CNC6 Floppy Disk
EMAX_DD_800KB                   :  Emax 3"5 DD Floppy Disk
EMAX_II_DD_800KB                :  Emax II 3"5 DD Floppy Disk
FLEX_SSDD_80T_358KB             :  FLEX SSDD 80 Tracks 358KB
FLEX_DSDD_80T_716KB             :  FLEX DSDD 80 Tracks 716KB
FLEX_DSDD_80T_716KB_PADDED      :  FLEX DSDD 80 Tracks 716KB  (cylinder 0 padded image)
FLEX_DSDD_40T_356KB             :  FLEX DSDD 40 Tracks 356KB
FLEX_DSDD_40T_356KB_PADDED      :  FLEX DSDD 40 Tracks 356KB (cylinder 0 padded image)
GENERALMUSIC_GEM_S3_1600KB      :  GeneralMusic Gem S3 HD Floppy Disk
GENERALMUSIC_GEM_WX_EXPANDER    :  GeneralMusic Gem WX Expander HD Floppy Disk
GRAVOGRAPH_ISIS_640KB           :  Gravograph ISIS 3"5 DD Floppy Disk
KORGDSS1_DD_800KB               :  KORG DSS1 3"5 DD Floppy Disk
KORGT3_HD_1M6                   :  KORG T3 3"5 HD Floppy Disk
LIF_3_50_264KB                  :  Logical Interchange Format (LIF) 3"1/2 264KB (single side)
LIF_3_50_616KB                  :  Logical Interchange Format (LIF) 3"1/2 616KB (double side)
LIF_3_5O_1232KB                 :  Logical Interchange Format (LIF) 3"1/2 1232KB (HD)
LIF_5_25_264KB                  :  Logical Interchange Format (LIF) 5"1/4 264KB
LINNFORAT9K_720KB               :  Linn/Forat 9000 Floppy Disk
MEMOTECH_80T                    :  Memotech Floppy Disk (80 tracks)
MEMOTECH_40T                    :  Memotech Floppy Disk (40 tracks)
Microtan 65 TANDOS Floppy Disk  :  Microtan 65 TANDOS Floppy Disk
BALZERS_250KB                   :  Oerlikon Balzers 250KB SD Disks
OPUS_DISCOVERY                  :  Spectrum Opus Discovery
OS9_640KB                       :  OS9 640KB Floppy Disk
OS9_1280KB                      :  OS9 1280KB Floppy Disk
ORIC_JASMIN_357KB               :  Oric Jasmin 357K Floppy Disk
PUMA_ROBOT_DD_640KB             :  PUMA Robot arm 560C DD 640KB Floppy Disk
QD_TRIUMPH_ADLER                :  Olivetti TOP 100 / Triumph-Adler typewriter Quickdisk raw image
ROLAND_DD_W30_S330_W50_S50_S550 :  Roland W30/S330/JW-50/W50/S50/S550 DD Floppy Disk
SORD_M68_HD_998KB               :  SORD M68 HD 998KB Floppy Disk
TATUNG_EINSTEIN_DD_200KB        :  Tatung Einstein DD 200KB Floppy Disk
TATUNG_EINSTEIN_DD_400KB        :  Tatung Einstein DD 400KB Floppy Disk
TIMEX_FDD3000_80T2S             :  Timex FDD3000 Floppy Disk (80 Tracks, 2 Sides)
TIMEX_FDD3000_40T1S             :  Timex FDD3000 Floppy Disk (40 Tracks, 1 Side)
TRS80_JV1                       :  Standard 3" Amstrad CPC Floppy Disk
UKNC MFM 800KB Disk Layout      :  UKNC MFM 800KB Disk Layout
Unitel Videotex Floppy Disk     :  Unitel Videotex Floppy Disk
```


## Convert format plugins (82)
```
---------------------------
-   Convert plugin list   -
---------------------------
Plugin ID                 

ACORN_ADF
AMIGA_ADF
AMIGA_ADZ
AMIGA_DMS
AMIGA_EXTADF
AMIGA_FS
AMIGA_OLDEXTADF
AMSTRADCPC_DSK
APRIDISK
ARBURG
ATARIST_DIM
ATARIST_MSA
ATARIST_ST
ATARIST_STT
ATARIST_STW
ATARIST_STX
AUTOSELECT
BBC_ADL
BBC_SSD_DSD
BMP_DISK_IMAGE
BMP_IMAGE
C64_D64
C64_D81
CAMPUTERSLYNX
CASIO_FZF
COPYQM
DRAGON3264_VDK
EMAX_EM
EMULATORI
EMULATORII
EMULATORII_EMUII
ENSONIQ_EDE
ENSONIQ_EDM
ENSONIQ_GKH
FAT12FLOPPY
FEI
GENERIC_XML
HEATHKIT
HXCMFM_IMG
HXCSTREAM
HXC_AFI
HXC_EXTHFE
HXC_HDDD_A2_HFE
HXC_HFE
HXC_HFEV3
HXC_QD
HXC_STREAMHFE
IMD_IMG
KRYOFLUXSTREAM
KURZWEIL_KRZ
MSX_DSK
NEC_D88
NORTHSTAR
OBERHEIM_DPX
ORIC_DSK
PROPHET2000
RAW_IMG
RAW_IMZ
RAW_LOADER
ROLAND_W30
SAMCOUPE_MGT
SAMCOUPE_SAD
SCP_FLUX_STREAM
SNES_SMC
SPECCYDOS_SDD
SPS_IPF
SVD
TELEDISK_TD0
THOMSONTO8D_SAP
THOMSON_FD
TI994A_PC99
TI994A_V9T9
TRS80_DMK
TRS80_JV1
TRS80_JV3
TRS80_JVC
VEGAS6809
VTR_IMG
X68000_HDM
ZXSPECTRUM_FDI
ZXSPECTRUM_SCL
ZXSPECTRUM_TRD
```


## File types support (160)

```
-------------------------------------------------------------------------------------------------------------------------------------
-                                            Supported file type list                                                               -
-------------------------------------------------------------------------------------------------------------------------------------
Type ID                            Read/Write    DESCRIPTION                                                            Extension

A2R_FLUX_STREAM                        R         A2R  Stream Loader                                                     *.a2r
ABB_320KB                              RW        ABB/Asea 3"5 DD Floppy Disk (ABB IRB2000 S3 - Single sided)            *.xml
ABB_328KB                              RW        ABB/Asea 3"5 328KB DD Floppy Disk (ABB IRB)                            *.xml
ABB_640KB                              RW        ABB/Asea 3"5 DD Floppy Disk                                            *.xml
ACORN_ADF                              R         ACORN ADF Loader                                                       *.adf
ACORN_ADFL_640K                        RW        Acorn ADFL 640K Floppy Disk                                            *.xml
ACORN_ADFM_320K                        RW        Acorn ADFM 320K Floppy Disk                                            *.xml
ACORN_ADFS_160K                        RW        Acorn ADFS 160K Floppy Disk                                            *.xml
AED 6200P Disk Layout                  RW        AED 6200P Floppy Disk Storage System Disk Layout                       *.xml
AKAIS3000_HD                           RW        Akai S3000 3"5 HD Floppy Disk                                          *.xml
AKAIS950_DD_800KB                      RW        Akai S900/S950 3"5 DD Floppy Disk                                      *.xml
AKAIS950_HD_1600KB                     RW        Akai S950 3"5 HD Floppy Disk                                           *.xml
AMIGA_ADF                              RW        AMIGA ADF Loader                                                       *.adf
AMIGA_ADZ                              RW        AMIGA ADZ Loader                                                       *.adz
AMIGA_DMS                              R         AMIGA DMS Loader                                                       *.dms
AMIGA_EXTADF                           R         AMIGA EXTENDED ADF Loader                                              *.adf
AMIGA_FS                               R         AMIGA FS Loader                                                        *.amigados
AMIGA_OLDEXTADF                        R         AMIGA OLD EXTENDED ADF Loader                                          *.adf
AMSTRADCPC_DD                          RW        Standard 3" Amstrad CPC Floppy Disk                                    *.xml
AMSTRADCPC_DSK                         RW        Amstrad CPC DSK Loader                                                 *.dsk
ANA_IMG                                R         AnaDisk file Loader                                                    *.ana
APPLE2_DO                              R         Apple II DO Loader                                                     *.do
APPLE2_NIB                             R         Apple II NIB Loader                                                    *.nib
APRIDISK                               R         APRIDISK Loader                                                        *.dsk
ARBURG                                 RW        ARBURG RAW Loader                                                      *.arburgfd
ATARIST_DD_720KB                       RW        Atari ST 3"5 DD Floppy Disk                                            *.xml
ATARIST_DIM                            RW        ATARI ST DIM Loader                                                    *.dim
ATARIST_MSA                            RW        ATARI ST MSA Loader                                                    *.msa
ATARIST_ST                             RW        ATARI ST ST Loader                                                     *.st
ATARIST_STT                            R         ATARI ST STT Loader                                                    *.stt
ATARIST_STW                            RW        STW Loader                                                             *.stw
ATARIST_STX                            RW        Atari ST STX/Pasti Loader                                              *.stx
ATARI_ATR                              R         Atari ATR Loader                                                       *.atr
AUTOMATIX_RAIL_DD_400KB                RW        Automatix RAIL DD 400KB Floppy Disk                                    *.xml
BALZERS_250KB                          RW        Oerlikon Balzers 250KB SD Disks                                        *.xml
BBC_ADL                                R         BBC ADL floppy image loader                                            *.adl
BBC_SSD_DSD                            R         BBC SSD & DSD floppy image loader                                      *.dsd
BMP_DISK_IMAGE                         W         BMP floppy layout (disk) image generator                               *.bmp
BMP_IMAGE                              W         BMP floppy tracks layout image generator                               *.bmp
BUNG_MGD2                              RW        Bung Multi Game Doctor 2 / MGD2 1756KB                                 *.xml
C64_D64                                R         C64 D64 file image loader                                              *.d64
C64_D81                                R         C64 D81 Loader                                                         *.d81
CAMPUTERSLYNX                          R         CAMPUTERSLYNX Loader                                                   *.ldf
CASIOFZ1_HD_1M25                       RW        Casio FZ1 3"5 HD Floppy Disk                                           *.xml
CASIO_FZF                              R         Casio FZF file Loader                                                  *.fzf
COMX35_DS_140KB                        RW        COMX35 DS 140KB Floppy Disk                                            *.xml
COMX35_SS_140KB                        RW        COMX35 SS 140KB Floppy Disk                                            *.xml
COMX35_SS_70KB                         RW        COMX35 SS 70KB Floppy Disk                                             *.xml
COPYQM                                 R         COPYQM IMG Loader                                                      *.dsk
DEC_RX55                               RW        Dec RX55 Floppy Disk                                                   *.xml
DFI_FLUX_STREAM                        R         DiscFerret DFI Stream Loader                                           *.dfi
DOS_DD_720KB                           RW        Standard 3"5 DOS DD Floppy Disk                                        *.xml
DOS_ED_2M88                            RW        Standard 3"5 DOS ED Floppy Disk                                        *.xml
DOS_EXDD_2M5                           RW        Special 2.5MB DOS EXHD Floppy Disk                                     *.xml
DOS_EXHD_4M5                           RW        Special 4.5MB DOS EXHD Floppy Disk                                     *.xml
DOS_EXHD_6M78                          RW        Special 6.78MB DOS EXHD Floppy Disk                                    *.xml
DOS_HD_1M44                            RW        Standard 3"5 DOS HD Floppy Disk                                        *.xml
DRAGON3264_VDK                         RW        DRAGON32 & 64 VDK Loader                                               *.vdk
DYNACORD_ADD_ONE                       RW        Dynacord Add-One Floppy Disk                                           *.xml
DYNACORD_HD                            RW        Dynacord HD 1.6MB Floppy Disk                                          *.xml
Didaktik_Spectrum_DD_720KB             RW        Didaktik Spectrum DD Floppy Disk                                       *.xml
EMAX_DD_800KB                          RW        Emax 3"5 DD Floppy Disk                                                *.xml
EMAX_EM                                R         EMAX EM1 & EM2 Loader                                                  *.em1
EMAX_II_DD_800KB                       RW        Emax II 3"5 DD Floppy Disk                                             *.xml
EMULATORI                              R         E-mu Emulator I dsk Loader                                             *.emufd
EMULATORII                             R         E-mu Emulator II / SP1200 dsk Loader                                   *.emuiifd
EMULATORII_EMUII                       R         E-mu Emulator II *.eii Loader                                          *.eii
ENSONIQ_DD_800KB                       RW        Ensoniq EPS 3"5 DD Floppy Disk                                         *.xml
ENSONIQ_EDE                            R         ENSONIQ EDE Loader                                                     *.ede
ENSONIQ_EDM                            R         Ensoniq mirage EDM Loader                                              *.edm
ENSONIQ_GKH                            R         ENSONIQ GKH Loader                                                     *.gkh
ENSONIQ_HD_1600KB                      RW        Ensoniq EPS 3"5 HD Floppy Disk                                         *.xml
ENSONIQ_MIRAGE_440KB                   RW        Ensoniq Mirage 3"5 DD Floppy Disk                                      *.xml
EXCELLON_CNC6                          RW        Excellon CNC6 Floppy Disk                                              *.xml
FAT12FLOPPY                            R         FAT12/MS DOS Loader                                                    *.fat
FAT12FLOPPY                            R         FAT12/MS DOS Loader                                                    *.fat
FEI                                    R         FEI Loader                                                             *.fei
FLEX_DSDD_40T_356KB                    RW        FLEX DSDD 40 Tracks 356KB                                              *.xml
FLEX_DSDD_40T_356KB_PADDED             RW        FLEX DSDD 40 Tracks 356KB (cylinder 0 padded image)                    *.xml
FLEX_DSDD_80T_716KB                    RW        FLEX DSDD 80 Tracks 716KB                                              *.xml
FLEX_DSDD_80T_716KB_PADDED             RW        FLEX DSDD 80 Tracks 716KB  (cylinder 0 padded image)                   *.xml
FLEX_SSDD_80T_358KB                    RW        FLEX SSDD 80 Tracks 358KB                                              *.xml
FLP_IMG                                R         FLP PC Magazine image Loader                                           *.flp
GENERALMUSIC_GEM_S3_1600KB             RW        GeneralMusic Gem S3 HD Floppy Disk                                     *.xml
GENERALMUSIC_GEM_WX_EXPANDER           RW        GeneralMusic Gem WX Expander HD Floppy Disk                            *.xml
GENERIC_XML                            RW        Generic XML file Loader                                                *.xml
GRAVOGRAPH_ISIS_640KB                  RW        Gravograph ISIS 3"5 DD Floppy Disk                                     *.xml
HEATHKIT                               RW        Heathkit Loader                                                        *.h8d
HXCMFM_IMG                             RW        HXC MFM IMG Loader                                                     *.mfm
HXCSTREAM                              R         HxC Stream Loader                                                      *.hxcstream
HXC_AFI                                RW        HxC AFI file loader                                                    *.afi
HXC_EXTHFE                             W         SD Card HxCFE EXTENDED HFE file Loader                                 *.hfe
HXC_HDDD_A2_HFE                        W         SD Card HxCFE HFE file Loader (HDDD A2 Support)                        *.hfe
HXC_HFE                                RW        SD Card HxCFE HFE file Loader                                          *.hfe
HXC_HFEV3                              RW        SD Card HxCFE HFE V3 file Loader                                       *.hfe
HXC_QD                                 RW        HXC Quickdisk image Loader                                             *.qd
HXC_STREAMHFE                          RW        Stream HFE file Loader                                                 *.hfe
IMD_IMG                                RW        ImageDisk IMD file Loader                                              *.imd
KORGDSS1_DD_800KB                      RW        KORG DSS1 3"5 DD Floppy Disk                                           *.xml
KORGT3_HD_1M6                          RW        KORG T3 3"5 HD Floppy Disk                                             *.xml
KRYOFLUXSTREAM                         RW        KryoFlux Stream Loader                                                 *.raw
LIF_3_50_264KB                         RW        Logical Interchange Format (LIF) 3"1/2 264KB (single side)             *.xml
LIF_3_50_616KB                         RW        Logical Interchange Format (LIF) 3"1/2 616KB (double side)             *.xml
LIF_3_5O_1232KB                        RW        Logical Interchange Format (LIF) 3"1/2 1232KB (HD)                     *.xml
LIF_5_25_264KB                         RW        Logical Interchange Format (LIF) 5"1/4 264KB                           *.xml
LINNFORAT9K_720KB                      RW        Linn/Forat 9000 Floppy Disk                                            *.xml
MEMOTECH_40T                           RW        Memotech Floppy Disk (40 tracks)                                       *.xml
MEMOTECH_80T                           RW        Memotech Floppy Disk (80 tracks)                                       *.xml
MSX_DSK                                R         MSX DSK Loader                                                         *.dsk
Microtan 65 TANDOS Floppy Disk         RW        Microtan 65 TANDOS Floppy Disk                                         *.xml
NEC_D88                                RW        NEC D88 Loader                                                         *.d88
NEC_FDI                                R         NEC FDI Loader                                                         *.fdi
NORTHSTAR                              RW        Northstar Loader                                                       *.nsi
OBERHEIM_DPX                           R         Oberheim DPX Loader                                                    *.dpx
OPUS_DISCOVERY                         RW        Spectrum Opus Discovery                                                *.xml
ORIC_DSK                               RW        ORIC DSK Loader                                                        *.dsk
ORIC_JASMIN_357KB                      RW        Oric Jasmin 357K Floppy Disk                                           *.xml
OS9_1280KB                             RW        OS9 1280KB Floppy Disk                                                 *.xml
OS9_640KB                              RW        OS9 640KB Floppy Disk                                                  *.xml
PROPHET2000                            R         PROPHET 2000 Loader                                                    *.img
PUMA_ROBOT_DD_640KB                    RW        PUMA Robot arm 560C DD 640KB Floppy Disk                               *.xml
QD_TRIUMPH_ADLER                       RW        Olivetti TOP 100 / Triumph-Adler typewriter Quickdisk raw image        *.xml
RAW_IMG                                R         IBM PC IMG Loader                                                      *.img
RAW_IMZ                                R         IBM PC IMZ Loader                                                      *.imz
RAW_LOADER                             RW        RAW Sector loader                                                      *.img
ROBOX_RC9400                           RW        Coat-A-Matic 9400 / Robox RC9400                                       *.xml
ROLAND_DD_W30_S330_W50_S50_S550        RW        Roland W30/S330/JW-50/W50/S50/S550 DD Floppy Disk                      *.xml
ROLAND_W30                             R         Roland W30 file Loader                                                 *.w30
SAMCOUPE_MGT                           R         SAM COUPE MGT Loader                                                   *.mgt
SAMCOUPE_SAD                           R         SAM COUPE SAD Loader                                                   *.sad
SCP_FLUX_STREAM                        RW        SCP Stream Loader                                                      *.scp
SDU_IMG                                R         SAB Diskette Utility Loader                                            *.sdu
SNES_SMC                               R         Super famicom SMC / Game Doctor Loader                                 *.smc
SORD_M68_HD_998KB                      RW        SORD M68 HD 998KB Floppy Disk                                          *.xml
SPECCYDOS_SDD                          RW        Speccy DOS SDD File Loader                                             *.sdd
SPS_IPF                                RW        SPS IPF Loader                                                         *.ipf
SVD                                    R         SVD Loader                                                             *.svd
SYSTEM_24                              R         System 24 loader                                                       *.s24
TATUNG_EINSTEIN_DD_200KB               RW        Tatung Einstein DD 200KB Floppy Disk                                   *.xml
TATUNG_EINSTEIN_DD_400KB               RW        Tatung Einstein DD 400KB Floppy Disk                                   *.xml
TELEDISK_TD0                           R         TELEDISK TD0 Loader                                                    *.td0
THOMSONTO8D_SAP                        R         THOMSON TO8D SAP Loader                                                *.sap
THOMSON_FD                             RW        THOMSON FD Loader                                                      *.fd
TI994A_PC99                            R         TI99 4A PC99 Loader                                                    *.pc99
TI994A_V9T9                            RW        TI99 4A V9T9 Loader                                                    *.v9t9
TIMEX_FDD3000_40T1S                    RW        Timex FDD3000 Floppy Disk (40 Tracks, 1 Side)                          *.xml
TIMEX_FDD3000_80T2S                    RW        Timex FDD3000 Floppy Disk (80 Tracks, 2 Sides)                         *.xml
TRS80_DMK                              RW        TRS80 DMK Loader                                                       *.dmk
TRS80_JV1                              R         TRS80 JV1 Loader                                                       *.jv1
TRS80_JV1                              RW        Standard 3" Amstrad CPC Floppy Disk                                    *.xml
TRS80_JV3                              RW        TRS80 JV3 Loader                                                       *.jv3
TRS80_JVC                              R         TRS80 JVC Loader                                                       *.jvc
UKNC MFM 800KB Disk Layout             RW        UKNC MFM 800KB Disk Layout                                             *.xml
Unitel Videotex Floppy Disk            RW        Unitel Videotex Floppy Disk                                            *.xml
VEGAS6809                              R         VEGAS6809 image Loader                                                 *.veg
VTR_IMG                                RW        VTR IMG Loader                                                         *.vtr
X68000_HDM                             R         X68000 HDM file Loader                                                 *.hdm
ZXSPECTRUM_FDI                         R         ZX SPECTRUM FDI Loader                                                 *.fdi
ZXSPECTRUM_SCL                         R         ZX SPECTRUM SCL Loader                                                 *.scl
ZXSPECTRUM_TRD                         RW        Zx Spectrum TRD Loader                                                 *.trd
```


## Interface modes (17)
```
---------------------------------------------------------------------------
-                        Interface mode list                              -
---------------------------------------------------------------------------
Interface ID                  (code)   DESCRIPTION

IBMPC_DD_FLOPPYMODE           (0x00) : PC Interface (720KB/DD Disk)
IBMPC_HD_FLOPPYMODE           (0x01) : PC Interface (1.44MB/HD Disk)
ATARIST_DD_FLOPPYMODE         (0x02) : Atari Interface (720KB/DD Disk)
ATARIST_HD_FLOPPYMODE         (0x03) : Atari Interface (1.44MB/HD Disk)
AMIGA_DD_FLOPPYMODE           (0x04) : Amiga Interface (880KB/DD)
AMIGA_HD_FLOPPYMODE           (0x05) : Amiga Interface (1.76MB/HD)
CPC_DD_FLOPPYMODE             (0x06) : Amstrad CPC Interface
GENERIC_SHUGART_DD_FLOPPYMODE (0x07) : Shugart Interface
IBMPC_ED_FLOPPYMODE           (0x08) : PC Interface (2.88MB/ED Disk)
MSX2_DD_FLOPPYMODE            (0x09) : MSX Interface
C64_DD_FLOPPYMODE             (0x0A) : C64 Interface
EMU_SHUGART_FLOPPYMODE        (0x0B) : E-mu Interface
S950_DD_FLOPPYMODE            (0x0C) : Akai S900/S950 Interface (800KB/DD Disk)
S950_HD_FLOPPYMODE            (0x0D) : Akai S950 Interface (1.6MB/HD Disk)
S950_DD_HD_FLOPPYMODE         (0x0E) : Akai S950 Interface (Automatic density selection)
IBMPC_DD_HD_FLOPPYMODE        (0x0F) : PC Interface (Automatic density selection)
QUICKDISK_FLOPPYMODE          (0x10) : Quickdisk Interface
```
