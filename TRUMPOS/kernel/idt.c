#include <system.h>

struct __attribute__((packed)) idt_entry
{
	unsigned short base_bottom;
	unsigned short selector;
	unsigned char zero;
	unsigned char flags;
	unsigned short base_top;
};

struct __attribute__((packed)) idt_ptr
{
	unsigned short limit;
	unsigned int base;
};

struct idt_entry idt[256]; //first 32 are reserved!
struct idt_ptr iptr;

extern void idt_load();

void idt_set_entry(unsigned char num_, unsigned long base_, unsigned short selector_, unsigned char flags_)
{
	//i did it all by myself!
	idt[num_].base_bottom = base_ & 0xFFFF;
	idt[num_].base_top = (base_ >> 16) & 0xFFFF;
	idt[num_].selector = selector_;
	idt[num_].zero = 0;
	idt[num_].flags = flags_;
}

void idt_init()
{
	iptr.limit = (sizeof(struct idt_entry) * 256) - 1;
	iptr.base = &idt;
	
	memset(&idt, 0, sizeof(struct idt_entry) * 256 );
	
	//ADD ISRs TO THE IDT HERE!!! USE THE IDT_SENT_ENTRY() FUNCTION!
	
	idt_load();
}
