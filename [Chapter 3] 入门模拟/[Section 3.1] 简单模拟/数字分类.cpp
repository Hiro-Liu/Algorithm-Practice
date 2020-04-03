#include <stdio.h>

int main()
{
	int N;
	while (scanf("%d", &N) != EOF) {
		int x, A[6] = { 0 }, sign = 1;
		bool exist = false;
		double sum = 0, count = 0;

               //输入和判断
		while(N--) {
			scanf("%d", &x);

			if (x % 5 == 0 && x % 2 == 0) {
				A[1] += x;
			}
			else if (x % 5 == 1) {
				exist = true;
				A[2] += x * sign;
				sign *= -1;
			}
			else if (x % 5 == 2) {
				A[3]++;
			}
			else if (x % 5 == 3) {
				sum += x;
				count++;
			}
			else if (x % 5 == 4) {
				if (x > A[5]) A[5] = x;
			}
		}
		
               //输出
		for (int i = 1; i <= 5; i++) {
			if (i == 2) {
				if (exist) printf("%d ", A[i]);
				else printf("N ");
			}
			else if (i == 4) {
				if (sum) printf("%.1f ", sum / count);
				else printf("N ");
			}
			else {
				if (A[i]) printf("%d ", A[i]);
				else printf("N ");
			}
		}

		printf("\n");
	}
	return 0;
}
