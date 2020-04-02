/****************************************************************************************/
//初始版本。OJ结果：运行时间>1000ms  TLE(Time Limited Exceeded) 
//思路：两点的正向路程就是起点A终点B的B-A段距离，逆向路程=总路程-正向路程，比较两段路程的长短后输出
/****************************************************************************************/
#include <stdio.h>

const int MAX = 100001;

int main()
{
	int N, D[MAX] = { 0 }, D_sum = 0;
	while (scanf("%d", &N) != EOF) {
		for (int i = 1; i <= N; i++) {
			scanf("%d", &D[i]);  //D[1]即D1
			D_sum += D[i];
		}

		int M, pt1, pt2;
		scanf("%d", &M);
		while (M--) {
			int shortest_dst = 0;
			scanf("%d %d", &pt1, &pt2);
			int start = (pt1 < pt2) ? pt1 : pt2;
			int end = (pt1 > pt2) ? pt1 : pt2;
			for (int i = start; i < end; i++) {
				shortest_dst += D[i];
			}
      
			if (D_sum < 2 * shortest_dst) {
				shortest_dst = D_sum - shortest_dst;
			}
			printf("%d\n", shortest_dst);
		}
	}
	return 0;
}


/*********************************************************/
//改动后的AC代码，运行时间<20ms
//思路改动：A点到B点的路程=绝对值(A点到第一个点的距离-B点到第一个点的距离)
/*********************************************************/
#include <stdio.h>

const int MAX = 100001;

int main()
{
	
	int N, D[MAX] = { 0 }, dst[MAX], D_sum = 0;
	while (scanf("%d", &N) != EOF) {
		for (int i = 1; i <= N; i++) {
			scanf("%d", &D[i]);  //D[1]即D1
			D_sum += D[i];
			dst[i + 1] = D_sum;  //第i+1个点到第一个点的距离
		}

		int M, pt1, pt2;
		scanf("%d", &M);
		while (M--) {
			int shortest_dst = 0;
			scanf("%d %d", &pt1, &pt2);
			shortest_dst = fabs(dst[pt1] - dst[pt2]);
			if (D_sum < 2 * shortest_dst) {  // IF: ALL-PART < PART
				shortest_dst = D_sum - shortest_dst;
			}
			printf("%d\n", shortest_dst);
		}
	}
	return 0;
}
