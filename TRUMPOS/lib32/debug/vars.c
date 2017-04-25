#include <debug/debug.h>

unsigned short *listentryptr;
bool odd;

int cursor_loc;

menu var_window;

void init_var_display(void)
{
	list_arrow_scroll();
	settextcolor(WHITE, BLUE);
}

void init_listentryptr(void)
{
	/*entry point for debug mode*/
	clearscreen();
	unsigned char attr = (BLUE << 4) | (WHITE & 0x0F);
	listentryptr = 0xB8000;
	for(int y = 0; y < 80; y++)
	{
		*listentryptr = (attr << 8) | 219;
		listentryptr++;
	}
	string str = "this is a list of all the variables and their values.";
	for( int y = 0; y < 80; y++)
	{
		if( y < strlen(str))
		{
			*listentryptr = (attr << 8) | str[y];
			listentryptr++;
		}
		else
		{
			*listentryptr = (attr << 8) | 32;
			listentryptr++;
		}
	}
	for( int y = 0; y < 80; y++)
	{
		*listentryptr = (attr << 8) | 32;
		listentryptr++;
	}
	for(int y = 0; y < 80; y++)
	{
		*listentryptr = (attr << 8) | 219;
		listentryptr++;
	}
	for(;;);
}
//offset = 3, count = 74

/*
DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
wordswordswordswords...
morewordsmorewordsmorewords...
DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
 >Dvar1			     valueD
  Dvar2			     valueD
  Dvar3			     valueD
............until var17..............
DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD

MENUMENUMENUMENUMENUMENUMENUMENUMENU



*/
