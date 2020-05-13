//Source_https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264

#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;

//令sum[i]表示从A[1]到A[i]的和,A[i]为正整数故sum[i]严格单增
//要计算某一子序列的和,A[i]到A[j]的和只需要计算sum[j]-sum[i-1]
//本题使用1~N的数组下标

int main() {
    int N, S, nearS = 1e7;
    scanf("%d %d", &N, &S);
    int sum[maxn];
    sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }

    for (int i = 1; i <= N; i++) {  //枚举左端点
        // S=sum[j]-sum[i-1] -> sum[j]=sum[i-1]+S
        // lower_bound(),求数组内第一个大于等于第三个参数的元素地址
        int j = lower_bound(sum + i, sum + N + 1, sum[i - 1] + S) -
                sum;                     //求右端点下标
        int temp = sum[j] - sum[i - 1];  //计算下标i~j子序列的和
        if (temp == S) {  //若存在和恰等于S的子序列,则最接近S的就是S本身
            nearS = S;
            break;
        } else if (j <= N && temp < nearS) {
            //保证右端点范围且寻找最接近S的子序列和nearS
            nearS = temp;  //更新nearS
        }
    }

    for (int i = 1; i <= N; i++) {  //枚举左端点
        int j = lower_bound(sum + i, sum + N + 1, sum[i - 1] + S) -
                sum;  //求右端点下标
        int temp = sum[j] - sum[i - 1];
        if (temp == nearS)
            printf("%d-%d\n", i, j);
    }

    return 0;
}
