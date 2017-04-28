#include <system.h>

/* FROM NOW ON, WE WILL BE USING THIS CLOCK SYSTEM AS OPPOSED TO THE OTHER CLOCK ON THE MOTHERBOARD SINCE THE RTC IS MUCH MORE CONVENIENT.

*/

time t;
unsigned int rtc_ticks_lower;
unsigned int rtc_ticks_upper;

void update_time()
{
	if(t.seconds % 60 == 0 && t.seconds != 0)
	{
		t.seconds = 0;
		t.minutes++;
		if(t.minutes % 60 == 0)
		{
			t.minutes = 0;
			t.hours++;
			if(t.hours % 24 == 0)
			{
				t.hours = 0;
				t.days++;
				if(t.days % 7 == 0)
				{
					t.weeks++;
				}

				if(t.days % 365 == 0)
				{
					t.days = 0;
					t.weeks = 0;
					t.years++;
				}
			}
		}
	}
}

void rtc_handler(struct regs *r)
{
	if(rtc_ticks_lower == 0xFFFFFFFF)
	{
		rtc_ticks_lower = 0x00000000;
		rtc_ticks_upper++;
	}

	if(rtc_ticks_lower % 1024 == 0)
	{
		t.seconds++;
		update_time();
	}
}


void rtc_init(void)
{
	irq_install_handler(8, rtc_handler);
	outportb(0x70, 0x8B);
	char prev=inportb(0x71);
	outportb(0x70, 0x8B);
	outportb(0x71, prev | 0x40);
	t.seconds = 0;
	t.minutes = 0;
	t.hours = 0;
	t.days = 0;
	t.weeks = 0;
	t.years = 0;
	rtc_ticks_lower = 0;
	rtc_ticks_upper = 0;
}

time get_time(void)
{
	return t;
}

void set_time(time nt)
{
	t.seconds = nt.seconds;
	t.minutes = nt.minutes;
	t.hours = nt.hours;
	t.days = nt.days;
	t.weeks = nt.weeks;
	t.years = nt.years;
}

byte get_seconds(void)
{
	return t.seconds;
}

byte get_minutes(void)
{
	return t.minutes;
}

byte get_hours(void)
{
	return t.hours;
}

short get_days(void)
{
	return t.days;
}

byte get_weeks(void)
{
	return t.weeks;
}

short get_years(void)
{
	return t.years;
}


void set_frequency(size_t set)
{
	if(set < 16 && set > 2)
	{
		disable_interrupts();
		outportb(0x70, 0x8A);
		char prev=inportb(0x71);
		outportb(0x70, 0x8A);
		outportb(0x71, (prev & 0xF0) | set);
		enable_interrupts();
	}
}
