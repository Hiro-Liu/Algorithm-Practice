#include <math.h>
#include <stdio.h>

const int maxn = 10010;
const double pi = acos(-1.0);
const double eps = 1e-5;

//函数ratio=f(h)
double f(double R, double h) {
    double alpha = 2 * acos((R - h) / R);
    double L = 2 * sqrt(R * R - (R - h) * (R - h));
    double S1 = alpha * R * R / 2 - L * (R - h) / 2;
    double S2 = pi * R * R / 2;
    return S1 / S2;
}
double binarySearch(double R, double ratio) {
    double left = 0, right = R, h;
    while (right - left > eps) {
        h = (left + right) / 2;
        if (f(R, h) > ratio)  //说明高度h过大
            right = h;
        else
            left = h;
    }
    return h;
}
int main() {
    double R, ratio;
    scanf("%lf %lf", &R, &ratio);
    printf("%.4f", binarySearch(R, ratio));
    return 0;
}
