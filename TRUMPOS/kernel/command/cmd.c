#include <commands/include_commands.h>
#include <system.h>
#include <cmd.h>

/*

int spoon = 1;
int *fork = &spoon;

*fork = 1;

*/

void setcommand(unsigned int index, command commandm, string name)
{
	commands[index] = name;
	command_method[index] = commandm;
	commandsize++;
}

string commands[] = 
{
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, //64 for the 64 function detailed below
};

command command_method[] = 
{
	0, 0, 0, 0, 0, 0, 0, 0, /*8*/
	0, 0, 0, 0, 0, 0, 0, 0, /*16*/
	0, 0, 0, 0, 0, 0, 0, 0, /*24*/
	0, 0, 0, 0, 0, 0, 0, 0, /*32*/
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, //etc
	0, 0, 0, 0, 0, 0, 0, 0, //64 reserved currently; sub-commands can be accessed with the handler for that command.
};

/*to call a command, do:
	*(command_method[number]) (scrnlibptr);
*/

unsigned int commandsize;

void init_commands()
{
	/*every time you add a new command, make SURE to add it here...*/
	commandsize = 0;
	setcommand(0, help, "help");
	setcommand(1, echo, "echo ");
	//setcommand(2, debug, "debug ");
	setcommand(2, get, "get ");
	setcommand(3, screencolor, "screencolor ");
	setcommand(4, fontcolor, "fontcolor ");
	setcommand(5, calc, "calc ");
	setcommand(6, listcolor, "list colors");
	setcommand(7, trumpphrase, "trumpphrase");
}

unsigned short *scrnlibptr;

bool cmd_strcmp(unsigned char *str1, unsigned short *str2, size_t countof1)
{
	for(int x = 0; x < (int) countof1; x++)
	{
		if(*str1 != (unsigned char) (*str2 & 0x00FF) )
		{
			return false;
		}
		//putchar((unsigned char) (*str2 & 0x00FF));
		str1++;
		str2++;
	}
	return true;
}

void getcmd()
{
	scrnlibptr = (unsigned short *) 0xB8000;
	scrnlibptr += /*(unsigned short *)*/ (get_cmd_x() + (get_cmd_y() * SCREENWIDTH) );
}

string addr_arr(size_t num, char arr[])
{
	string ret;
	int x;
	for(x = 0; x < num; x++)
	{
		*ret = arr[x];
		ret++;
	}
	ret -= x;
	return ret;
}
	
bool unknown_command;

void cmd(size_t count)
{
	//num_to_string(get_cmd_y(), 10, 4); DEBUG
	//num_to_string(get_cmd_x(), 10, 5); ALSO DEBUG
	//for(int x = 0; x < 150 * SCREENWIDTH * SCREENWIDTH * SCREENHEIGHT * 150; x++){ REALLY DEBUG

	//} FINAL DEBUG.
	unknown_command = true;
	putchar('\n');
	getcmd();
	if(count != 0)
	{
		for(unsigned int x = 0; x < commandsize; x++ )
		{
			if(cmd_strcmp(commands[x], scrnlibptr, strlen(commands[x])) && commands[x] != 0 && command_method[x] != 0)
			{
				command_method[x](count, scrnlibptr);
				unknown_command = false;
			}
			//putstr("\nreached point!");
		}

		if(unknown_command)
		{
			unknown_command = true;
			putstr("unknown command. use \"help\" to see the commands, filthy hillary supporter.");
		}
	}
	else if(count == 0)
	{
		putstr("type \"help\" to see a list of commands, bad hombre.");
	}
	//putstr("\nreached end of cmd().");    //ALSO DEBUG!!!
	//command_method[0](count, scrnlibptr); //DEBUG!!!
}
