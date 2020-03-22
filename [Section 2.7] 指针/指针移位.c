/**************************************************************/
//input: 2
//output:love China!
//input: 7
//output:China!
/**************************************************************/

#include <stdio.h>

int main()
{
	const char* a = "I love China!";
	int n;
	scanf("%d", &n);
	a = a + n;
	printf("%s", a);
	return 0;
}
