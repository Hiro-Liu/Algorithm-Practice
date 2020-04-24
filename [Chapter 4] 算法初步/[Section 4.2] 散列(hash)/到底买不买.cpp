#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    char seller[1100];
    char buyer[1100];
    int need[128] = {0};
    cin >> seller >> buyer;
    int lack = 0;  //缺少的珠子数
    for (int i = 0; i < strlen(buyer); i++) {
        need[buyer[i]]++;  //累计各种珠子的需求数
        lack++;            //累计总缺少数
    }

    int rest = strlen(seller);  //多余的珠子数
    for (int i = 0; i < strlen(seller); i++) {
        if (need[seller[i]] != 0) {  //若有需求
            need[seller[i]]--;  //补充一个需求,需求减一,缺少减一
            rest--;
            lack--;
        }
    }

    if (lack == 0) {  //若没有缺少珠子,输出多了多少珠子
        cout << "Yes " << rest;
    } else {  //若缺少珠子,输出缺了几颗
        cout << "NO " << lack;
    }
    return 0;
}
