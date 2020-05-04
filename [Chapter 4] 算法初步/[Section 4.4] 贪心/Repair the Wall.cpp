#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    int GapLength, BlockNum;
    int BlockSize[600];
    while (cin >> GapLength >> BlockNum) {
        int BlockLengthSum = 0;
        for (int i = 0; i < BlockNum; i++) {
            cin >> BlockSize[i];
            BlockLengthSum += BlockSize[i];
        }
        sort(BlockSize, BlockSize + BlockNum, cmp);
        if (BlockLengthSum < GapLength) {
            cout << "impossible" << endl;
        } else {
            int Length = 0;
            for (int i = 0; i < BlockNum; i++) {
                Length += BlockSize[i];
                if (Length >= GapLength) {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
