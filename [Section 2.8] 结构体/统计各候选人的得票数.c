#include <stdio.h>
#include <string>

bool equal(char s1[], char s2[])
{
	if (strcmp(s1, s2) == 0)
		return true;
	else
		return false;
}

int main()
{
	struct nomineeInfo {
		char name[20];
		int votes;
	}nominee[3] = { "Li",0,"Zhang",0,"Fun",0 };

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char name[20];
		scanf("%s", name);
		for (int j = 0; j < 3; j++)
		{
			if (equal((nominee + j)->name, name))
			{
				(nominee + j)->votes++;
				break;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s:%d\n", (nominee + i)->name, (nominee + i)->votes);
	}
	return 0;
}
