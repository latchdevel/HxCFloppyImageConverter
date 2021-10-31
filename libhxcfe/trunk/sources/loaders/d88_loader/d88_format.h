/*
D88 (D68/D77/D98) File Structure
================================

Multiple disk image:
====================
Simple concatenation of multiple individual disks.


Disk structure:
===============
Header
Track 0
Track 1
Track 2
Track 3
...


Size: 688 or 672 bytes.

Offset    Size             Meaning
------------------------------------------------------------------------------------

00h       16(CHAR)             Name/Comment.
0Ah       10                   Reserved (00h).
1Ah       1                    Write protect flag. 00h = normal. 10h = write protected.
1Bh       1                    Media flag. 00h = 2D, 10h = 2DD, 20h = 2HD.
1Ch       4(DWORD)             Disk size (including header size).
20h       4(DOWRD) * 164       Track table. Offset of each track from disk start.
                               0 if track is not recorded in image.
                               *Alternative header format only has 160 track table entries.

-> End of disk image if disk is unformatted (header only).


Data:
=====
Offset: 2A0h or 2B0h.
Size: variable.
Concatenation of all tracks in disk (see track table for offsets).


Track:
======
Size: variable.
Concatenation of all sectors in track in their original order (possible
interleaving).


Sector:
=======
Size: variable.
Sector header + sector data.

Offset    Size          Meaning
------------------------------------------------------------------------------------------

00h       1                 C (cylinder/track value of sector's id).
01h       1                 H (head value of sector's id).
02h       1                 R (record/number value of sector's id).
03h       1                 N (sector length in IBM format. Bytes in sector = 128 * (1 << N)).
04h       2(WORD)           Number of sectors in track.
06h       1                 Density. 00h double density. 40h = single density.
07h       1                 Deleted data (DDAM). 0 = normal, 1 = deleted.
08h       1                 Status (error code returned by disk bios). 00h = normal.
09h       5                 Reserved (00h).
0Eh       2(WORD)    Sector length in bytes. (-> end sector header)
01h       (variable)    Sector data. See sector length field for size.


STATUS is the returned code by the bios of the PC-98x1 :
========================================================

0x00 Normal
0x10 Normal (Deleted)
0xA0 ID CRC Error
0xB0 DATA CRC Error
0xE0 No ADDRESS Mark
0xF0 No DATA Mark

Note: sector size and data size are coded using 2 bytes with little endian.
*/

#pragma pack(1)

typedef struct d88_fileheader_
{
	uint8_t name[16];
	uint8_t reserved[10];
	uint8_t write_protect;
	uint8_t media_flag;
	uint32_t file_size;
}d88_fileheader;

typedef struct d88_sector_
{
	uint8_t  cylinder;
	uint8_t  head;
	uint8_t  sector_id;
	uint8_t  sector_size;
	uint16_t number_of_sectors;
	uint8_t  density;
	uint8_t  deleted_data;
	uint8_t  sector_status;
	uint8_t  reserved[5];
	uint16_t sector_length;
}d88_sector;

#pragma pack()
