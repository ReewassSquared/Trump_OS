#ifndef MENU_H
#define MENU_H
//basic vga text-mode objects, methods, structures, etc...
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

extern menu loading_screen;
extern bool keyboard_modifier_list_arrow;
extern bool default_keyboard_modifier;
extern unsigned int num_of_entries;

#endif
