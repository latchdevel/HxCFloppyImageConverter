/*
THE COMPUTER CODE CONTAINED HEREIN IS THE SOLE PROPERTY OF PARALLAX
SOFTWARE CORPORATION ("PARALLAX").  PARALLAX, IN DISTRIBUTING THE CODE TO
END-USERS, AND SUBJECT TO ALL OF THE TERMS AND CONDITIONS HEREIN, GRANTS A
ROYALTY-FREE, PERPETUAL LICENSE TO SUCH END-USERS FOR USE BY SUCH END-USERS
IN USING, DISPLAYING,  AND CREATING DERIVATIVE WORKS THEREOF, SO LONG AS
SUCH USE, DISPLAY OR CREATION IS FOR NON-COMMERCIAL, ROYALTY OR REVENUE
FREE PURPOSES.  IN NO EVENT SHALL THE END-USER USE THE COMPUTER CODE
CONTAINED HEREIN FOR REVENUE-BEARING PURPOSES.  THE END-USER UNDERSTANDS
AND AGREES TO THE TERMS HEREIN AND ACCEPTS THE SAME BY USE OF THIS FILE.
COPYRIGHT 1993-1998 PARALLAX SOFTWARE CORPORATION.  ALL RIGHTS RESERVED.
*/
/*
 * $Source: f:/miner/source/pslib/rcs/lzw.c $
 * $Revision: 1.8 $
 * $Author: john $
 * $Date: 1994/02/01 13:23:51 $
 *
 * Based on lzw15v.c from Data Compression book.
 * CompressFile and Expandfile have been replaced by cfread and cfwrite.
 *
 * $Log: lzw.c $
 * Revision 1.8  1994/02/01  13:23:51  john
 * *** empty log message ***
 *
 * Revision 1.7  1993/10/22  17:50:43  yuan
 * Fixed the hard to track down bug
 *
 * Revision 1.6  1993/10/18  18:00:13  yuan
 * Fixed memory alloc errors.
 *
 * Revision 1.5  1993/09/21  17:22:24  yuan
 * *** empty log message ***
 *
 * Revision 1.4  1993/09/21  17:16:25  yuan
 * cleaning up
 *
 * Revision 1.3  1993/09/14  13:11:57  yuan
 * cfread and cfwrite have been changed into lzw_expand and lzw_compress.
 * the new cfread and cfwrite functions are now in library.c
 * lzw_compress returns the compressed buffer and a parameter *size.
 *
 * Revision 1.2  1993/09/09  17:45:56  yuan
 * tab added to ERROR messages
 *
 * Revision 1.1  1993/09/08  16:15:03  yuan
 * Initial revision
 *
 * Revision 1.3  1993/07/24  19:05:22  yuan
 * *** empty log message ***
 *
 * Revision 1.2  1993/07/22  11:27:29  yuan
 * No change
 *
 * Revision 1.1  1993/07/21  15:28:48  matt
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>

#include "lzw.h"

#define BITS				15
#define MAX_CODE			( ( 1 << BITS ) - 1 )
#define TABLE_SIZE			35023L
#define END_OF_STREAM		256
#define BUMP_CODE			257
#define FLUSH_CODE			258
#define FIRST_CODE			259
#define UNUSED				-1

unsigned int find_child_node( int parent_code, int child_character );
unsigned int decode_string( unsigned int offset, unsigned int code );

typedef struct {
	int code_value;
	int parent_code;
	char character;
} DICTIONARY;

DICTIONARY * dict;

char * decode_stack;
unsigned int next_code;
int current_code_bits;
unsigned int next_bump_code;

#define PACIFIER_COUNT 2047

BIT_BUF *OpenOutputBitBuf( )
{
	BIT_BUF *bit_buf;

	bit_buf = (BIT_BUF *)malloc(1*sizeof(BIT_BUF));
	if ( bit_buf == NULL )
		return( bit_buf );
	bit_buf->current_byte = 0;
	bit_buf->rack = 0;
	bit_buf->mask = 0x80;
	bit_buf->pacifier_counter = 0;

	return( bit_buf );
}

BIT_BUF *OpenInputBitBuf( ubyte *buffer )
{
	BIT_BUF *bit_buf;

	bit_buf = (BIT_BUF *)malloc(1*sizeof(BIT_BUF));
	if ( bit_buf == NULL )
		return( bit_buf );
	bit_buf->buf = buffer;
	bit_buf->current_byte = 0;
	bit_buf->rack = 0;
	bit_buf->mask = 0x80;
	bit_buf->pacifier_counter = 0;

	return( bit_buf );
}

void CloseOutputBitBuf( BIT_BUF *bit_buf )
{
	if ( bit_buf->mask != 0x80 )
		bit_buf->buf[bit_buf->current_byte++] = bit_buf->rack;
	free( bit_buf );
}

void CloseInputBitBuf( BIT_BUF *bit_buf )
{
	//free( bit_buf->buf );
	free( bit_buf );
}

void OutputBit( BIT_BUF *bit_buf, int bit )
{
	if ( bit )
		bit_buf->rack |= bit_buf->mask;
	bit_buf->mask >>= 1;
	if ( bit_buf->mask == 0 ) {
		bit_buf->buf[bit_buf->current_byte++] = bit_buf->rack;
		bit_buf->rack = 0;
		bit_buf->mask = 0x80;
	}
}

void OutputBits( BIT_BUF *bit_buf, unsigned int code, int count )
{
	unsigned int mask;

	mask = 1L << ( count - 1 );
	while ( mask != 0)
	{
		if ( mask & code )
			bit_buf->rack |= bit_buf->mask;
		bit_buf->mask >>= 1;
		if ( bit_buf->mask == 0 )
		{
			bit_buf->buf[bit_buf->current_byte++] = bit_buf->rack;
			bit_buf->rack = 0;
			bit_buf->mask = 0x80;
		}
		mask >>= 1;
	}
}

int InputBit( BIT_BUF *bit_buf )
{
	int value;

	if ( bit_buf->mask == 0x80 )
	{
		bit_buf->rack = bit_buf->buf[bit_buf->current_byte++];
		if ( bit_buf->rack == EOF )
		{
			//printf( "    ERROR : Fatal error in InputBit!\n" );
			//exit(4);
			return -1;
		}
	}

	value = bit_buf->rack & bit_buf->mask;
	bit_buf->mask >>= 1;
	if ( bit_buf->mask == 0 )
		bit_buf->mask = 0x80;

	return( value ? 1 : 0 );
}

unsigned int InputBits( BIT_BUF *bit_buf, int bit_count )
{
	unsigned int mask;
	unsigned int return_value;

	mask = 1L << ( bit_count - 1 );
	return_value = 0;

	while ( mask != 0)
	{
		if ( bit_buf->mask == 0x80 )
		{
			bit_buf->rack = bit_buf->buf[bit_buf->current_byte++];
			if ( bit_buf->rack == EOF )
			{
				//printf( "    ERROR : Fatal error in InputBits!\n" );
				//exit(5);
				return 0xFFFFFFFF;
			}
		}

		if ( bit_buf->rack & bit_buf->mask )
			return_value |= mask;

		mask >>= 1;
		bit_buf->mask >>= 1;
		if ( bit_buf->mask == 0 )
			bit_buf->mask = 0x80;
	}

	return( return_value );
}

void InitializeDictionary()
{
	unsigned int i;

	for ( i = 0 ; i < TABLE_SIZE ; i++ )
		dict[i].code_value = UNUSED;

	next_code = FIRST_CODE;

	current_code_bits = 9;
	next_bump_code = 511;
}

void InitializeStorage()
{
	dict = (DICTIONARY *)malloc(TABLE_SIZE*sizeof(DICTIONARY));
	decode_stack = (char *)malloc(TABLE_SIZE*sizeof(char));
}

void FreeStorage()
{
	free(dict);
	free(decode_stack);
}

ubyte *lzw_compress( ubyte *inputbuf, ubyte *outputbuf, int input_size, int *output_size )
{
	BIT_BUF *output;
	int character;
	int string_code;
	unsigned int index;
	int i;

	output = OpenOutputBitBuf();

	if ( outputbuf == NULL )
	{
		output->buf = (ubyte *)malloc(input_size*sizeof(ubyte));
		if (output->buf == NULL)
		{
			//printf("    ERROR : OpenOutputBitBuf - Not enough memory to read buffer.\n");
			//exit(1);
			return NULL;
		}
		outputbuf = output->buf;
	}
	else
	{
		output->buf = outputbuf;
	}

	InitializeStorage();
	InitializeDictionary();
	string_code = ( *inputbuf++ );
	for ( i=0 ; i<input_size ; i++ )
	{
		if ( output->current_byte+4 >= *output_size )
		{
			CloseOutputBitBuf( output );
			FreeStorage();
			free( outputbuf );
			*output_size = -1;
			return NULL;
		}

		character = ( *inputbuf++ );
		index = find_child_node( string_code, character );
		if ( dict[ index ].code_value != - 1 )
		{
			string_code = dict[ index ].code_value;
		}
		else
		{
			dict[ index ].code_value = next_code++;
			dict[ index ].parent_code = string_code;
			dict[ index ].character = (char) character;
			OutputBits( output,(uint32_t) string_code, current_code_bits );
			string_code = character;

			if ( next_code > MAX_CODE )
			{
				OutputBits( output,(uint32_t) FLUSH_CODE, current_code_bits );
				InitializeDictionary();
			}
			else if ( next_code > next_bump_code )
			{
				OutputBits( output,(uint32_t) BUMP_CODE, current_code_bits );
				current_code_bits++;
				next_bump_code <<= 1;
				next_bump_code |= 1;
			}
		}
	}
	OutputBits( output, (uint32_t) string_code, current_code_bits );
	OutputBits( output, (uint32_t) END_OF_STREAM, current_code_bits);

	*output_size = output->current_byte + 1;

	CloseOutputBitBuf( output );
	FreeStorage();

	return outputbuf;
}

ubyte *lzw_expand( ubyte *inputbuf, ubyte *outputbuf, int length )
{
	BIT_BUF *input;
	unsigned int new_code;
	unsigned int old_code;
	int character;
	unsigned int count;
	int counter;

	input = OpenInputBitBuf( inputbuf );
	if ( outputbuf == NULL )
		outputbuf = (ubyte *)malloc(length*sizeof(ubyte));

	InitializeStorage();
	counter = 0;
	for ( ; ; )
	{

		InitializeDictionary();
		old_code = (unsigned int) InputBits( input, current_code_bits );
		if ( old_code == END_OF_STREAM )
		{
			CloseInputBitBuf( input );
			return outputbuf;
		}
		character = old_code;

		if (counter<length)
		{
			outputbuf[counter++] = ( ubyte ) old_code;
		}
		else
		{
			//printf( "ERROR:Tried to write %d\n", old_code );
			//exit(1);
			return 0;
		}

		for ( ; ; )
		{

			new_code = (unsigned int) InputBits( input, current_code_bits );
			if ( new_code == END_OF_STREAM )
			{
				CloseInputBitBuf( input );
				FreeStorage();
				return outputbuf;
			}
			if ( new_code == FLUSH_CODE )
				break;

			if ( new_code == BUMP_CODE )
			{
				current_code_bits++;
				continue;
			}

			if ( new_code >= next_code )
			{
				decode_stack[ 0 ] = (char) character;
				count = decode_string( 1, old_code );
			}
			else
			{
				count = decode_string( 0, new_code );
			}

			character = decode_stack[ count - 1 ];
			while ( count > 0 ) {
				// This lets the case counter==length pass through.
				// This is a hack.
				if (counter<length) {
 					//printf("%x ", ( ubyte ) decode_stack[ count ]);
					outputbuf[counter++] = ( ubyte ) decode_stack[ --count ];

				} else if (counter>length) {
					printf( "ERROR:Tried to write %d\n", decode_stack[ --count ] );
					exit(1);
				} else
					count--;
			}
			dict[ next_code ].parent_code = old_code;
			dict[ next_code ].character = (char) character;
			next_code++;
			old_code = new_code;
		}
	}
}

unsigned int find_child_node( int parent_code, int child_character ) {
	unsigned int index;
	int offset;

	index = ( child_character << ( BITS - 8 ) ) ^ parent_code;
	if ( index == 0 )
		offset = 1;
    else
		offset = TABLE_SIZE - index;

	for ( ; ; )
	{
		if ( dict[ index ].code_value == UNUSED )
			return( (unsigned int) index );

		if ( dict[ index ].parent_code == parent_code &&
			 dict[ index ].character == (char) child_character )
			return( index );
		if ( (int) index >= offset )
			index -= offset;
		else
			index += TABLE_SIZE - offset;
	}
}

unsigned int decode_string( unsigned int count, unsigned int code ) {
	while ( code > 255 ) {
		decode_stack[ count++ ] = dict[ code ].character;
		code = dict[ code ].parent_code;
	}
	decode_stack[ count++ ] = (char) code;
	return( count );
}
