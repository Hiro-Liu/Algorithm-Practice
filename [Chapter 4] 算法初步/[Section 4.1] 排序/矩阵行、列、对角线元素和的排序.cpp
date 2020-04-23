#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) {  //从大到小排序
    return x > y;
}

int main() {
    int m;
    int a[10][10];
    int sum[110]; //前m个元素表示行和,中间m个元素表示列和，最后两个元素表示对角线和
    while (scanf("%d", &m) != EOF) {
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                sum[i] += a[i][j];      //第i行元素累加
                sum[m + j] += a[i][j];  //第j列元素累加
                if (i == j)             //若是主对角线元素
                    sum[2 * m] += a[i][j];
                if (i + j == m - 1)     //若是副对角线元素
                    sum[2 * m + 1] += a[i][j];
            }
        }
        sort(sum, sum + 2 * m + 2, cmp);
        for (int i = 0; i < 2 * m + 2; i++) {
            printf("%d ", sum[i]);
        }
        printf("\n");
    }
    return 0;
}
