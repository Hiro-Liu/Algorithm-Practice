方式一:

#include <stdio.h>
#define N 10

int main()
{
	int a[N],b[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		b[N - 1 - i] = a[i];
	}
	for (int i = 0; i < N; i++)
		a[i] = b[i];
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	return 0;
}

方式二:

#include <stdio.h>
#define N 10

int main()
{
	int a[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	int temp;
	for (int i = 0; i < N / 2; i++)
	{
		temp = a[i];
		a[i] = a[N - 1 - i];
		a[N - 1 - i] = temp;
	}
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	return 0;
}
