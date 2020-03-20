#include <stdio.h>

int main()
{
	int a[10];
	int x;
	for (int i = 0; i < 9; i++)
		scanf("%d", &a[i]);
	scanf("%d", &x);
	for (int i = 0; i < 9 ; i++)
	{
		if (x < a[i])
		{
			for (int j = 9; j > i; j--)
			{
				a[j] = a[j - 1];
			}
			a[i] = x;	
			break;
		}
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
}
