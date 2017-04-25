#include <system.h>

struct __attribute__((packed)) gdt_entry
{
	unsigned short limit_bottom;
	unsigned short base_bottom;
	unsigned char base_mid;
	unsigned char access;
	unsigned char granularity;
	unsigned char base_top;
};

struct __attribute((packed)) gdt_ptr
{
	unsigned short limit;
	unsigned int base;
};

struct gdt_entry gdt[3];
struct gdt_ptr gptr;

extern void gdt_flush();

void gdt_set_entry(int num_, unsigned short base_bottom_, unsigned short limit_bottom_, unsigned char base_mid_, unsigned char access_, unsigned char granularity_, unsigned char base_top_)
{
	gdt[num_].base_bottom = base_bottom_;     //the value of the thing.
	gdt[num_].base_mid = base_mid_;
	gdt[num_].base_top = base_top_;
	gdt[num_].limit_bottom = limit_bottom_;      //limit thing. look to the original bootldr.asm for the comments.
	gdt[num_].granularity = granularity_;
	gdt[num_].access = access_;
}

void gdt_init()
{
	gptr.limit = (sizeof(struct gdt_entry) * 3) - 1;
	gptr.base = &gdt; //LOCATIONS!
	
	//first up, the NULL DESCRIPTER!!!!!!!!!
	gdt_set_entry( 0,0,0,0,0,0,0 );
	
	//COAD SURGMURNTEH!!!!!!
	gdt_set_entry(1,0xFFFF, 0, 0, 0x9A, 0xCF, 0); //the hex codes are from the original bootldr.asm gdt...
	
	//DAAAAAATTTAAAA SEEEEEGGGMMMMEEENNNNTTT!!!!!!!!!!!
	gdt_set_entry(2,0xFFFF, 0, 0, 0x92, 0xCF, 0);
	
	//gotta get rid of the current one, lol
	gdt_flush(); //old gdt equals homeless and loaderless...
}
