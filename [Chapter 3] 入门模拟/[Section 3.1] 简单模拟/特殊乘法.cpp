#include <stdio.h>

int special_multiply(int x, int y)
{
	int x_sum = 0, y_sum = 0;
	
	while (x / 10) {	//若x变为个位数->break
		x_sum += x % 10;
		x /= 10;
	}
	x_sum += x;   //将剩余的最高位数加进去

	while (y / 10) {	
		y_sum += y % 10;
		y /= 10;
	}
	y_sum += y;  
	
	return x_sum * y_sum;
}

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", special_multiply(a, b));
	}
	return 0;
}
