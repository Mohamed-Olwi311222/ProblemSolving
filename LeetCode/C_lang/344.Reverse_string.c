#include "problems.h"
void reverseString(char* s, int sSize)
{
	char tmp = '\0';

	/**Thats mean that the whole string is reversed*/
	if (sSize <= 1)
	{
		return;
	}
	tmp = s[0];
	s[0] = s[sSize - 1];
	s[sSize - 1] = tmp;
	reverseString(s + 1, sSize - 2);
}
/**
 	sSize = 4
 	s = " MIDO"
	s[0] => 'M'
	tmp = s[0] = 'M'
	s[0] = s[sSize - 1] = 'D';
	s[sSize - 1] = tmp = 'M'

	then call the function again but with args (s + 1, sSize - 2)
	2nd call:
		s + 1 => "IDM"
		sSize - 2 => 1 for the index(as it start from zero) and because we moved s by 1
			       we will decrement it also by one as we already switched two chars
		sSize = 2
		s = "IDM"
		tmp = s[0] = 'I'
		s[0] = s[sSize - 1] = 'D'
		s[sSize - 1] = tmp = 'I'
	3rd call:
		s = "IM"
		sSize = 0
		the base case is true then exit
	and as the stack pops
	s = "IM"
	s = "DIM"
	s = "ODIM"
 **/
