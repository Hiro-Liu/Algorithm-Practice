#include <stdio.h>

int month[13][2] = {{0, 0},   {31, 31}, {28, 29}, {31, 31}, {30, 30},
                    {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30},
                    {31, 31}, {30, 30}, {31, 31}};  //平年和闰年每个月的天数

bool isLeap(int year) {  //判断是否是闰年
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        int y, m, d;
        scanf("%d %d %d", &y, &m, &d);
        d++;
        if (d == month[m][isLeap(y)] + 1) {
            d = 1;
            m++;
        }
        if (m == 13) {
            m = 1;
            y++;
        }
        printf("%04d-%02d-%02d\n", y, m, d);
    }
    return 0;
}
