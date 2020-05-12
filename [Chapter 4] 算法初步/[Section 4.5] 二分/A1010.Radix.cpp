#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
LL Map[256];  //字符映射为十进制数

void init() {
    for (char c = '0'; c <= '9'; c++) {
        Map[c] = c - '0';  //将'0'~'9'映射为0~9
    }
    for (char c = 'a'; c <= 'z'; c++) {
        Map[c] = c - '0' + 10;  //将'a'~'z'映射为10~35
    }
}

LL toDecimal(string s, int radix) {
    LL ans = 0;
    int len = s.length();
    for (int i = len - 1, k = 0; i >= 0; i--, k++) {
        ans += pow(radix, k) * Map[s[i]];
    }
    return ans;
}

LL findLargestDigit(string n2) {
    int len = n2.length();
    int ans = Map[n2[0]];
    for (int i = 1; i < len; i++) {
        if (Map[n2[i]] > ans)
            ans = Map[n2[i]];
    }
    return ans + 1;  //返回进制数底线为最大数位+1
}

LL binarySearch(string n2, LL left, LL right, LL decimal) {
    LL mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        LL temp = toDecimal(n2, mid);
        if (temp == decimal)
            return mid;
        else if (temp > decimal)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;  //找不到答案
}

int main() {
    string n1, n2;
    LL tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2)  //保证总是N1的radix已知
        swap(n1, n2);
    init();                             //映射字符到Map[]
    LL decimal = toDecimal(n1, radix);  //计算n1的十进制数
    LL left = findLargestDigit(n2);     //下界为n2可能的最小进制
    LL right = max(left, radix) + 1;    //上界为n2进制与下界较大值+1
    LL ans = binarySearch(n2, left, right, decimal);  //二分查找目标进制数
    if (ans == -1)
        printf("Impossible");
    else
        printf("%lld\n", ans);
    return 0;
}
