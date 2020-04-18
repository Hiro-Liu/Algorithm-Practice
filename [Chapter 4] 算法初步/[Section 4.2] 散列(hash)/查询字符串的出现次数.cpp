#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int hashFunc(char str[]) {
    int id = 0;  //当前字符串代表的十进制整数
    //以A~Z映射为0~25即26进制为例，id最高为26^strlen(str)-1
    //若长度为4则最高可达456976，故需要考虑计数数组count的长度是否足够
    for (int i = 0; i < strlen(str); i++) {
        id += (str[i] - 'A') * pow(25, i);
        // id = id * 26 + (str[i] - 'A');  使用这种转换方式也可以
    }
    return id;
}

int main() {
    int count[500010];
    memset(count, 0, sizeof(count));  //初始化出现次数为0
    char str[110], temp[110];
    int N, M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        count[hashFunc(str)]++;  //将字符串映射为一个整数并使相应数组元素++
    }
    scanf("%d", &M);  //查询字符串个数
    for (int i = 0; i < M; i++) {
        scanf("%s", temp);                      //输入查询字符串
        printf("%d\n", count[hashFunc(temp)]);  //打印该查询字符串出现的次数
    }
    return 0;
}
