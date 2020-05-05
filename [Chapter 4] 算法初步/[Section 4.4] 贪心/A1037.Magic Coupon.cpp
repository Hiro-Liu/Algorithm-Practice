#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 100010;
int coupon[maxn], product[maxn];

int main() {
    int Nc, Np;  // coupon数量,product数量
    cin >> Nc;
    for (int i = 0; i < Nc; i++) {
        cin >> coupon[i];
    }
    cin >> Np;
    for (int i = 0; i < Np; i++) {
        cin >> product[i];
    }
    sort(coupon, coupon + Nc);    //升序排列
    sort(product, product + Np);  //升序排列
    long long ans = 0;            //避免乘积之和过大导致越界
    for (int i = 0; i < Nc && i < Np && coupon[i] < 0 && product[i] < 0; i++) {
        ans += coupon[i] * product[i];
    }
    for (int i = Nc - 1, j = Np - 1;
         i >= 0 && j >= 0 && coupon[i] > 0 && product[j] > 0; i--, j--) {
        ans += coupon[i] * product[j];
    }
    cout << ans << endl;
    return 0;
}
