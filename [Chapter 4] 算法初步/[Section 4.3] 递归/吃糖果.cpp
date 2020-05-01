//递归式：f(N)=f(N-1)+f(N-2),n>=3
//递归边界：f(1)=1,f(2)=2

#include <stdio.h>

int Plan(int n) {
    if (n == 1) return 1;  //如果就1块巧克力,则只有1种方案      
    if (n == 2) return 2;  //如果有2块巧克力,则有2种方案    
    //如果巧克力是三块或以上
    return Plan(n - 1) + Plan(n - 2);
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        printf("%d\n", Plan(N));
    }
    return 0;
}
