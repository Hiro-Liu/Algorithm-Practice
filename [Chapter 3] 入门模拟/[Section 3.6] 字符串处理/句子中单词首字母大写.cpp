#include <stdio.h>
#include <string.h>

int main() {
    char s[110];
    while (gets(s) != NULL) {
        s[0] = (s[0] >= 'a' && s[0] <= 'z') ? (s[0] - 32) : s[0];
        for (int i = 1; i < strlen(s); i++) {
            s[i] = (s[i - 1] == ' ' && s[i] >= 'a' && s[i] <= 'z') ? (s[i] - 32) : s[i];
        }
        printf("%s\n", s);
    }
    return 0;
}
