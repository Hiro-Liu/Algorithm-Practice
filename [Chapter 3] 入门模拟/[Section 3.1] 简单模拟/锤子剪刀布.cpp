/****************************************************************************************/
//注：scanf键入char型变量，一次输入结束的回车是会被下一次scanf捕捉
//所以scanf后面的getchar()非常重要，缺少会导致答案错误(WA)
/****************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>

//const int MAX = 1000;

int main()
{
	int N;
	scanf("%d", &N);
	getchar();  //吸收回车
	
	int win1 = 0, win2 = 0, draw = 0;
	int C1, J1, B1, C2, J2, B2; //两位选手C/J/B赢的次数
	C1 = J1 = B1 = C2 = J2 = B2 = 0;

	char state1, state2;
	for (int i = 0; i < N; i++) {
		scanf("%c %c", &state1, &state2);
		getchar();  //吸收回车
		if (state1 == 'C') {
			if (state2 == 'C') draw++;
			else if (state2 == 'J') { win1++; C1++; }
			else if (state2 == 'B') { win2++; B2++; }		
		}
		else if (state1 == 'J') {
			if (state2 == 'J') draw++;
			else if (state2 == 'B') { win1++; J1++; }
			else if (state2 == 'C') { win2++; C2++; }
		}
		else if (state1 == 'B') {
			if (state2 == 'B') draw++;
			else if (state2 == 'C') { win1++; B1++; }
			else if (state2 == 'J') { win2++; J2++; }
		}
	}

	char best_state1 = (C1 >= J1) ? ((C1 <= B1) ? 'B' : 'C') : ((J1 <= B1) ? 'B' : 'J');
	char best_state2 = (C2 >= J2) ? ((C2 <= B2) ? 'B' : 'C') : ((J2 <= B2) ? 'B' : 'J');
	
	printf("%d %d %d\n", win1, draw, N - win1 - draw);
	printf("%d %d %d\n", win2, draw, N - win2 - draw);
	printf("%c %c", best_state1, best_state2);
	
	return 0;
}
