/**************************************************************/
//strlen函数的内部实现是使用一个循环扫描数组来累计长度，直到'\0'结束
//所以strlen本身就有O(N)的复杂度，在套上N重for循环直接将遍历字符串的复杂度
//从O(N)上升到了O(N^2)导致超时。所以strlen一定要在for循环之前就计算好。
//本人之前的代码一直是吧strlen写进了for的判断语句内，写顺手了一直没有发现
//这个严重的问题，好在现在是学生阶段，没有因为此造成工程上的故障。
/**************************************************************/
#include <stdio.h>
#include <string.h>

int main() {
    bool hashTable[128] = {false};  // false代表s2中没有,true代表有
    char s1[10010], s2[10010];
    gets(s1);
    gets(s2);
    int len1 = strlen(s1);  // strlen必须在for循环之前就计算
    int len2 = strlen(s2);
    for (int i = 0; i < len2; i++) {
        hashTable[s2[i]] = true;  // s2[i]要在s1中删除
    }

    for (int i = 0; i < len1; i++) {
        if (hashTable[s1[i]] == false) {  //不删则输出
            printf("%c", s1[i]);
        }
    }
    return 0;
}
