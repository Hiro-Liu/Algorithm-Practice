#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct mooncake {
    double store;  //库存
    double sell;   //总价
    double price;  //单价
} cake[1000];

//排序规则,按单价降序排列
bool cmp(mooncake x, mooncake y) {
    return x.price > y.price;
}

int main() {
    int type;     //月饼种类
    double need;  //市场需求量
    cin >> type >> need;
    for (int i = 0; i < type; i++) {  //库存输入
        cin >> cake[i].store;
    }
    for (int i = 0; i < type; i++) {  //输入总价,计算单价
        cin >> cake[i].sell;
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake, cake + type, cmp);     //按单价降序排列
    double sum = 0;                   //总的最大利润
    for (int i = 0; i < type; i++) {  //输入总价,计算单价
        if (cake[i].store >= need) {
            sum += cake[i].price * need;
            printf("%.2lf\n", sum);
            return 0;
        } else {
            sum += cake[i].sell;
            need -= cake[i].store;
        }
    }
}
