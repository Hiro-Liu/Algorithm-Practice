/*********************************************************/
//这里A B C需定义成long long以免A+B的结果超出int的取值范围
/*********************************************************/
#include <stdio.h>
#include <string>
#include <math.h>

const int MAX = 100001;
int main()
{
	int T;
	long long A, B, C;
	while (scanf("%d", &T) != EOF) {
		for (int i = 1; i <= T; i++) {
			scanf("%lld %lld %lld", &A, &B, &C);
			if ((A + B) > C) printf("Case #%d: true\n", i);
			else printf("Case #%d: false\n", i);
		}
	}
	return 0;
}
