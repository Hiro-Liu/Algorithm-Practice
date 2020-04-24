#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

void toLower(char& c) {
    c = (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

int main() {
    int hashTable[26] = {0};
    char s[1100];
    gets(s);
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        toLower(c);                  //转成小写字母
        if (c >= 'a' && c <= 'z') {  //若是字母
            hashTable[c - 'a']++;
        }
    }

    int index = 0;  //记录最大元素的下标
    for (int i = 1; i < 26; i++) {
        if (hashTable[i] > hashTable[index]) {
            index = i;  //记录下标,即记录是哪一个字母
        }
    }
    cout << char(index + 'a') << " " << hashTable[index];
    return 0;
}
