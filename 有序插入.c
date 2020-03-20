#include <stdio.h>
#define N 10

int main()
{
	int a[N];
	int x;
	for (int i = 0; i < N -1; i++)
		scanf("%d", &a[i]);
	scanf("%d", &x);
	for (int i = 0; i < N - 1; i++)
	{
		if (x < a[i])
		{
			for (int j = N -1 ; j > i; j--)
			{
				a[j] = a[j - 1];
			}
			a[i] = x;
			break;
		}
	}
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	return 0;
}
