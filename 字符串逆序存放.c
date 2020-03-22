/**************************************************************/
//FOR INSTANCE:
//input : Hello 007
//output: 700 olleH
/**************************************************************/

#include <stdio.h>
#include <string>

void reverse(char s[])
{
	int length = strlen(s);
	for (int i = 0; i < length / 2 ; i++)
	{
		char temp = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = temp;
	}
}

int main()
{
	char str[100];
	gets_s(str);
	reverse(str);
	puts(str);
	return 0;
}
