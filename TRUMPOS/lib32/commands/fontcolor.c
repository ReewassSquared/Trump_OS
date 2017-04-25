#include <system.h>

void fontcolor(unsigned int length, unsigned short *message)
{
	bool bad;
	if(cmd_strcmp("black", message + 0xA, 5)){
		if(( getattribute() & 0xF0 ) >> 4 == BLACK){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(BLACK,  (( getattribute() & 0xF0 )) >> 4);
		putstr("hey, when did we get to detroit?");
	}
	else if(cmd_strcmp("blue", message + 0xA, 4)){
		if(( getattribute() & 0xF0 ) >> 4== BLUE){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(BLUE,  (( getattribute() & 0xF0 )) >> 4);
		putstr("the color of the clinton menace...");
	}
	else if(cmd_strcmp("green", message + 0xA, 5)){
		if(( getattribute() & 0xF0 ) >> 4 == GREEN){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(GREEN,  (( getattribute() & 0xF0 )) >> 4);
		putstr("the color of a mid-size loan of a billion dollars.");
	}
	else  if(cmd_strcmp("cyan", message + 0xA, 4)){
		if(( getattribute() & 0xF0 ) >> 4 == CYAN){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(CYAN,  (( getattribute() & 0xF0 )) >> 4);
		putstr("a smaller clinton menace...");
	}
	else if(cmd_strcmp("red", message + 0xA, 3)){
		if(( getattribute() & 0xF0 ) >> 4 == RED){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(RED,  (( getattribute() & 0xF0 )) >> 4); 
		putstr("the color of the best party. make america proud...");
	}
	else if(cmd_strcmp("magenta", message + 0xA, 7)){
		if(( getattribute() & 0xF0 ) >> 4 == MAGENTA){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(MAGENTA,  (( getattribute() & 0xF0 )) >> 4); 
		putstr("something trump would say about magenta. like, a tie joke.");
	}
	else if(cmd_strcmp("brown", message + 0xA, 5)){
		if(( getattribute() & 0xF0 ) >> 4 == BROWN){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(BROWN,  (( getattribute() & 0xF0 )) >> 4); 
		putstr("the color of the muslim terrorists...");
	}
	else if(cmd_strcmp("lightgrey", message + 0xA, 9)){
		if(( getattribute() & 0xF0 ) >> 4 == LIGHTGREY){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(LIGHTGREY, (( getattribute() & 0xF0 )) >> 4); 
		putstr("the color of the blue menace's suit");
	}
	else if(cmd_strcmp("darkgrey", message + 0xA, 8)){
		if(( getattribute() & 0xF0 ) >> 4 == DARKGREY){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(DARKGREY,  (( getattribute() & 0xF0 )) >> 4); 
		putstr("the color of my million dollar suit");
	}
	else if(cmd_strcmp("lightblue", message + 0xA, 9)){
		if(( getattribute() & 0xF0 ) >> 4 == LIGHTBLUE){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(LIGHTBLUE,  (( getattribute() & 0xF0 )) >> 4);
		putstr("the color may be light but symbolizes a dark evil...");
	}
	else if(cmd_strcmp("lightgreen", message + 0xA, 10)){
		if(( getattribute() & 0xF0 ) >> 4 == LIGHTGREEN){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(LIGHTGREEN,  (( getattribute() & 0xF0 )) >> 4); 
		putstr("the color of a small loan of a million dollars");
	}
	else if(cmd_strcmp("lightcyan", message + 0xA, 9)){
		if(( getattribute() & 0xF0 ) >> 4 == LIGHTCYAN){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(LIGHTCYAN,  (( getattribute() & 0xF0 )) >> 4); 
		putstr("reminds me of a dark dark evil...");
	}
	else if(cmd_strcmp("orange", message + 0xA, 6)){
		if(( getattribute() & 0xF0 ) >> 4 == ORANGE){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(ORANGE, (( getattribute() & 0xF0 )) >> 4); 
		putstr("the color of my skin...");
	}
	else if(cmd_strcmp("pink", message + 0xA, 4)){
		if(( getattribute() & 0xF0 ) >> 4 == PINK){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(PINK, (( getattribute() & 0xF0 )) >> 4); 
		putstr("INSERT CLEVER PUN HERE");
	}
	else if(cmd_strcmp("lightbrown", message + 0xA, 10)){
		if(( getattribute() & 0xF0 ) >> 4 == LIGHTBROWN){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor(LIGHTBROWN, (( getattribute() & 0xF0 )) >> 4);
		putstr("the color of a muslim terrorist...");
	}
	else if(cmd_strcmp("white", message + 0xA, 5)){
		if(( getattribute() & 0xF0 ) >> 4 == WHITE){
			bad = true;
			goto SPOONEDITUP;
		}
		settextcolor( WHITE, (( getattribute() & 0xF0 )) >> 4); 
		putstr("the superior color!");
	}
	else{
		putstr("c'mon, gringo. type a legitimate color or i'll send bannon after you.");
	}

	if(bad)
	{
		SPOONEDITUP: putstr("hey, you can't see the text if you did this! pick another color.");
	}
}
