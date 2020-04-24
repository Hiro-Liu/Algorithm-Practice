#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int hashTable[1000] = {0};  //下标：队号_元素值：总分数
    int N, team, member, score;  //参赛队员总数,队伍编号,队员编号,队员成绩
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d-%d %d", &team, &member, &score);
        hashTable[team] += score;
    }

    int index = 0;  //最高得分队伍的队号(即数组下标)
    for (int i = i; i < 1000; i++) {
        if (hashTable[i] > hashTable[index]) {
            index = i;
        }
    }
    cout << index << " " << hashTable[index];
    return 0;
}
