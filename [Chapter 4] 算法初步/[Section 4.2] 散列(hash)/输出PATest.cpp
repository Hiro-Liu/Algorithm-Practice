//B1043.

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    char s[10010];
    char dict[6] = {'P', 'A', 'T', 'e', 's', 't'};
    int hashTable[6] = {0};
    int sum = 0;  //待输出字符数
    cin >> s;
    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j < 6; j++) {  //遍历dict字典
            if (s[i] == dict[j]) {     //若包含于字典当中
                hashTable[j]++;        //对应字母的个数+1
                sum++;                 //待输出字符数+1
            }
        }
    }
    while (sum > 0) {
        for (int i = 0; i < 6; i++) {
            if (hashTable[i] > 0) {
                cout << dict[i];
                hashTable[i]--;  //个数-1
                sum--;           //待输出字符数-1
            }
        }
    }
    return 0;
}
