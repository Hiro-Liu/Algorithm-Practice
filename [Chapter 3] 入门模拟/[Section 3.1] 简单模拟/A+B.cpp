/**************************************************************/
//Test：
//input：5,000,000  -15,000,000
//output：-10000000
/**************************************************************/
#include <stdio.h>
#include <string>
#include <math.h>

long long convert(char str[])
{
	long long num = 0;
	int n = 0;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] >= '0' && str[i] <= '9') {
			num += (str[i] - '0') * pow(10, n);
			n++;
		}
	}
	if (str[0] == '-') {
		num = -num;
	}
	return num;
}

int main()
{
	char a[20], b[20];
	while (scanf("%s %s", a, b) != EOF) {
		printf("%lld", convert(a) + convert(b));
	}
	return 0;
}
