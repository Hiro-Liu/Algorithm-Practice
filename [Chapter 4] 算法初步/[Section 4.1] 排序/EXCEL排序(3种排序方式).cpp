#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Student {
    char id[10];
    char name[10];
    int score;
} stu[100010];

//非递减排序，即递增（由小到大）
bool cmp_C1(Student x, Student y) {
    return strcmp(x.id, y.id) < 0;
}

bool cmp_C2(Student x, Student y) {
    if (strcmp(x.name, y.name))
        return strcmp(x.name, y.name) < 0;
    else
        return strcmp(x.id, y.id) < 0;
}

bool cmp_C3(Student x, Student y) {
    if (x.score != y.score)
        return x.score < y.score;
    else
        return strcmp(x.id, y.id) < 0;
}

int main() {
    int N, C;  //学生数和排序方式
    int case_num = 1;
    while (scanf("%d %d", &N, &C), N != 0) {
        for (int i = 0; i < N; i++) {
            scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].score);
        }
        switch (C) {
            case 1: sort(stu, stu + N, cmp_C1); break;
            case 2: sort(stu, stu + N, cmp_C2); break;
            case 3: sort(stu, stu + N, cmp_C3); break;
        }
        printf("Case %d:\n", case_num++);
        for (int i = 0; i < N; i++) {
            printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].score);
        }
    }
    return 0;
}
