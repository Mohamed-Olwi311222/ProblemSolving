#include <string.h>
#include <stdio.h>
#include <stdbool.h>
void rev_str(char *s);
bool isPalindrome(int x)
{
    char str[20];
    char rev[20];
    size_t count = 0;

    snprintf(str, sizeof(str), "%d", x);
    snprintf(rev, sizeof(rev), "%d", x);
    rev_str(rev);
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == rev[i])
            count++;
    }
    if (count == strlen(str))
        return (true);
    return (false);
    
}
void rev_str(char *s)
{
	int length = strlen(s);
	int middle = length / 2;
	char tmp;
	int i;

	for (i = 0; i < middle; i++)
	{
		tmp = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = tmp;
	}
}