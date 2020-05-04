#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct warehouse {
    int Java;          //房间的JavaavaBean数量
    int CatFood;       //房间需要的猫粮数量
    double UnitPrice;  //得失比
} room[1000];

bool cmp(warehouse x, warehouse y) {
    return x.UnitPrice > y.UnitPrice;
}

int main() {
    int M, N;  // M磅猫粮,N个房间
    while (cin >> M >> N, M != -1 && N != -1) {
        for (int i = 0; i < N; i++) {
            cin >> room[i].Java >> room[i].CatFood;
            room[i].UnitPrice = 1.0 * room[i].Java / room[i].CatFood;
        }
        sort(room, room + N, cmp);  //按得失比给房间排序
        double GainJavaBean = 0;
        for (int i = 0; i < N; i++) {    //总是先去得失比高的房间
            if (room[i].CatFood <= M) {  //若剩余猫粮够付所需猫粮
                GainJavaBean += room[i].Java;
                M -= room[i].CatFood;
            } else {  //若剩余猫粮不够所需猫粮
                GainJavaBean += M * room[i].UnitPrice;
                break;
            }
        }
        printf("%.3lf\n", GainJavaBean);
    }
    return 0;
}
