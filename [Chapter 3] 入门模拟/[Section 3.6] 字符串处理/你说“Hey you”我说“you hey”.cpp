#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1[100];
    char s2[100][100];
    int j = 0, k = 0;
    gets(s1);
    for (int i = 0, ; i < strlen(s1); i++) {
        if (s1[i] != ' ') {
            s2[j][k++] = s1[i];
        } else {
            s2[j][k] = '\0';
            j++;
            k = 0;
        }
    }
    for (int i = j; i >= 0; i--) {
        printf("%s", s2[i]);
        if (i > 0) {
            printf(" ");  //保证输出结尾没有空格
        }
    }
    return 0;
}
