#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int Fibonacci(int n) {
    if (n == 0) return 0;        
    if (n == 1 || n == 2) return 1;              //递归边界                                        
    return Fibonacci(n - 1) + Fibonacci(n - 2);  //递归式
}

int main() {
    int m;  //样例数
    cin >> m;
    int n;  //行数
    while (m--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {               //第i行
            for (int j = 2 * (n - i); j > 0; j--) {  //第i行前面的2(n-i)个空格
                cout << " ";
            }
            for (int j = 2 * i - 1, k = 0; j > 0; j--, k++) {  //第i行的2i-1个数
                cout << Fibonacci(k) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
