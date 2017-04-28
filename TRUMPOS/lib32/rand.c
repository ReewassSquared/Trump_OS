#include <stdbool.h>
#include <stdint.h>

unsigned short lfsr = 0xACE1;
unsigned bit;

unsigned short rand(short seed)
{
	lfsr += seed;
	bit = ( (lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
	return lfsr = (lfsr >> 1) | (bit << 15);
}

