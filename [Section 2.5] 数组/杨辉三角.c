#include <stdio.h>
#define N 6

int main()
{
	int a[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0 || j == i)
				a[i][j] = 1;
			else
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

杨辉三角边上的值为1，中间数的值=正上方和左上方值的和。
如果要求手动输入层数后输出（层数N<=10），可以设置一个10×10的二维数组只输出前N层。
