#include <stdio.h>
#include <string>

const int MAX = 10000;

int main()
{
	int tree[MAX];
	int L, M;  //L+1颗树  M个区间
	int left, right;  //区间端点
	while (scanf("%d %d", &L, &M), L || M) {
		memset(tree, -1, sizeof(tree));  //重置，非零常数-1表示树存在
		//删除M个区间的树
		while (M--) {
			scanf("%d %d", &left, &right);
			for (int i = left; i <= right; i++) {
				tree[i] = 0;
			}
		}
		//计算剩余的树
		int count = 0;
		for (int i = 0; i < L + 1; i++) {
			if (tree[i]) count++; 
		}
		printf("%d\n", count);
	}
	return 0;
}
