#include <stdio.h>
#include <string.h>

//转成小写字母
void toLowercase(char aim[]) {
    for (int i = 0; i < strlen(aim); i++)
        aim[i] = (aim[i] >= 65 && aim[i] <= 90) ? (aim[i] + 32) : aim[i];
}

int main() {
    char aim[200];
    char s[1000];
    char ans[1000];
    gets(aim);
    toLowercase(aim);
    int len = strlen(aim);
    while (gets(s) != NULL) {
        int k = 0;
        for (int i = 0; i < strlen(s); i++) {
            //当前字符与aim首字母相同->开始判断长度为len的字串与aim是否相同
            if (s[i] == aim[0] || s[i] + 32 == aim[0]) {
                bool equal = true;
                for (int j1 = 0, j2 = i; j1 < len; j1++, j2++) {
                    //有字符不同，直接跳出并正常录入
                    if (s[j2] != aim[j1] && s[j2] + 32 != aim[j1]) {  
                        equal = false;
                        break;
                    }
                }
                if (equal)  i += len - 1;  //子串相同，则跳过这个字串所在部分不予录入
                else  ans[k++] = s[i];     //子串不同，正常录入
            }
            
            //当前字符与aim首字母不同，则除去空格外正常录入
            else {
                if (s[i] != ' ')  ans[k++] = s[i];  
            }
        }
        ans[k] = '\0';  //结束符
        printf("%s\n", ans);
    }
    return 0;
}
