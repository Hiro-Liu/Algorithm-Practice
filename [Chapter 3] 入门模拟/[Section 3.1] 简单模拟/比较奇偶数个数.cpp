#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int even = 0, odd = 0, num;
		while(n--) {
			scanf("%d", &num);
			if (num % 2) odd++;
			else even++;
		}
		if (even > odd) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
