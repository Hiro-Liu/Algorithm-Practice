//http://codeup.hustoj.com/problem.php?cid=100000585&pid=2

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 10010;
int n, m;  //数组长度和查找个数
int a[maxn];

string binarySearch(int a[], int x) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] == x)
            return "YES";
        else if (a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return "NO";
}

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);  //保证数组有序
        cin >> m;
        int x;  //要查找的数
        while (m--) {
            cin >> x;
            cout << binarySearch(a, x) << endl;
        }
    }
    return 0;
}
