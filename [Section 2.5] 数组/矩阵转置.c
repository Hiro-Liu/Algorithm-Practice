#include <stdio.h>

int main() 
{
	const int X = 2;  
	const int Y = 3;
	int a[X][Y];
	int b[Y][X];
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			b[i][j] = a[j][i];
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
  
	return 0;
}
