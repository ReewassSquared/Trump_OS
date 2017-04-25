#include <system.h>

void screencolor(unsigned int length, unsigned short *message)
{
	bool badd;
	if(cmd_strcmp("black", message + 0xC, 5)){
		if(getattribute() & 0x0F == BLACK){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, BLACK);
		putstr("hey, when did we get to detroit?");
	}
	else if(cmd_strcmp("blue", message + 0xC, 4)){
		if(getattribute() & 0x0F == BLUE){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, BLUE);
		putstr("the color of the clinton menace...");
	}
	else if(cmd_strcmp("green", message + 0xC, 5)){
		if(getattribute() & 0x0F == GREEN){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, GREEN);
		putstr("the color of a mid-size loan of a billion dollars.");
	}
	else  if(cmd_strcmp("cyan", message + 0xC, 4)){
		if(getattribute() & 0x0F == CYAN){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, CYAN);
		putstr("a smaller clinton menace...");
	}
	else if(cmd_strcmp("red", message + 0xC, 3)){
		if(getattribute() & 0x0F == RED){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, RED); 
		putstr("the color of the best party. make america proud...");
	}
	else if(cmd_strcmp("magenta", message + 0xC, 7)){
		if(getattribute() & 0x0F == MAGENTA){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, MAGENTA); 
		putstr("something trump would say about magenta. like, a tie joke.");
	}
	else if(cmd_strcmp("brown", message + 0xC, 5)){
		if(getattribute() & 0x0F == BROWN){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, BROWN); 
		putstr("the color of the muslim terrorists...");
	}
	else if(cmd_strcmp("lightgrey", message + 0xC, 9)){
		if(getattribute() & 0x0F == LIGHTGREY){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, LIGHTGREY); 
		putstr("the color of the blue menace's suit");
	}
	/*else if(cmd_strcmp("darkgrey", message + 0xC, 8)){
		if(getattribute() & 0x0F == DARKGREY){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, DARKGREY); 
		putstr("the color of my million dollar suit");
	}
	else if(cmd_strcmp("lightblue", message + 0xC, 9)){
		if(getattribute() & 0x0F == LIGHTBLUE){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, LIGHTBLUE);
		putstr("the color may be light but symbolizes a dark evil...");
	}
	else if(cmd_strcmp("lightgreen", message + 0xC, 10)){
		if(getattribute() & 0x0F == LIGHTGREEN){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, LIGHTGREEN); 
		putstr("the color of a small loan of a million dollars");
	}
	else if(cmd_strcmp("lightcyan", message + 0xC, 9)){
		if(getattribute() & 0x0F == LIGHTCYAN){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, LIGHTCYAN); 
		putstr("reminds me of a dark dark evil...");
	}
	else if(cmd_strcmp("orange", message + 0xC, 6)){
		if(getattribute() & 0x0F == ORANGE){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, ORANGE); 
		putstr("the color of my skin...");
	}
	else if(cmd_strcmp("pink", message + 0xC, 4)){
		if(getattribute() & 0x0F == PINK){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, PINK); 
		putstr("INSERT CLEVER PUN HERE");
	}
	/*else if(cmd_strcmp("lightbrown", message + 0xC, 10)){
		if(getattribute() & 0x0F == LIGHTBROWN){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, LIGHTBROWN);
		putstr("the color of a muslim terrorist...");
	}
	else if(cmd_strcmp("white", message + 0xC, 5)){
		if(getattribute() & 0x0F == WHITE){
			badd = true;
			goto FORKEDITUP;
		}
		settextcolor( getattribute() & 0x0F, WHITE); 
		putstr("the superior color!");
	}*/
	else{
		putstr("c'mon, gringo. type a legitimate color or i'll send bannon after you.");
	}

	if(badd)
	{
		FORKEDITUP: putstr("hey, you can't see the text if you did this! pick another color.");
	}
}
