#include <system.h>
#include <rand.h>

extern string trump_catch_phrases[30] = 
{
	"what I say is what I say",
	"We will build a wall! And Mexico's paying for it!",
	"Stupid, corrupt Hillary.",
	"Make America Great Again!",
	"The Concept of Global warming was created by and for the Chinese.",
	"I could stand in the middle of fifth avenue and shoot somebody and I wouldn't\nlose voters.",
	"I will be the greatest president that God has ever created",
	"vote for me you bad hombre",
	"Trump is your lord and saviour",
	"The muslim terrorists will destroy America",
	"The Affordable Care Act sucks. American Health Care Act all the way!",
	"Taxes!? Where we're going we don't need taxes...",
	"Democrats, why does it always have to be Democrats...",
	"I will save America",
	"Breitbart is the best news website God created ever"
	"Bite my pissy orange hair!"
	"Losers, i see losers"
	"All of the women on The Apprentice flirted with me - consciously or\nunconsciously. That's to be expected."
	"I really just see the bigness of it all, the USA"
	"Fox treats me well, it's that Fox is the most accurate"
	"It's pretty good, right? The red is obviously us."
	"The Russia is ... made up."
	"President Xi, we have a, like, a really great relationship."
	"President Xi is my gay lover"
	"Maybe we should boycott Starbucks."
	"I’ve always had a great relationship with the blacks"
	"Blood coming out of her pussy"
	"I’ve said if Ivanka weren’t my daughter, perhaps I’d be dating her"
	"My fingers are long and beautiful, as, it has been well documented, are various\nother parts of my body."
	"you can never be too greedy"
};

void trumpphrase(unsigned int length, unsigned short *message)
{
	unsigned short g = rand(get_timer_ticks());
	putstr(trump_catch_phrases[g % 30]);
}
