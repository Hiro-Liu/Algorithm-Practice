#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

//方式一：用f(x)=x^2且f(sqrt(2))=2做逼近
/*double f(double x) {
    return x * x;
}
int main() {
    const double eps = 1e-5;          //精度
    double left = 1, right = 2, mid;  //根号2在整数1和2之间
    while (right - left > eps) {
        mid = (left + right) / 2;
        if (f(mid) > 2)  // mid > 根号2
            right = mid;
        else  // mid < 根号2
            left = mid;
    }
    cout << mid << endl;
    return 0;
}*/

//方式二：相当于求f(x)=x^2-2在区间[1,2]上的根
double f(double x) {  //[0,+∞)的严格单增函数
    return x * x - 2;
}

int main() {
    const double eps = 1e-5;          //精度
    double left = 1, right = 2, mid;  //求区间[1,2]内方程的根
    while (right - left > eps) {
        mid = (left + right) / 2;
        if (f(mid) > 0)  // 根在左边
            right = mid;
        else  // 根在右边
            left = mid;
    }
    cout << mid << endl;
    return 0;
}
