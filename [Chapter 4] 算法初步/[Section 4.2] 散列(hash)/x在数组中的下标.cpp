//http://codeup.hustoj.com/problem.php?cid=100000585&pid=0
//本题是二分法部分的习题,但由于数组无序,暂时没有想到恰当的二分写法
//用hash的思想就可以很轻松的解决

#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 10010;
int n;  //数组长度
int a[maxn];

int main() {
    int hashTable[maxn];
    while (cin >> n) {
        memset(hashTable, -1, sizeof(hashTable));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            hashTable[a[i]] = i;  //储存下标
        }
        int x;  //要找的数
        cin >> x;
        if (hashTable[x] > -1)
            cout << hashTable[x] << endl;  //输出下标
        else
            cout << -1 << endl;  //查无此数
    }
    return 0;
}
