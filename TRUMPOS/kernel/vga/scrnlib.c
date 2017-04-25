#include <system.h>
#include <commands/debug.h>

//Don’t make decisions based only on emotion.
//If you dream of a school teacher it indicates an interest in higher education
//Lack of conﬁdence in completing tasks or handling situations
//A beach in a dream represents a boundary between your pragmatic thoughts and your emotions, between knowledge and instinct.

unsigned short *screenptr;
int attrib = 0x1F;
int cursor_x, cursor_y;
int cmd_origin_x, cmd_origin_y;
unsigned int listptr_y;
int hard_listptr_y;

int getattribute()
{
	return attrib;
}

int get_x()
{
	return cursor_x;
}

int get_y()
{
	return cursor_y;
}

int get_cmd_x()
{
	return cmd_origin_x;
}

int get_cmd_y()
{
	return cmd_origin_y;
}

void set_cmd_x(int r)
{
	cmd_origin_x = r;
}

void set_cmd_y(int r)
{
	cmd_origin_y = r;
}


//scrolls the screen when needed...
void scroll(void)
{
	unsigned blank, tmp;
	//blank = space character (ascii code is 32, or 0x20.)
	blank = 0x20 | (attrib << 8);
	
	if(cursor_y >= SCREENHEIGHT)
	{
		tmp = cursor_y - SCREENHEIGHT + 1;
		memcpy(screenptr, screenptr + tmp * SCREENWIDTH, (SCREENHEIGHT - tmp) * 2 * SCREENWIDTH);
		memsetw(screenptr + ((SCREENHEIGHT - tmp) * SCREENWIDTH), blank, SCREENWIDTH);
		
		cursor_y = SCREENHEIGHT - 1;
		cmd_origin_y--;
		num_to_string(get_cmd_y(), 10, 0);
	}
}

//moves the blinking cursor thingy
void move_cursor(void)
{
	unsigned tmp;
	tmp = cursor_y * SCREENWIDTH + cursor_x;
	
	//send 14 and 15 control indices to the CRT control register in the VGA controller. cause blinking.
	//for more about VGA graphics stuff, go to http://www.brackeen.com/home/vga 
    outportb(0x3D4, 14);
    outportb(0x3D5, tmp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, tmp);
}

void clearscreen()
{
	unsigned blank;
	int i;
	blank = 0x20 | (attrib << 8);
	for(i = 0; i < SCREENHEIGHT; i++){
		memsetw(screenptr + i * SCREENWIDTH, blank, SCREENWIDTH);
	}
	
	cursor_x = 0;
	cursor_y = 0;
	move_cursor();
}

void putchar(unsigned char c)
{
	unsigned short *loc;
	unsigned att = attrib << 8;
	
	if(c == 0x08){   //backspace
		if(cursor_x > 0 /*&& bsz != 0*/) 
		{		
			/*buffer[bsz-1] = (char)0;*/
			cursor_x--;
			loc = screenptr + (cursor_x + cursor_y * SCREENWIDTH);
			*loc = 0 | att; //attribute setting with character setting as well!
			/*bsz--;*/
		}
	}
	else if(c == 0x09){   //tab
		cursor_x = (cursor_x + 8) & ~(8 - 1);
	}
	else if(c == '\r'){  //carriage return
		cursor_x = 0;
	}
	else if(c == '\n'){  //newline
		cursor_x = 0;
		cursor_y++;

		//PUT A SYSTEM FUNCTION CALL HERE

	}
	else if(c >= ' '){
		loc = screenptr + (cursor_x + cursor_y * SCREENWIDTH);
		*loc = c | att; //attribute setting with character setting as well!
		cursor_x++;
	}
	
	if(cursor_x >= SCREENWIDTH){
		cursor_x = 0;
		cursor_y++;
	}
	
	/*if(debug_mode)
	{
		scroll_debug();
	}
	else
	{
		scroll();
		move_cursor();
	}*/
	scroll();
	move_cursor();
}

void scroll_debug(bool direction) //direction: true = up, false = down.
{
	unsigned blank, tmp;
	//blank = space character (ascii code is 32, or 0x20.)
	blank = 0x20 | (attrib << 8);
	
	if(listptr_y >= 0 && !direction)
	{
		listptr_y++;
		screenptr[hard_listptr_y * SCREENWIDTH + 2] = (unsigned short) ( ( (BLUE << 4) | (WHITE & 0x0F) ) << 8 ) | ('>' & 0x00FF);
	}
}

char get_char()
{
	return (char) screenptr[cursor_y * SCREENHEIGHT + cursor_x];
}

void putstr(unsigned char *txt){
	int i;
	
	for(i = 0; i < strlen(txt); i++)
	{
		putchar(txt[i]);
	}
}

void putstr_at(unsigned char *txt, int cursorg_y, int cursorg_x)
{
	int tmp_x, tmp_y;
	tmp_x = cursor_x;
	tmp_y = cursor_y;
	cursor_x = cursorg_x;
	cursor_y = cursorg_y;
	int i;
	
	for( i = 0; i < strlen(txt); i++)
	{
		putchar(txt[i]);
	}
	cursor_x = tmp_x;
	cursor_y = tmp_y;
}

void putchar_at(unsigned char txt, int cursorg_y, int cursorg_x)
{
	int tmp_x, tmp_y;
	tmp_x = cursor_x;
	tmp_y = cursor_y;
	cursor_x = cursorg_x;
	cursor_y = cursorg_y;
	putchar(txt);
	cursor_x = tmp_x;
	cursor_y = tmp_y;
} 

void updatescreencolor()
{
	unsigned char *loc = 0xB8000;
	for(int i = 0; i < SCREENHEIGHT; i++)
	{
		for(int j = 0; j < SCREENWIDTH; j++)
		{
			memset(loc + (2 * j + 1) + (i * SCREENWIDTH * 2), attrib, 1);
		}
	}
}

void settextcolor(unsigned char forecolor, unsigned char backcolor)
{
	attrib = (backcolor << 4) | (forecolor & 0x0F);
	updatescreencolor();
}

void init_video(void)
{
	screenptr = (unsigned short *)0xB8000;
	clearscreen();
	listptr_y = 0;
	hard_listptr_y = 5;
}
