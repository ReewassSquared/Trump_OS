//NOTE: THIS FILE HAS TO ONLY INHERIT FROM THIS INCLUDE, AS MULTIPLE DEFINITION ERRORS MAY OCCUR OTHERWISE.
//USE WITH CARE.
#include <debug/debug.h>

bool debug_mode;

void debug(unsigned int length, unsigned short *message)
{
	debug_mode = false;
	string r_ = "entrails";
	if(cmd_strcmp( r_, message + 6, strlen(r_) ) )
	{
		debug_mode = true;
	}
	init_listentryptr();
}
