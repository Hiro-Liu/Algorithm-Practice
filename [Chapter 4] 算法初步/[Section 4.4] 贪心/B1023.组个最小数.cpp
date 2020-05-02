#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int hashTable[10];  //数字0~9的个数
    for (int i = 0; i <= 9; i++) {
        cin >> hashTable[i];
    }
    for (int i = 1; i <= 9; i++) {  //先输出存在的最小非0数
        if (hashTable[i] > 0) {
            cout << i;
            hashTable[i]--;
            break;
        }
    }
    for (int i = 0; i <= 9; i++) {  //剩下的升序输出
        while (hashTable[i] != 0) {
            cout << i;
            hashTable[i]--;
        }
    }
    return 0;
}
