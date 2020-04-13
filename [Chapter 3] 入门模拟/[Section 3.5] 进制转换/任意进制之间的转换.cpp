/*********************************************************/
//Example：
//input：4 123 10
//output：27
/*********************************************************/
#include <math.h>
#include <stdio.h>
#include <string.h>

int a, b;         //转换前后的进制数
char n[30];       //待转换数
int decimal = 0;  //待转换数的十进制形式
char result[30];  //转换结果

void other2dec() {
    for (int i = strlen(n) - 1, j = 0; i >= 0; i--) {
        // n[i]∈[0,9]
        if (n[i] >= '0' && n[i] <= '9') {
            decimal += (n[i] - '0') * pow(a, j++);
        }
        // n[i]∈[a,f]
        else if (n[i] >= 'a' && n[i] <= 'f') {
            decimal += (n[i] - 'a' + 10) * pow(a, j++);
        }
        // n[i]∈[A,F]
        else {
            decimal += (n[i] - 'A' + 10) * pow(a, j++);
        }
    }
}

void dec2other() {
    int i = 0;
    int rest;  //余数
    do {
        rest = decimal % b;
        result[i++] = (rest < 10) ? (rest + '0') : (rest - 10 + 'A');
        decimal /= b;
    } while (decimal != 0);
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", result[j]);
    }
    printf("\n");
}

int main() {
    while (scanf("%d %s %d", &a, n, &b) != EOF) {
        other2dec();
        dec2other();
    }
    return 0;
}
