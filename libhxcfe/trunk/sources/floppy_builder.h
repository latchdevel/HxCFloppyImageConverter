#define STACK_SIZE 0x80
#define NUMBEROFSECTOR_MAX 0x200

#define MAX_NUMBER_OF_INDEX 64

typedef struct _fb_track_state
{
	HXCFE_SECTCFG sectorconfig;
	int32_t track_number;
	int32_t side_number;
	int32_t interleave;
	int32_t start_sector_id;
	int32_t sectors_size;
	int32_t skew;
	int32_t side_skew;
	int32_t type;
	int32_t rpm;
	int32_t pregap;
	int32_t bitrate;
	int32_t interface_mode;

	int32_t indexlen[MAX_NUMBER_OF_INDEX];
	int32_t indexpos[MAX_NUMBER_OF_INDEX];
	int32_t sectorunderindex;

	int32_t numberofsector_min;
	int32_t numberofsector;
	HXCFE_SECTCFG sectortab[NUMBEROFSECTOR_MAX];

	int32_t sc_stack_pointer;
	HXCFE_SECTCFG sc_stack[36];
}fb_track_state;

#ifndef _HXCFE_FLPGEN_

typedef struct _HXCFE_FLPGEN
{
	HXCFE_FLOPPY * floppydisk;
	HXCFE* floppycontext;
	int32_t fb_stack_pointer;
	fb_track_state * fb_stack;
	int32_t disk_flags;
}HXCFE_FLPGEN;

#define _HXCFE_FLPGEN_
#endif
