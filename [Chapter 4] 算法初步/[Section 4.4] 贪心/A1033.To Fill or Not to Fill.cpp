#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct Gas_Station {
    double Price;
    double Distance;
} S[10010];

bool cmp(Gas_Station x, Gas_Station y) {
    return x.Distance < y.Distance;
}

int main() {
    int N;                 //加油站数量
    double Cmax, D, Davg;  //油箱容量,总路程,单位油量能跑的距离
    while (cin >> Cmax >> D >> Davg >> N) {
        for (int i = 0; i < N; i++) {
            cin >> S[i].Price >> S[i].Distance;
        }
        //把终点也当作一个加油站
        S[N].Distance = D;
        S[N].Price = 0;
        sort(S, S + N, cmp);
        if (S[0].Distance != 0) {
            cout << "The maximum travel distance = 0.00" << endl;
        }
        else {
            int now = 0;  //当前所在加油站的编号
            //总花费,当前油量,满油能行驶的最大路程,
            double cost = 0, tank = 0, Max = Cmax * Davg;
            while (now < N) {  //到达终点前
                //在满油状态下能到达的所有加油站范围内寻找价格最低的加油站
                //若范围内没有加油站比当前加油站价格更低,则选择里面价格较低的
                double Min_Price = INFINITY;
                int k = -1;  //选中的目标加油站
                for (int i = now + 1;
                     i <= N && Max >= S[i].Distance - S[now].Distance; i++) {
                    //找到范围内油价较低的k
                    if (S[i].Price < Min_Price) {
                        Min_Price = S[i].Price;
                        k = i;
                    }
                    //若k油价比当前加油站油价还低,直接退出循环
                    if (Min_Price < S[now].Price)  break;
                }
                if (k == -1)  break;  //范围内无法到达任何加油站,也就无法到达终点

                //出发去k加油站
                // need为now到k所需油量
                double need = (S[k].Distance - S[now].Distance) / Davg;
                if (S[k].Price < S[now].Price) {  // k价格比now低
                    if (tank >= need) {           //若当前油量足够到k
                        tank -= need;             //到达k,消耗相应油量
                    } else {  //若当前油量无法到k,则仅加恰好能到k的油量
                        cost += (need - tank) * S[now].Price;
                        tank = 0;  //到达k,油量为0
                    }
                } else {                                   // k价格比now高
                    cost += (Cmax - tank) * S[now].Price;  //加满油
                    tank = Cmax - need;  //到达k,消耗相应油量
                }
                now = k;  //到达k加油站
            }

            //成功到达终点则输出cheapest cost,否则输出能到达的最远距离
            if (now == N)   printf("%.2lf\n", cost);
            else            printf("The maximum travel distance = %.2lf\n", S[now].Distance + Max);
        }
    }
    return 0;
}
