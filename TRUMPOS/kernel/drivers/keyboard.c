#include <system.h>
#include <commands/debug.h>
#include <vga/menu.h>

unsigned char lastchar;
unsigned int keychr;

unsigned char keys_layout[128] =
{
	0,  27,
	'1', '2', '3', '4', '5', '6', '7', '8',
	/* 9 */
	'9', '0', '-', '=', '\b',	/* Backspace */
 	'\t',			/* Tab */
	'q', 'w', 'e', 'r',	/* 19 */
	't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
	 210,			/* 29   - Control */
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
	'\'', '`',   201,		/* Left shift */
	'\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
	'm', ',', '.', '/',   
	202,				/* Right shift */
	'*',  209,/* Alt */
	' ',	/* Space bar */
	200,/* Caps lock */
	211,/* 59 - F1 key ... > */
	212, 213, 214, 215, 216, 217, 218, 219,
	220,/* < 0... F10 */
	0,	/* 69 - Num lock*/
	0,	/* Scroll Lock */
	0,/* Home key */
	203,/* Up Arrow */
	0,/* Page Up */
	'-',
    	204,/* Left Arrow */
	0,
    	205,/* Right Arrow */
	'+',
	0,	/* 79 - End key*/
	206,/* Down Arrow */
	0,	/* Page Down */
	207,/* Insert Key */
	208,/* Delete Key */
	0,   0,   0, 221,/* F11 Key */
	222,/* F12 Key */
	0,	/* All other keys are undefined */
};		

unsigned char keys_layout_shft[128] =
{
	0,  27,
	'!', '@', '#', '$', '%', '^', '&', '*',
	/* 9 */
	'(', ')', '_', '+', '\b',	/* Backspace */
 	'\t',			/* Tab */
	'Q', 'W', 'E', 'R',	/* 19 */
	'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',	/* Enter key */
	 210,			/* 29   - Control */
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':',	/* 39 */
	'\"', '~',   201,		/* Left shift */
	'|', 'Z', 'X', 'C', 'V', 'B', 'N',			/* 49 */
	'M', '<', '>', '\?',   
	202,				/* Right shift */
	'*',  209,/* Alt */
	' ',	/* Space bar */
	200,/* Caps lock */
	211,/* 59 - F1 key ... > */
	212, 213, 214, 215, 216, 217, 218, 219,
	220,/* < 0... F10 */
	0,	/* 69 - Num lock*/
	0,	/* Scroll Lock */
	0,/* Home key */
	203,/* Up Arrow */
	0,/* Page Up */
	'-',
    	204,/* Left Arrow */
	0,
    	205,/* Right Arrow */
	'+',
	0,	/* 79 - End key*/
	206,/* Down Arrow */
	0,	/* Page Down */
	207,/* Insert Key */
	208,/* Delete Key */
	0,   0,   0, 221,/* F11 Key */
	222,/* F12 Key */
	0,	/* All other keys are undefined */
};	

/* REAL QUICK:
I WANT TO SAY WHAT THE ACTUAL VALUES FOR THE UN-ASCII-FIED CHARACTERS ARE (AKA, SPECIAL CHARACTERS):
200 = CAPS LOCK
201 = LEFT SHIFT
202 = RGIHT SHIFT
203 = UP ARROW
204 = LEFT ARROW
205 = RIGHT ARROW
206 = DOWN ARROW
207 = INSERT
208 = DELETE
209 = ALT KEY
210 = CTRL KEY
211-222 = F1-F12
223 = ...*/

bool lshft;
bool rshft;
bool lctrl;
bool lalt;
bool delete_;

bool numlock;
bool scrolllock;
bool capslock;

bool default_keyboard_modifier;
bool keyboard_modifier_list_arrow;
unsigned int num_of_entries;

void lights()
{
	if(numlock){
		if(capslock){
			if(scrolllock){
				outportb(0x64, 0xED);
				outportb(0x64, 0x7);
			}
			else {
				outportb(0x64, 0xED);
				outportb(0x64, 0x6);
			}
		}
		else if(scrolllock){
			outportb(0x64, 0xED);
			outportb(0x64, 0x3);
		}
		else {
			outportb(0x64, 0xED);
			outportb(0x64, 0x2);
		}
	}
	else if(scrolllock){
		if(capslock){
			outportb(0x64, 0xED);
			outportb(0x64, 0x5);
		}
		else {
			outportb(0x64, 0xED);
			outportb(0x64, 0x1);
		}
	}
	else if(capslock){
		outportb(0x64, 0xED);
		outportb(0x64, 0x4);
	}
}

