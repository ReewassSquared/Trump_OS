#include <string.h>
#include <system.h>

int strlen(const char *str)
{
	size_t c;
	for(c = 0; *str != '\0'; str++) c++;
	return c;
}

bool strcmp(unsigned char *str1, unsigned char *str2)
{
	if(strlen(str1) != strlen(str2))
	{
		return false;
	}
	else
	{
		for( int y = 0; y < strlen(str2); y++)
		{
			if(*str1 != *str2)
			{
				return false;
			}
			str1++;
			str2++;
		}
	}
	return true;
}

string strcat(unsigned char *str1, unsigned char *str2) //note: str1 is added to the end of str2
{
	string strret;
	for(int x = 0; x < strlen(str1); x++)
	{
		*strret = *str1;
		strret++;
		str1++;
	}
	for(int x = 0; x < strlen(str2); x++)
	{
		*strret = *str2;
		strret++;
		str2++;
	}
	return strret;
}

bool strocc(unsigned char *strbig, unsigned char *strins)
{
	int h, g;
	bool r = false;
	if(strlen(strbig) > strlen(strins) ){
		return false;
	}
	for(g = 0; g < strlen(strbig); g++)
	{
		if(*strlen == *strins)
		{
			r = true;
			for(h = 0; h < strlen(strins); h++)
			{
				if(*strlen != *strins)
				{
					r = false;
					break;
				}
				strins++;
				strbig++;
			}
			if(r)
			{
				return true;
			}
		} 
		strins++;
		strbig++;
	}
	return false;
}

unsigned int strocc_times(unsigned char *strbig, unsigned char *strins)
{
	int h, g;
	int e = 0;
	bool r = false;
	for(g = 0; g < strlen(strbig); g++)
	{
		if(*strlen == *strins)
		{
			r = true;
			for(h = 0; h < strlen(strins); h++)
			{
				if(*strlen != *strins)
				{
					r = false;
					break;
				}
				strins++;
				strbig++;
			}
			if(r)
			{
				e++;
			}
			
		} 
		strins++;
		strbig++;
	}
	return e;
}

bool charocc(unsigned char *str, unsigned char f)
{
	for(int x = 0; x < strlen(str); x++)
	{
		if(*str++ = f)
		{
			return true;
		}
	}
	return false;
}

unsigned int charocc_times(unsigned char *str, unsigned char f)
{
	unsigned int ret = 0;
	for(int x = 0; x < strlen(str); x++)
	{
		if(*str++ = f)
		{
			ret++;
		}
	}
	return ret;
}

void num_to_string(int r, int base, int yloc)
{
	int g = 0;
	char convert[25] = {0};
	if( r == 0 )
	{
		putchar_at('0', yloc, (SCREENWIDTH - 1));
	}
	else if(r < 0)
	{
		r  = -r;
		convert[g] = '-';
		g++;
	}
	int tmp = 0;
	while(r != 0)
	{
		tmp = r % base;
		if(tmp >= 36){
			convert[g] = (unsigned char) (61 + tmp);
		}
		else if(tmp >= 10)
		{
			convert[g] = (unsigned char) (55 + tmp);
		}
		else
		{
			convert[g] = (unsigned char) (tmp + 48);
		}
		r /= base;
		g++;
	}
	convert[g] = '\0';
	char *ret[strlen(convert) + 1];
	int x;
	for(x = 0; x < strlen(convert); x++)
	{
		ret[x] = convert[x];
		putchar_at(ret[x], yloc, (SCREENWIDTH - 1) - x);
	}
}
/*
#define INT_DIGITS 19		// enough for 64 bit integer 

char *itoa(i)
     int i;
{
  // Room for INT_DIGITS digits, - and '\0' 
  static char buf[INT_DIGITS + 2];
  char *p = buf + INT_DIGITS + 1;	// points to terminating '\0' 
  if (i >= 0) {
    do {
      *--p = '0' + (i % 10);
      i /= 10;
    } while (i != 0);
    return p;
  }
  else {			// i < 0 
    do {
      *--p = '0' - (i % 10);
      i /= 10;
    } while (i != 0);
    *--p = '-';
  }
  return p;
}
*/
string bool_to_string(bool r)
{
	if(r)
	{
		return "true";
	}
	return "false";
}

string removechar(string g, char r)
{
	int x = strlen(g) - charocc_times(g, r);
	int e = 0;
	char n[x];
	do
	{
		if(*g == r)
		{
			n[e] = g[e];
			e++;
		}
	} while(x != e);
	string str = r;
	return str;
}

string removestr(string g, string occ)
{
	int x = strlen(g) - strocc_times(g, occ);
	for(int e = 0; e < x; e++)
	{

	}
	//tmp
	return 0;
}
