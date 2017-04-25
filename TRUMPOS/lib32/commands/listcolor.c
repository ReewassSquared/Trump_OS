#include <system.h>
#define DARKGREY 0x8
#define LIGHTBLUE 0x9
#define LIGHTGREEN 0xA
#define LIGHTCYAN 0xB
#define ORANGE 0xC
#define PINK 0xD
#define LIGHTBROWN 0xE
#define WHITE 0xF
void listcolor(unsigned int length, unsigned short *message)
{
	putstr("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	putstr("\t\t\t\t     COLORS     \t\t\t\t");
	putstr("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	putstr("SCREEN CAN BE BLACK, GREEN, BLUE, RED, CYAN, MAGENTA, BROWN, AND LIGHTGREY.\n");
	putstr("FONT CAN BE:\nRED, GREEN, BLUE CYAN, MAGENTA, BROWN, BLACK, LIGHTGREY,\nDARKGREY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, ORANGE, PINK, LIGHTBROWN, AND WHITE.\nSCREEN AND FONT CANNOT BE THE SAME COLOR, GRINGO.");
}
