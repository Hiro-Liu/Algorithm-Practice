#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 10010;

bool cmp(string x, string y) {
    return x + y < y + x;
}

int main() {
    int n;  //数字串个数
    cin >> n;
    string str[maxn];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    string ans;
    for (int i = 0; i < n; i++) {
        ans += str[i];
    }
    while (ans.length() != 0 && ans[0] == '0') {
        ans.erase(ans.begin());  //去除前导零
    }
    if (ans.length() == 0)  cout << 0 << endl;
    else                    cout << ans << endl;
    return 0;
}
