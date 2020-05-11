//写法一：若b为奇数,a^b=a*a^(b-1) —— b-1变为偶数
//若b为偶数,a^b=a^(b/2)*a^(b/2)
//最后可将b二分到0即b^0=1;然后依次回退计算

//写法二：假设b=13,其二进制为1101,则a^13=a^8+a^4+a^1
//令b不断右移(相当于b/2)最终b=0,迭代完成

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;

//写法一：二分和递归
LL binaryPow(LL a, LL b) {
    if (b == 0)  //边界条件
        return 1;
    if (b & 1)  //若b为奇数
        return a * binaryPow(a, b - 1);
    else {  //若b为偶数
        //这里之所以不写成binaryPow(a,b/2)* binaryPow(a,b/2)的原因跟
        // for循环的判断语句不能写strlen()一样,前者每次都用调用两遍
        // binaryPow函数会使复杂度由O(logb)->O(2^logb)=O(b)
        LL temp = binaryPow(a, b / 2);
        return temp * temp;
    }
}
//写法二：迭代
/*LL binaryPow(LL a, LL b) {
    LL ans = 1;
    while (b > 0) {
        if (b & 1) {  //若b的二进制末位为1(即b为奇数)
            ans = ans * a;
        }
        a = a * a;   //令a平方
        b = b >> 1;  // b右移一位,相当于b=b/2
    }
    return ans;
}*/

int main() {
    LL a, b, m;
    cin >> a >> b >> m;
    cout << binaryPow(a, b) % m;
    return 0;
}

