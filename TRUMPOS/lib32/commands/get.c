#include <system.h>

void get(unsigned int length, unsigned short *message)
{
	if(cmd_strcmp("time", message + 4, 4))
	{
		putstr("what do I look like, a watch!? I got a country to run!");
	}
	else if(cmd_strcmp("a life", message + 4, 6))
	{
		putstr("wow, clever. so original. haven't heard that one before.");
	}
	else if(cmd_strcmp("date", message + 4, 4))
	{
		putstr("today, duh.");
	}
	else if(cmd_strcmp("money", message + 4, 5) || cmd_strcmp("a small loan", message + 4, 12) || cmd_strcmp("more money", message + 4, 10) )
	{
		putstr("I have all the money and loans in the world. I'M THE PRESIDENT!");
	}
	else if(cmd_strcmp("out", message + 4, 3) )
	{
		putstr("I can be wherever I want, bad hombre.\n");
	}
	else
	{
		putstr("can't exactly get that. don't know how. GOT A COUNTRY TO RUN!");
	}
}
