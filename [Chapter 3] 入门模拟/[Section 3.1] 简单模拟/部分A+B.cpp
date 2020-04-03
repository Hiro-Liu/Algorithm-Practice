#include <stdio.h>
#include <string.h>
#include <math.h>

//const int MAX = 1000;

int calculate(char a[], int DA)
{
	int n = 0, PA = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] - '0' == DA) {
			PA += DA * pow(10, n);
			n++;
		}
	}
	return PA;
}

int main()
{
	int A, DA, B, DB;
	while (scanf("%d %d %d %d", &A, &DA, &B, &DB) != EOF) {
		char a[12], b[12];
    
		//从右到左，将int型变量以%d的格式写入字符数组中，或可直接定义字符数组来input
		sprintf(a, "%d", A);
		sprintf(b, "%d", B);

		printf("%d\n", calculate(a, DA) + calculate(b, DB));
	}
	return 0;
}
