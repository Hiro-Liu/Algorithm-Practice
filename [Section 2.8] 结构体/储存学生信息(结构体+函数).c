#include <stdio.h>
#define N 5    //共N个学生的信息
#define S 3    //每个学生需存S门成绩

struct studentInfo{
	int number;
	char name[20];
	int score[S];
}stu[N];

void input(struct studentInfo stu[])
{
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &stu[i].number, &stu[i].name);
		for (int j = 0; j < S; j++)
			scanf("%d", &stu[i].score[j]);
	}
}

void print(struct studentInfo stu[])
{
	for (int i = 0; i < N; i++)
	{
		printf("%d %s", stu[i].number, stu[i].name);
		for (int j = 0; j < S; j++)
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
