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
