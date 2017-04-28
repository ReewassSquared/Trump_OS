#ifndef SYSTEM_H
#define SYSTEM_H

//screen library stuff.
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
#include <string.h>
#include <cmd.h>
#include <rand.h>
#include <stdio.h> //<-- contains the pci bus stuff and some of the usb stuff.
#include <drivers/pci.h>

struct regs
{
	unsigned int gs, fs, es, ds;
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
	unsigned int int_no, err_code;
	unsigned int eip, cs, eflags, useresp, ss;
};

//here is a registry of environment flags and variables for the purpose of stuff.

struct registry
{
	bool print_all_messages;
	bool print_boot_messages;
	uint32_t UHCI_base;
	uint32_t UHCI_size;
	uint32_t OHCI_base;
	uint32_t OCHI_size;
	uint32_t EHCI_base;
	uint32_t EHCI_size;
	uint32_t xHCI_base;
	uint32_t xHCI_size;
};

typedef struct __attribute__((packed)) time
{
	short miliseconds;
	byte seconds;
	byte minutes;
	byte hours;
	short days;
	byte weeks;
	short years;
} time;

//general-purpose programs for use later... 
extern unsigned char *memcpy(void *dest, const void *src, size_t count);
extern unsigned char *memset(void *dest, char val, size_t count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);
extern unsigned short inportw (unsigned short _port);
extern void outportw (unsigned short _port, unsigned short _data);
extern unsigned int inportd (unsigned short _port);
extern void outportd (unsigned short _port, unsigned int _data);
extern void disable_interrupts(void);
extern void enable_interrupts(void);

//screen functions for text stuff
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

extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();
extern void gdt_init();
extern void idt_init();
extern void isrs_init();
extern void irq_init();
extern void irq_install_handler(int irq, void (*handler) (struct regs *r));
extern void irq_uninstall_handler(int irq);
extern void timer_init();
extern unsigned int get_timer_ticks(void);
extern void timer_stall();
extern void keyboard_init();

extern bool rtrn;

extern void init_commands();

extern string trump_catch_phrases[]; 

//timer stuff

extern void set_frequency(size_t set);
extern void rtc_init(void);
extern time get_time(void);
extern void set_time(time nt);
extern byte get_seconds(void);
extern byte get_minutes(void);
extern byte get_hours(void);
extern short get_days(void);
extern byte get_weeks(void);
extern short get_years(void);
extern void rtc_stall(size_t y);

extern struct registry ENVIRONMENT_VARS;

//extern string get_cmd();

#endif
