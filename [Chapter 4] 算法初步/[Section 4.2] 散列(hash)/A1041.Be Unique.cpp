#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N, a[100010], hashTable[100010] = {0};
    cin >> N;
    for (int i = 0; i < N; i++) {
        // cin >> a[i];
        scanf("%d", &a[i]);  //数据量较大(N<=10^5),用cin和cout很可能会超时
        hashTable[a[i]]++;   //出现次数+1
    }

    int ans = -1;
    for (int i = 0; i < N; i++) {
        if (hashTable[a[i]] == 1) {  //若a[i]只出现了一次
            ans = a[i];              //答案就是a[i],打印后跳出循环
            printf("%d", ans);
            break;
        }
    }
    if (ans == -1) {  //若没有答案,即没有谁"与众不同"
        printf("None");
    }
    return 0;
}
