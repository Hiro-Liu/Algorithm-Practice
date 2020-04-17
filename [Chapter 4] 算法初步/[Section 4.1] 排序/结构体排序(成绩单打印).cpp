#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Student {
    char id[15];          //考号
    int score;            //分数
    int location_number;  //考场
    int local_rank;       //考场排名
} stu[10000];

bool cmp(Student a, Student b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0;
}

int main() {
    int testLocation;    //考场数
    int local_testee;    //考场内考生数
    int sum_testee = 0;  //考生总数
    scanf("%d", &testLocation);
    for (int i = 1; i <= testLocation; i++) {
        scanf("%d", &local_testee);  //考场内人数
        for (int j = 0; j < local_testee; j++) {
            scanf("%s %d", stu[sum_testee].id, &stu[sum_testee].score);  //录入考号和成绩
            stu[sum_testee].location_number = i;  //考场号
            sum_testee++;  //总考生数递增
        }
        sort(stu + sum_testee - local_testee, stu + sum_testee, cmp);  //按照cmp函数的规则对该考场学生排序
        stu[sum_testee - local_testee].local_rank = 1;  //第一个学生的排名为1

        for (int j = sum_testee - local_testee + 1; j < sum_testee; j++) {  //当前考场的排名情况
            if (stu[j].score == stu[j - 1].score)
                stu[j].local_rank = stu[j - 1].local_rank;
            else
                stu[j].local_rank = j + 1 - (sum_testee - local_testee);
        }
    }
    sort(stu, stu + sum_testee, cmp);  //按照cmp函数的规则对所有学生排序
    printf("%d\n", sum_testee);        //打印总人数
    int rank = 1;
    for (int i = 0; i < sum_testee; i++) {  //所有学生的排名情况,并打印成绩单
        if (i > 0 && stu[i].score != stu[i - 1].score) {
            rank = i + 1;
        }
        printf("%s ", stu[i].id);
        printf("%d %d %d\n", rank, stu[i].location_number, stu[i].local_rank);
    }
    return 0;
}
