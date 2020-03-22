#include <stdio.h>
#include <string>

void vowels(char s1[],char s2[])
{
	for (int i = 0, j = 0; i < strlen(s1); i++)
	{
		if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')
			s2[j++] = s1[i];
	}
}

int main()
{
	char str1[100];
	char str2[100] = "\0" ;
	gets_s(str1);
	vowels(str1,str2);
	puts(str2);
	return 0;
}
