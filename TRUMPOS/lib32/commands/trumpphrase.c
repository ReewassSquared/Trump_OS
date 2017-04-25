#include <system.h>
#include <rand.h>

extern string trump_catch_phrases[15] = 
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

};

void trumpphrase(unsigned int length, unsigned short *message)
{
	unsigned short g = rand();
	putstr(trump_catch_phrases[g % 15]);
}
