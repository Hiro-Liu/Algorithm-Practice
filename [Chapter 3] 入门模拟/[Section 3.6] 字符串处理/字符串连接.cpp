#include <stdio.h>
#include <string.h>
//solution 1
/*int main() {
    char s1[220];
    char s2[110];
    while (scanf("%s %s", s1, s2) != EOF) {
        int len = strlen(s1);
        for (int i = 0; i < strlen(s2); i++) {
            s1[len++] = s2[i];
        }
        s1[len] = '\0';  //写上结尾，防止后面未输入而乱码
        printf("%s\n", s1);
    }
    return 0;
}*/

//solution 2
/*int main() {
    char s1[220];
    while (scanf("%s", s1) != EOF) {
        getchar();  //防止空格被下个scanf读入
        int len = strlen(s1);
        char c;
        while (scanf("%c", &c), c != '\n') {
            s1[len++] = c;
        }
        s1[len] = '\0';  //写上结尾，防止后面未输入而乱码
        printf("%s\n", s1);
    }
    return 0;
}*/

//solution 3
int main() {
    char s1[220];
    while (scanf("%s", s1) != EOF) {
        scanf("%s", &s1[strlen(s1)]);
        printf("%s\n", s1);
    }
    return 0;
}
