#include <math.h>
#include <stdio.h>
#include <string.h>
const int max = 1000;

int main() {
    char s[110];
    char a[110];
    char b[110];
    char ans[max][110];
    while (gets(s) != NULL) {
        scanf("%s", a);
        scanf("%s", b);
        getchar();  //吸收回车

        //分块，把每个单词都存到一个字符串内
        int row = 0, k = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] != ' ') {
                ans[row][k++] = s[i];
            } else {
                ans[row][k] = '\0';  //字符串结尾
                row++;
                k = 0;
            }
        }
        ans[row][k] = '\0';

        //替换,a——>b
        for (int i = 0; i <= row; i++) {
            if (!strcmp(ans[i], a))
                strcpy(ans[i], b);
        }

        //输出，打印替换后的字符串
        for (int i = 0; i <= row; i++) {
            printf("%s", ans[i]);
            if (i < row) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
