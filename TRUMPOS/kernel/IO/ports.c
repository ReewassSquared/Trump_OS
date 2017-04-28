#include <system.h>

unsigned char* memcpy(void *dest, const void *src, size_t count)
{
	const char *sp = (const char *)src;
	char *dp = (char *)dest;
	for(; count != 0; count--) *dp++ = *sp++;
	return dest;
}

unsigned char* memset(void *dest, char val, size_t count)
{
	char *temp = (char *)dest;
	for( ; count != 0; count--) *temp++ = val;
	return dest;
}

unsigned short* memsetw(unsigned short *dest, unsigned short val, size_t count)
{
	unsigned short *temp = (unsigned short *)dest;
	for(; count != 0; count--) *temp++ = val;
	return dest;
}

unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

unsigned short inportw (unsigned short _port)
{
    unsigned short rv;
    __asm__ __volatile__ ("inw %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportw (unsigned short _port, unsigned short _data)
{
    __asm__ __volatile__ ("outw %1, %0" : : "dN" (_port), "a" (_data));
}

unsigned int inportd (unsigned short _port)
{
    unsigned int rv;
    __asm__ __volatile__ ("inl %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportd (unsigned short _port, unsigned int _data)
{
    __asm__ __volatile__ ("outl %1, %0" : : "dN" (_port), "a" (_data));
}

void disable_interrupts(void)
{
	__asm__ __volatile__ ("cli");
}

void enable_interrupts(void)
{
	__asm__ __volatile__ ("sti");
}

