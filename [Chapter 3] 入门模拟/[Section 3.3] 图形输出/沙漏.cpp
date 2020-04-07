#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j > 0; j--) {
                printf(" ");
            }
            for (int j = n - i; j > 0; j--) {
                printf("* ");
            }
            printf("\n");
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 2 - i; j > 0; j--) {
                printf(" ");
            }
            for (int j = 2 + i; j > 0; j--) {
                printf("* ");
            }
            printf("\n");
        }
    }
    return 0;
}
