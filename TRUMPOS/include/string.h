#ifndef STRING_H
#define STRING_H
#include <stdbool.h>
#include <stdint.h>

typedef char *string;

extern int strlen(const char *str);
extern bool strcmp(unsigned char *str1, unsigned char *str2);
extern string strcat(unsigned char *str1, unsigned char *str2);
extern bool strocc(unsigned char *strbig, unsigned char *strins);
extern unsigned int strocc_times(unsigned char *strbig, unsigned char *strins);
extern string bool_to_string(bool r);
extern bool charocc(unsigned char *str, unsigned char f);
extern unsigned int charocc_times(unsigned char *str, unsigned char f);
extern string removechar(string g, char r);
extern string num_to_string(size_t r, size_t base, unsigned char *buf);
extern char* itoa(size_t i, size_t base);

#endif
