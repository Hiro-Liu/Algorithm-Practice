#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;


int main() {
    int reader[220];  //下标:读者i;元素值:喜欢的书编号
    int bookId[220];  //下标:书编号;元素值:被喜欢的次数
    int N, M;
    while (cin >> N >> M) {
        memset(bookId, 0, sizeof(bookId));
        for (int i = 0; i < N; i++) {
            cin >> reader[i];     //第i个读者最喜欢的图书编号
            bookId[reader[i]]++;  //编号+1
        }
        for (int i = 0; i < N; i++) {
            if (bookId[reader[i]] == 1)  //这本书只有他自己喜欢
                cout << "BeiJu" << "\n";
            else
                cout << bookId[reader[i]] - 1 << "\n";
        }
    }
    return 0;
}
