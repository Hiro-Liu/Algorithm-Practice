#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int* p1 = &a, * p2 = &b, * p3 = &c;

	int max = (*p1 > * p2 ? *p1 : *p2) > * p3 ? (*p1 > * p2 ? *p1 : *p2) : *p3;
	int min = (*p1 < * p2 ? *p1 : *p2) < * p3 ? (*p1 < * p2 ? *p1 : *p2) : *p3;

	printf("%d %d %d", max, *p1 + *p2 + *p3 - max - min, min);
	return 0;
}