void disable_key_interrupts()
{
	outportb(0x64, 0xF5);
}

void enable_key_interrupts()
{
	outportb(0x64, 0xF4);
}

void keyboard_handler(struct regs *r)
{
	unsigned char scancode;
	
	scancode = inportb(0x60);

	if(default_keyboard_modifier)
	{
		if(keychr >= 256){
			goto SKP;
		}

		if(scancode >= 0x80)
		{
			if(scancode == 0xAA){
				lshft = false;
			}
			else if(scancode == 0xB6){
				rshft = false;
			}		
			else if(scancode == 0x9D){
				lctrl = false;
			}
			else if(scancode == 0xB8){
				lalt = false;
			}
			else if(scancode == 0xD3){
				delete_ = false;
			}
			
		}	
		else	
		{	
			if(scancode == 0x2A){
				lshft = true;
			}
			else if(scancode == 0x36){
				rshft = true;
			}		
			else if(scancode == 0x1D){
				lctrl = true;
			}
			else if(scancode == 0x38){
				//lalt = true;
				clearscreen();
				settextcolor(WHITE, BLUE);
				putstr("WHAT I SAY IS WHAT I SAY. LOAD THIS.");
				putstr("\n\nTRUMP_OS>>>");
				set_cmd_x(get_x());
				set_cmd_y(get_y());
			}
			else if(scancode == 0x53){
				delete_ = true;
			}
			else if(scancode == 0x1C)
			{
				__asm__ __volatile__ ("cli");
				cmd(keychr);
				keychr = 0;
				putstr("\nTRUMP_OS>>>");
				set_cmd_x(get_x());
				set_cmd_y(get_y());
				//num_to_string(get_cmd_y(), 10, 0); DEBUG
				//num_to_string(get_cmd_x(), 10, 1); ALSO DEBUG
				__asm__ __volatile__ ("sti");
			}	
			else if(keys_layout[scancode] == 200 && !capslock)
			{
				capslock = true;
			}
			else if(keys_layout[scancode] == 200 && capslock)
			{
				capslock = false;
			}
			//keep adding for each key handler you want...
			else
			{		
				if(scancode == (unsigned char) 0x0E && keychr != 0)
				{
					putchar(keys_layout[scancode]);
					keychr--;
				}
				else if(lshft || rshft)
				{
					putchar(keys_layout_shft[scancode]);
					keychr++;
				}
	
				else if(capslock && keys_layout[scancode] <= 122 && keys_layout[scancode] >= 97)
				{
					if(lshft || rshft)
					{
						putchar(keys_layout[scancode]);
						keychr++;
					}
					else
					{
						putchar((unsigned char) ((unsigned short)keys_layout[scancode] - 0x20));
						keychr++;
					}
				}
				else
				{
					if(scancode != 0x0E)
					{
						putchar(keys_layout[scancode]);
						keychr++;
					}
				}
			}
		}

		lights();
		lastchar = keys_layout[scancode];
		SKP:
		if(scancode == 0x1C && keychr >= 256)
		{
			putchar('\n');
			cmd(keychr);
			keychr = 0;
			putstr("\nTRUMP_OS>>>");
			set_cmd_x(get_x());
			set_cmd_y(get_y());
			//num_to_string(get_cmd_y(), 10, 0); DEBUG
			//num_to_string(get_cmd_x(), 10, 1); ALSO DEBUG
		}
	
		if(lctrl && lalt && delete_){
			rtrn = true;
		}
	}
	else if(keyboard_modifier_list_arrow && debug_mode)
	{
		if(keys_layout[scancode] == 206)
		{
			scrolldown(5);
		}
		else if(keys_layout[scancode] == 203)
		{
			scrollup(22);
		}
	}
}

void scrolldown(int lim)
{
	scroll_debug();
}

void scrollup(int lim)
{
	scroll_debug();
}

void keyboard_init()
{
	irq_install_handler(1, keyboard_handler);
	default_keyboard_modifier = true;
	keyboard_modifier_list_arrow = false;
	num_of_entries = 0;
	keychr = 0;
	lshft = false;
	rshft = false;
	lctrl = false;
	lalt = false;
	delete_ = false;

	numlock = false;
	scrolllock = false;
	capslock = false;
}
