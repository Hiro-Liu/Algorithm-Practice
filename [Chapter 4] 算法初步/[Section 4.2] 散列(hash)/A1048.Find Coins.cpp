#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N, M, num;
    int hashTable[100100] = {0};  //用来记录每个数字的出现个数
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        hashTable[num]++;
    }
    int count = 0;
    for (int i = 0; i < M; i++) {
        if (hashTable[i] > 0 && hashTable[M - i] > 0) {
            if (i == M - i && hashTable[i] < 2) {
                continue;
            }
            printf("%d %d", i, M - i);
            return 0;
        }
    }
    printf("NO Solution");
    return 0;
}
