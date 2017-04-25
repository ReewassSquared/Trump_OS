#include <system.h>

void set_timer_rate(int hz)
{
	int divisor = 1193180 / hz;
	outportb(0x43, 0x36);  		//00110110
	outportb(0x40, divisor & 0xFF);
	outportb(0x40, divisor >> 8);
}

unsigned int timer_ticks; 

void time_handler(struct regs *r)
{
	timer_ticks++;

	if(timer_ticks % (18 * 3600) == 0)
	{
		putstr("\nOne hour has passed\n");
	}
	/*else if(timer_ticks % 18 == 0)
	{
		putstr("\nOne second has passed\n");
	}*/
}

void timer_init()
{
	irq_install_handler(0, time_handler);
	timer_ticks = 0;
}

void timer_stall(unsigned int ticks)
{
	unsigned int tick_elapse = timer_ticks + ticks;
	while (timer_ticks < tick_elapse)
	{
		
	}
}
