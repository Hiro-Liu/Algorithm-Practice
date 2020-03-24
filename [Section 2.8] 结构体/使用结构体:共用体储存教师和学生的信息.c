#include <stdio.h>

struct personInfo{
	int num;
	char name[10];
	char sex;
	char job;
	union {
		int classroom;
		char position[10];
	}category;
};

int main()
{
	int n;
	scanf("%d", &n);
	personInfo person[100];
  
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s %c %c", &(person + i)->num, &(person + i)->name,
			&(person + i)->sex, &(person + i)->job);
		if ((person + i)->job == 's')
			scanf("%d", &(person + i)->category.classroom);
		else
			scanf("%s", &(person + i)->category.position);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d %s %c %c ", (person + i)->num, (person + i)->name,
			(person + i)->sex, (person + i)->job);
		if ((person + i)->job == 's')
			printf("%d\n", (person + i)->category.classroom);
		else
			printf("%s\n", (person + i)->category.position);
	}

	return 0;
}
