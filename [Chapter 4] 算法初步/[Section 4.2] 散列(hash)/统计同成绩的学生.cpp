//B1038.
/*********************************************************/

#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N, K, score, target;
    int hashTable[110] = {0};
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> score;
        hashTable[score]++;
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> target;
        cout << hashTable[target];
        if (i < K - 1)  cout << " ";
    }
    return 0;
}
