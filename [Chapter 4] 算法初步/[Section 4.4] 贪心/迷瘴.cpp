#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int C;  // C组输入数据
    cin >> C;
    int n, V, W;  //药水种类,每种药水的体积,解药的最大浓度
    int P[110];   //每种药水的浓度Pi
    while (C--) {
        cin >> n >> V >> W;
        for (int i = 0; i < n; i++) {
            cin >> P[i];
        }
        sort(P, P + n);  //浓度从小到大排序
        if (P[0] > W) {  //若浓度最小的药水都掺不进去,则调制不出解药
            printf("0 0.00\n");
            continue;  //进入下一轮数据输入
        }
        //若可以调配出解药,往下继续掺入,欲求得解药最大体积
        int ans_V = V;
        double ans_W = P[0];
        for (int i = 1; i < n; i++) {
            //若掺入该药水后的浓度不超过最大浓度,就掺入
            //若掺入该药水后的浓度超过了最大浓度,停止掺入
            double temp_W = (ans_W * ans_V + P[i] * V) / (ans_V + V);
            if (temp_W <= W) {
                ans_W = temp_W;
                ans_V += V;
            } else
                break;
        }
        ans_W *= 0.01;
        printf("%d %.2lf\n", ans_V, ans_W);
    }
    return 0;
}
