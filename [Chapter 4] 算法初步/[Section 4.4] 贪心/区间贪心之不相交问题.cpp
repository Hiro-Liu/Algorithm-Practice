#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct Interval {
    int left;
    int right;
} I[10010];

bool cmp(Interval x, Interval y) {
    if (x.left != y.left) {  //按左端点从大到小排序
        return x.left > y.left;
    } else {  //左端点相等的按右端点从小到大排序
        return x.right < y.right;
    }
}

int main() {
    int n;  //区间个数
    while (scanf("%d", &n), n != 0) {
        for (int i = 0; i < n; i++) {  //输入n个区间
            scanf("%d %d", &I[i].left, &I[i].right);
        }
        sort(I, I + n, cmp);
        int count = 1;  //不相交的区间数,若有不相交那必定直接是2个区间
        int lastLeft = I[0].left;//上一个入选区间的左端点
        for (int i = 1; i < n; i++) {
            //如果当前区间右端点小于等于上个入选区间左端点,则不相交
            if (I[i].right <= lastLeft) {
                lastLeft = I[i].left;
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
