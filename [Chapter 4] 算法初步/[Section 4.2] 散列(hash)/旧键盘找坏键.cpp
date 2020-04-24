//思路：输入好键盘应该能够输入得到的字符串before和坏键盘实际输入得到的字符串after
//枚举after，每个出现的字符使其Hash值为true
//枚举before，检查每个字符的Hash值是否是true，若不是，则说明before[i]在after中没有出现，即为坏键
//注意：输出坏键后，需要将坏键的Hash值赋true，防止之后有同样的字符(坏键)造成重复输出
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

void toCapital(char& s) {
    s = (s >= 97 && s <= 122) ? s - 32 : s;
}

int main() {
    char before[80];
    char after[80];
    bool hashTable[128] = {false};  // ASCII码的个数128个
    gets(before);
    gets(after);
    for (int i = 0; i < strlen(after); i++) {
        toCapital(after[i]);
        hashTable[after[i]] = true;
    }
    for (int i = 0; i < strlen(before); i++) {
        toCapital(before[i]);
        if (hashTable[before[i]] == false)  //这个字符没有在之后输出，则是坏的
            cout << before[i];        //输出坏键
        hashTable[before[i]] = true;  //防止坏键多次输出
    }
    return 0;
}


//参考代码：
//解题思路：枚举before，对before里的每一个字符枚举after，如果字符相等则说明此键没坏，跳出即可
//若after完全枚举过也没有出现before的这个字符，则说明此键已坏，输出该坏键，同时哈希表为true防止多次输出坏键
/*int main() {
    char before[80];
    char after[80];
    bool hashTable[128] = {false};  // ASCII码的个数128个
    gets(before);
    gets(after);
    for (int i = 0; i < strlen(before); i++) {
        int j;
        char c1, c2;
        for (j = 0; j < strlen(after); j++) {
            c1 = before[i];
            c2 = after[j];
            toCapital(c1);
            toCapital(c2);
            if (c1 == c2) break;               
        }
        if (j == strlen(after) && hashTable[c1] == false){  //这个字符没有在之后输出，则是坏的        
            cout << c1;              //输出坏键
        }
        hashTable[c1] = true;  //防止坏键多次输出
    }
    return 0;
}*/
