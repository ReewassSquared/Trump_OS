#include <system.h>

void help(unsigned int length, unsigned short *message) //eventually it will load the object "help_menu"
{
	putstr("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	putstr("\t\t\t\t    COMMANDS    \t\t\t\t");
	putstr("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	putstr("{0} echo - echoes a statement. usage: \"echo <text>\"\n");
	putstr("{1} help - loads this menu. usage: \"help\"\n");
	//putstr("{2} debug - loads the debug commands. usage: \"debug <password>\"\n");
	putstr("{2} get - gets a thing from trump. usage: \"get <thing>\"\n");
	putstr("{3} screencolor - changes screencolor. usage: \"screencolor <color> \"\n");
	putstr("{4} fontcolor - changes the fontcolor. usage: \"fontcolor <color>\"\n");
	putstr("{5} calc - calculates an expression. usage: \"calc <expression>\"\n");
	putstr("{6} list colors - lists font and screen colors. usage: \"list colors\"\n");
	putstr("{7} trumpphrase - I say a phrase to you. usage: \"trumpphrase\"\n");
}
