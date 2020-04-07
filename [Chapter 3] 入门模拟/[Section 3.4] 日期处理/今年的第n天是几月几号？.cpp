#include <stdio.h>

int month[13][2] = {{0, 0},   {31, 31}, {28, 29}, {31, 31}, {30, 30},
                    {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30},
                    {31, 31}, {30, 30}, {31, 31}};  //平年和闰年每个月的天数

bool isLeap(int year) {  //判断是否是闰年
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int y, n;
    while (scanf("%d %d", &y, &n) != EOF) {
        int m = 1, day = 0;
        while (n--) {
            day++;
            if (day == month[m][isLeap(y)] + 1) {
                day = 1;
                m++;
            }
        }
        printf("%04d-%02d-%02d\n", y, m, day);
    }
    return 0;
}
