#include <stdio.h>
#include <string.h>

//遍历数据前一半，比较对称位置，若有不同，则非“回文串”，直接返回false即可。
bool cmp(char s1[]) {
    int len = strlen(s1);
    for (int i = 0; i < len / 2; i++) {
        if (s1[i] != s1[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char s1[250];
    scanf("%s", s1);
    if (cmp(s1)) {
        printf("YES");  //是回文串
    } else {
        printf("NO");   //非回文串
    }
    return 0;
}
