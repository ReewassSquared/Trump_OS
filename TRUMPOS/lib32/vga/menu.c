#include <system.h>
#include <vga/menu.h>

menu loading_screen;

void list_arrow_scroll()
{
	keyboard_modifier_list_arrow = true;
	default_keyboard_modifier = false;
}

void init_loading_screen()
{
	byte attribute = (byte) getattribute();
	loading_screen.keyboard_modifier = list_arrow_scroll;
	for(int x = 0; x < 25; x++){
		if(x == 0 || x == 24)
		{
			for(int y = 0; y < 80; y++)
			{
				loading_screen.data[x][y].attr = attribute;
				loading_screen.data[x][y].val = 219;
			}
		}
	}
	string strings[11] =
	{
		"||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||",
		"/   _____                                   _____ \\;;/     _____       ____  \\",
		"  //=====\\\\         /\\         |        |  ||====> []    ///===\\\\\\    //||\\\\  ",
		" //       \\\\       //\\\\        |\\      /|  ||      ;;   |||  |  |||  //    \\\\ ",
		" ||               //  \\\\       ||\\    /||  ||___   []   |||  |  |||  \\\\___    ",
		" ||    ______    //____\\\\      |||\\  /|||  ||===>  ;;   |||-{0}-|||   \\\\==\\\\  ",
		" ||    \\===||   //======\\\\     ||||  ||||  ||      []   |||  |  |||        \\\\ ",
		" \\\\_______//   //        \\\\    || \\\\// ||  ||____  ;;   |||  |  |||   \\\\___// ",
		"  \\\\=====//  _/|_        _|\\_ _||_ \\/ _||_ ||====> []    \\\\\\===///     \\||//  ",
		"\\                                                /;;\                        /",
		"||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||",
	};
}
