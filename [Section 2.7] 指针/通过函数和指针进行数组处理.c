#include <stdio.h>
#define N 10

void input(int* a)  //这种形参写法等价于(int a[])
{
	for (int i = 0; i < N; i++)
	{
		scanf("%d", a + i);
	}
}

void swap(int* a)
{
	int* max = &a[0], * min = &a[0];
	for (int i = 1; i < N ; i++)
	{
		if (*(a + i) > *max)
		{
			max = a + i;
		}

		if (*(a + i) < *min)
		{
			min = a + i;
		}		
	}

	int temp = *min;
	*min = a[0];
	a[0] = temp;

	temp = *max;
	*max = a[N-1];
	a[N-1] = temp;
}

void output(int* a)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", *(a + i));
	}
}

int main()
{
	int a[N];
	input(a);
	swap(a);
	output(a);
	return 0;
}
