#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct Student {
    char id[20];
    int score = 0;
} stu[10010];

bool cmp(Student x, Student y) {
    if (x.score != y.score)
        return x.score > y.score;
    else
        return strcmp(x.id, y.id) > 0;
}

int main() {
    int person, problem_sum, line;  //考生数、题目数、分数线
    int group[10];                  //题目的分值
    int solve_sum, solve_num;       //做对的题数和题号
    while (cin >> person >> problem_sum >> line, person != 0) {
        int count = 0;                            //过线人数
        for (int i = 1; i <= problem_sum; i++) {  //输入每个题目的分值
            cin >> group[i];
        }
        for (int i = 0; i < person; i++) {  //输入并处理每个考生的信息
            cin >> stu[i].id >> solve_sum;
            for (int j = 0; j < solve_sum; j++) {
                cin >> solve_num;
                stu[i].score += group[solve_num];  //累加总分
            }
            if (stu[i].score >= line)  //达到分数线，则过线人数+1
                count++;
        }
        sort(stu, stu + person, cmp);
        cout << count << "\n";
        for (int i = 0; i < count; i++) {
            cout << stu[i].id << " " << stu[i].score << "\n";
        }
    }
    return 0;
}
