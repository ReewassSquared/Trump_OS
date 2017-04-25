#ifndef DEBUG_H
#define DEBUG_H
//THESE ARE POINTERS TO ALL OF THE THINGIES OUT THERE...

/*INCLUDES*/
#define SCREENWIDTH 80
#define SCREENHEIGHT 25
#define BLACK 0x0
#define BLUE 0x1
#define GREEN 0x2
#define CYAN 0x3
#define RED 0x4
#define MAGENTA 0x5
#define BROWN 0x6
#define LIGHTGREY 0x7
#define DARKGREY 0x8
#define LIGHTBLUE 0x9
#define LIGHTGREEN 0xA
#define LIGHTCYAN 0xB
#define ORANGE 0xC
#define PINK 0xD
#define LIGHTBROWN 0xE
#define WHITE 0xF
#define TIMETICKS 0xFFFF
struct regs
{
	unsigned int gs, fs, es, ds;
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
	unsigned int int_no, err_code;
	unsigned int eip, cs, eflags, useresp, ss;
};
typedef void (*command)(unsigned int, unsigned short *);
#define true 1
#define false 0

typedef unsigned char bool;
typedef unsigned char uint8_t;
typedef unsigned char byte;
typedef unsigned short uint16_t;
typedef unsigned short word;
typedef unsigned int uint32_t;
typedef unsigned int dword;
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;

typedef unsigned size_t;
typedef char *string;

extern int strlen(const char *str);
extern bool strcmp(unsigned char *str1, unsigned char *str2);
extern string strcat(unsigned char *str1, unsigned char *str2);
extern bool strocc(unsigned char *strbig, unsigned char *strins);
extern unsigned int strocc_times(unsigned char *strbig, unsigned char *strins);

typedef void (*menu_func)();
typedef struct __attribute__((packed)) element
{
	byte attr;
	char val;
} element;

typedef struct __attribute__((packed)) menu
{
	element __attribute__((packed)) data[25][80];
	menu_func keyboard_modifier;
	bool *type;
} menu;


//debug.c itself...
extern void debug(unsigned int length, unsigned short *message);
extern bool debug_mode;

//start.asm:
	//vars:
	
	//methods:
extern void gdt_flush();
extern void idt_load();
extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();
extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

//gdt.c:
	//vars:
extern struct gdt_entry gdt;
extern struct gdt_ptr gptr;
	//methods:
extern void gdt_set_entry(int num_, unsigned short base_bottom_, unsigned short limit_bottom_, unsigned char base_mid_, unsigned char access_, unsigned char granularity_, unsigned char base_top_);
extern void gdt_init();

//idt.c:
	//vars:
extern struct idt_entry idt; //first 32 are reserved!
extern struct idt_ptr iptr;
	//methods:
extern void idt_set_entry(unsigned char num_, unsigned long base_, unsigned short selector_, unsigned char flags_);
extern void idt_init();

//irq.c:
	//vars:
extern void *irq_routine[16];
	//methods:
extern void irq_install_handler(int irq, void (*handler) (struct regs *r));
extern void irq_uninstall_handler(int irq);
extern void irq_remap(void);
extern void irq_init();
extern void irq_handler(struct regs *r);

//isrs.c:
	//vars:
extern unsigned char *exception_message[];
	//methods:
extern void isrs_init();
extern void fault_handler(struct regs *r);

//main.c:
	//vars:
extern bool rtrn;
/* extern void main(); //don't have a need for this so let's just omit it... */
	//methods:

//keyboard.c:
	//vars:
extern unsigned char lastchar;
extern unsigned int keychr;
extern unsigned char keys_layout[128];
extern unsigned char keys_layout_shft[128];
extern bool lshft;
extern bool rshft;
extern bool lctrl;
extern bool lalt;
extern bool delete_;
extern bool numlock;
extern bool scrolllock;
extern bool capslock;
extern bool default_keyboard_modifier;
extern bool keyboard_modifier_list_arrow;
extern unsigned int num_of_entries;
	//methods:
extern void lights();
extern void disable_key_interrupts();
extern void enable_key_intterupts();
extern void keyboard_handler(struct regs *r);
extern void keyboard_init();

//timer.c:
	//vars:
extern unsigned int timer_ticks;
	//methods:
extern void time_handler(struct regs *r);
extern void timer_init();
extern void timer_stall(unsigned int ticks);

//ports.c:
	//vars:

	//methods:
extern unsigned char *memcpy(void *dest, const void *src, size_t count);
extern unsigned char *memset(void *dest, char val, size_t count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);

//scrnlib.c:
	//vars:
extern unsigned short *screenptr;
extern int attrib;
extern int cursor_x, cursor_y;
extern int cmd_origin_x, cmd_origin_y;
extern int listptr_y;
	//methods:
extern void clearscreen();
extern void putchar(unsigned char c);
extern void putstr(unsigned char *str);
extern int get_x();
extern int get_y();
extern int get_cmd_x();
extern int get_cmd_y();
extern void set_cmd_x();
extern void set_cmd_y();
extern int getattribute();
extern void scroll(void);
extern void move_cursor(void);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();
extern char get_char();


//cmd.c:
	//vars:
extern string commands[];
extern command command_method[];
extern unsigned int commandsize;
extern unsigned short *scrnlibptr;
extern bool unknown_command;
	//methods:
extern void setcommand(unsigned int index, command commandm, string name);
extern bool cmd_strcmp(unsigned char *str1, unsigned short *str2, size_t countof1);
extern void getcmd();
extern void cmd(size_t count);
extern string addr_arr(size_t num, char arr[]);
extern void init_commands();

//echo.c:
extern void echo(unsigned int length, unsigned short *message);

//help.c:
extern void help(unsigned int length, unsigned short *message);

//menu.c:
	//vars:
extern menu loading_screen;
	//methods:
extern void list_arrow_scroll();
extern void init_loading_screen();

//vars.c, debug mode special:
extern void init_listentryptr(void);

#endif
