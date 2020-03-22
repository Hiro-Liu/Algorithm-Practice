#include <stdio.h>
#include <string>

int main()
{
	const int N = 3;
	char s[N][20];
	for (int i = 0; i < 3; i++)
	{
		scanf("%s", s+i);
	}
  
	for (int i = 0; i < N-1 ; i++)    //冒泡排序对N个字符串由小到大重排
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (strcmp(*(s + j), *(s + j + 1)) >= 0)
			{
				char temp[20];
				strcpy(temp, *(s + j));
				strcpy(*(s + j), *(s + j + 1));
				strcpy(*(s + j + 1), temp);
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", s+i);
	}
	
	return 0;
}
