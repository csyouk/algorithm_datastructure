
// 문제 번호 : [TST]쇠막대기
#if 0
#include <stdio.h>
#define MAX 100010
char d[MAX];

int main(void)
{
	// 여기서부터 작성
	int sum = 0, stick = 0;
	freopen("in.txt", "r", stdin);

	scanf("%s", &d[1]);
	fflush(stdin);

	for (int i = 1; i < MAX; i++){
		if (d[i] == 0) break;
		if (d[i] == '(') stick++;
		if (d[i] == ')') stick--;
		if (d[i - 1] == '(' && d[i] == ')'){
			sum += stick;
		}
		if (d[i - 1] == ')' && d[i] == ')'){
			sum++;
		}
	}

	printf("%d", sum);
	return 0;
}
#endif
