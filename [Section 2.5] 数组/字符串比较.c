/*输入s1="ZAZA"  s2="AAAA"  由于ASCII(Z)=90 ASCII(A)=65 故输出25+25=50*/

#include <stdio.h>
#include <string>

int main() 
{
	char s1[100], s2[100];
	gets_s(s1);
	gets_s(s2);
	int sum=0;
	for (int i = 0; i < ((strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2)); i++)
	{
		if (s1[i] != s2[i])
			sum += s1[i] - s2[i];
	}
	printf("%d", sum);
	return 0;
}
