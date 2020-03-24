#include <stdio.h>
#define N 5    //学生数
#define M 3    //科目数

struct studentInfo{
	int number;
	char name[20];
	int score[M];
}stu[N];

void input()
{
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &stu[i].number, &stu[i].name);
		for (int j = 0; j < M; j++)
			scanf("%d", &stu[i].score[j]);
	}
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		printf("%d %s", stu[i].number, stu[i].name);
		for (int j = 0; j < M; j++)
			printf(" %d", stu[i].score[j]);
      
		printf("\n");
	}
}

int main()
{
	input(stu);
	print(stu);
	return 0;
}
