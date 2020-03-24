#include <stdio.h>

struct student {
	int num;
	char name[20];
	char sex;
	int age;
};

int main()
{
	int n; 
	scanf("%d", &n);
	student stu[20];
	student* p = stu;
  
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s %c %d", &(p + i)->num, (p + i)->name, &(p + i)->sex, &(p + i)->age);
	}
  
	printf("\n");
  
	for (int i = 0; i < n; i++)
	{
		printf("%d %s %c %d\n", (p + i)->num, (p + i)->name, (p + i)->sex, (p + i)->age);
	}

	return 0;
}
