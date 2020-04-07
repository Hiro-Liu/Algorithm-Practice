#include <stdio.h>

int month[13][2] = {{0, 0},   {31, 31}, {28, 29}, {31, 31}, {30, 30},
                    {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30},
                    {31, 31}, {30, 30}, {31, 31}};  //平年和闰年每个月的天数

bool isLeap(int year) {  //判断是否是闰年
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int time1, year1, month1, day1;
    int time2, year2, month2, day2;
    while (scanf("%d %d", &time1, &time2) != EOF) {
        if (time1 > time2) {  //保证第二个日期更晚
            int temp = time1;
            time1 = time2;
            time2 = temp;
        }
        year1 = time1 / 10000, month1 = time1 / 100 % 100, day1 = time1 % 100;
        year2 = time2 / 10000, month2 = time2 / 100 % 100, day2 = time2 % 100;
        int count = 1;
        while (year1 != year2 || month1 != month2 || day1 != day2) {  //只要年月日有一个不相同
            day1++;
            if (day1 == month[month1][isLeap(year1)] + 1) {  // day++后是否超出限制
                day1 = 1;
                month1++;
            }
            if (month1 == 13) {  // month++是否超出限制
                month1 = 1;
                year1++;
            }
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
