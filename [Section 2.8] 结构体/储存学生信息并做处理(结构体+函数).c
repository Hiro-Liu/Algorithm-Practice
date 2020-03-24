#include <stdio.h>

const int N = 10; //学生数
const int M = 3;  //科目数

struct studentInfo{
	int number;
	char name[20];
	int score[M];
}stu[N];

int sumscore[M] = { 0 };   //科目总分
int max = 0;               //个人最高总分
int index;                 //个人总分/平均分最高的学生下标

void input()
{
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &stu[i].number, &stu[i].name);

		int stu_sumscore = 0;  //个人总分
		for (int j = 0; j < M; j++) {
			scanf("%d", &stu[i].score[j]);
			stu_sumscore += stu[i].score[j];
			sumscore[j] += stu[i].score[j];	
		}

		if (stu_sumscore > max){
			max = stu_sumscore;
			index = i;
		}
	}	
}

void output()
{
	for (int j = 0; j < M; j++){
		printf("%.2f ", sumscore[j] / (N * 1.0));
	}
	
	printf("\n%d %s ", stu[index].number, stu[index].name);
	for (int j = 0; j < M; j++){
		printf("%d ", stu[index].score[j]);
	}
	printf("%.2f", max / (M * 1.0));
}

int main()
{
	input();
	output();
	return 0;
}
