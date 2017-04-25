#ifndef CMD_H

#define CMD_H


#include <stdint.h>

#include <string.h>



typedef void (*command)(unsigned int, unsigned short *);


extern void cmd(size_t count);

extern bool cmd_strcmp(unsigned char *str1, unsigned short *str2, size_t countof1);

extern void getcmd();
extern string addr_arr(size_t num, char arr[]);

extern unsigned int commandsize;

extern string commands[];

extern command command_method[];

extern void setcommand(unsigned int index, command commandm, string name);



#endif
