#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;  //要找的钱
    while (scanf("%d", &n), n != 0) {
        int a[5] = {0};           //分别代表1、5、10、20和50的数量
        bool index[5] = {false};  //分别代表1、5、10、20和50的出现与否
        //总是先找能够找的最大面额
        while (n >= 50) {
            a[0]++;
            n -= 50;
            index[0] = true;
        }
        while (n >= 20) {
            a[1]++;
            n -= 20;
            index[1] = true;
        }
        while (n >= 10) {
            a[2]++;
            n -= 10;
            index[2] = true;
        }
        while (n >= 5) {
            a[3]++;
            n -= 5;
            index[3] = true;
        }
        while (n >= 1) {
            a[4]++;
            n -= 1;
            index[4] = true;
        }
        for (int i = 0; i < 5; i++) {
            int count;
            if (i == 0) count = 50;
            if (i == 1) count = 20;
            if (i == 2) count = 10;
            if (i == 3) count = 5;
            if (i == 4) count = 1;
            if (index[i]) {  //若该面额出现,则输入"面额*数量"
                printf("%d*%d", count, a[i]);
                int j = i + 1;
                while (j < 5) {  //如果后面还有要找的面额,则输出一个'+'
                    if (index[j]) {
                        printf("+");
                        break;
                    }
                    j++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
