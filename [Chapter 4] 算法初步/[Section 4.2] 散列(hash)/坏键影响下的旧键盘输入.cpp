//思路：将128个ASCII码值全部赋True; 枚举所有坏键,将坏键的hash值置为false
//最后枚举应该输入的串,若当前字符的hash值为True,则说明是好键,输出即可
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    char broken[80];      //坏掉的键,对应字母给出大写
    char str[80];         //应该得到的字符串
    bool hashTable[128];  // true代表好键,false代表坏键
    memset(hashTable, true, sizeof(hashTable));
    gets(broken);
    gets(str);
    for (int i = 0; i < strlen(broken); i++) {
        int c = broken[i];
        hashTable[c] = false;  //标记坏键
        if (c >= 65 && c <= 90) hashTable[c + 32] = false;  //标记小写字母 
    }
    for (int i = 0; i < strlen(str); i++) {
        if (hashTable[str[i]] == true) {  //若是好键
            //若上档键坏掉,且为大写字母,do nothing(不予输出)
            if (hashTable['+'] == false && str[i] >= 65 && str[i] <= 90) {} 
            else cout << str[i];
        }
    }
    return 0;
}
