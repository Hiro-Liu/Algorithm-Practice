#include <stdio.h>
#include <string>

int main() 
{
	char str[100];
	gets(str);
	for (int i = 0; i < strlen(str); i++)
	{
		if ( str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = 'A' + 'Z' - str[i];
		}
			
		else if (str[i]>='a' && str[i] <= 'z') {
			str[i] = 'a' + 'z' - str[i];
		}
	}
	puts(str);
	return 0;
}
