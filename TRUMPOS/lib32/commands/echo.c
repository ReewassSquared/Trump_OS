#include <commands/echo.h>

#include <system.h>


void echo(unsigned int length, unsigned short *message)
{

	unsigned short *addr = message + 5;

	for( message = (unsigned short *) addr; message < addr + length; message++ )

	{

		putchar((unsigned char) (*message & 0x00FF));

	}

	putstr("\nDICTATED BUT NOT READ.\nTRUMP.\nPRESIDENT OF U.S.");
}
