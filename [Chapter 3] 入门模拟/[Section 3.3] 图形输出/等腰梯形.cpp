#include <stdio.h>

int main() {
    int m, h;  //m个case,高和上底边为h
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &h);
        int add = 2;                  //每行长度增量(需为正偶数)
        int max = h + (h - 1) * add;  //最长的长度(底边长)

        for (int i = 0; i < h; i++) {
            for (int j = (max - h - add * i) / 2; j > 0; j--) {
                printf(" ");
            }
            for (int j = h + i * add; j > 0; j--) {
                printf("*");
            }
            for (int j = (max - h - add * i) / 2; j > 0; j--) {
                printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}
