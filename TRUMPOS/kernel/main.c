#include <system.h>
#include <commands/include_commands.h>

bool rtrn = false;


void main()
{	/*initialization functions*/
	init_video();
	/*THESE ARE TEST THINGIES:
	for(int x = 32; x < 256; x++)	
	{
		putchar( (unsigned char) x );
	}
	*/
	putstr("WHAT I SAY IS WHAT I SAY. LOAD THIS.");
	//gdt_init();
	idt_init();
	isrs_init();
	irq_init();
	timer_init();
	//timer_stall(15); ERRORS WITH TIMER... Lol
	keyboard_init();
	/*finally*/
	putstr("\n\nTRUMP_OS>>>");
	set_cmd_x(get_x());
	set_cmd_y(get_y());
	init_commands();
	__asm__ __volatile__ ("sti");
    	for (;;)
	{
		//if(rtrn)
		//{
		//	break;
		//}
	}
}


	/*clearscreen();
	putstr("\n{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}");

	putstr("\n:/   _____                                   _____ \\;;/     _____       ____  \\:");

	putstr("\n:  //=====\\\\         /\\\         |        |  ||====> []    ///===\\\\\\    //||\\\\  :");

	putstr("\n: //       \\\\       //\\\\        |\\      /|  ||      ;;   |||  |  |||  //    \\\\ :");

	putstr("\n: ||               //  \\\\       ||\\    /||  ||___   []   |||  |  |||  \\\\___    :");

	putstr("\n: ||    ______    //____\\\\      |||\\  /|||  ||===>  ;;   |||-{0}-|||   \\\\==\\\\  :");

	putstr("\n: ||    \\===||   //======\\\\     ||||  ||||  ||      []   |||  |  |||        \\\\ :");

	putstr("\n: \\\\_______//   //        \\\\    || \\\\// ||  ||____  ;;   |||  |  |||   \\\\___// :");

	putstr("\n:  \\\\=====//  _/|_        _|\\_ _||_ \\/ _||_ ||====> []    \\\\\\===///     \\||//  :");

	putstr("\n:\\                                                /;;\                        /:");

	putstr("\n{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}{||}\n");

	putstr("VER. 0.0.1 --> new edition!\n\n");*/
