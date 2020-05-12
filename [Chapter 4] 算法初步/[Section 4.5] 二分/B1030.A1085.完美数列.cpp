#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 10010;

int main() {
    int N, p, a[maxn];
    cin >> N >> p;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);
    long long x = a[0] * p;
    //upper_bound返回第一个大于x的元素的地址,减去数值首地址得到其下标
    cout << upper_bound(a, a + N, x) - a;
    return 0;
}
