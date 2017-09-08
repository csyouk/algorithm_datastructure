#define _CRT_SECURE_NO_WARNINGS
// ���� ��ȣ : [TST]ȸ�� �ʹ�(��)
#if 0
#include <stdio.h>
#define DISH 30000 + 10
#define SUSHI 3000 + 10
#define EMPTY 0
#define GIVE 1
#define COLLECT 0

int dish[DISH], sushi[SUSHI], given[DISH];
int N, d, k, c, cnt, max=0x80000000;

int main(void){

	freopen("in.txt", "r", stdin);
	int i, j, prev = 0;
	scanf("%d %d %d %d", &N, &d, &k, &c);
	for (i = 1; i <= N; i++) scanf("%d", &dish[i]);

	sushi[c]++; cnt++;
	for (i = 1; i <= N; i++)
	{
		if (prev){
			if (prev < N+1){
				sushi[dish[prev]]--;
				given[prev] = COLLECT;
				if (sushi[dish[prev]] == EMPTY) cnt--;
			}else{
				sushi[dish[prev % N + 1]]--;
				given[prev % N + 1] = COLLECT;
				if (sushi[dish[prev % N + 1]] == EMPTY) cnt--;
			}
		}

		for ( j = i; j < i+k; j++)
		{
			if (j < N+1){
				if (sushi[dish[j]] == EMPTY) cnt++;
				if (given[j]) continue;
				sushi[dish[j]]++;
				given[j] = GIVE;
			}
			else{
				if (sushi[dish[j % N]] == EMPTY) cnt++;
				if (given[j]) continue;
				sushi[dish[j % N]]++;
				given[j] = GIVE;
			}
		}

		// ���� �� �ִ� ȸ���ʹ� ���� ����.
		if (max < cnt) max = cnt;

		prev = i;
	}

	printf("%d", max);

	return 0;
}
#endif

// ȸ���ʹ�. rabin-karp�� ����� ���̵���.
#if 0
/*
ȸ�� �ʹ� ���������� ȸ���ϴ� ��Ʈ ���� ���� ���� ������ 
�ʹ��� ���ÿ� ��� ���� �ְ�, �մ��� �� �߿��� �ڱⰡ �����ϴ� 
�ʹ��� ��� �Դ´�. �ʹ��� ������ ��ȣ�� ǥ���� ��, 
���� �׸��� ȸ�� �ʹ� �������� ��Ʈ ������ ���� �����ְ� �ִ�. 
��Ʈ ������ ���� ������ �ʹ��� �� �̻� ���� �� �ִ�.
���� ���� �� ȸ�� �ʹ� �������� �Ұ��� ������ �������, 
������ ���� �� ���� ��縦 ���ؼ� �Ż��� �ø����� �Ѵ�.
1. ���� ȸ�� �ʹ��� �մ��� ������� �ʹ��� ����, ���� �ʹ丸ŭ 
�Ĵ븦 ���������, ��Ʈ�� ������ �� ��ġ���� k���� ���ø� �����ؼ� 
���� ��� ���ε� ���� �������� �����Ѵ�.
2. �� ������ �ʹ��� ���� �ϳ��� ���� ������ �����ϰ�, 
1�� ��翡 ������ ��� �� ������ ������ ������ �ʹ� �ϳ��� 
�߰��� ����� �����Ѵ�. ���� �� ��ȣ�� ������ �ʹ��� ���� 
��Ʈ ���� ���� ���, �丮�簡 ���� ����� �մԿ��� �����Ѵ�.
�� ���� ��翡 �����Ͽ� ������ �� �پ��� ������ �ʹ��� �������� �Ѵ�.
�� �׸��� ���� ������ �����غ���. k=4�̰�, 30�� �ʹ��� �������� 
�޾Ҵٰ� ��������. 
������ ������� ������ 4���� �ٸ� �ʹ��� ���� �� �ִ� ���� 
(9, 7, 30, 2), (30, 2, 7, 9), (2, 7, 9, 25) �� ���� ��찡 �ִµ�, 
30�� �ʹ��� �߰��� �������� ���� �� �����Ƿ� (2, 7, 9, 25)�� ���� 
5���� ������ �ʹ��� ���� �� �ִ�.
ȸ�� �ʹ� �������� ��Ʈ ����, �޴��� �ִ� �ʹ��� ������, 
�����ؼ� �Դ� ������ ����, ���� ��ȣ�� �־����� ��, �մ��� ���� �� �ִ�
�ʹ� �������� �ִ밪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
�Է��� ù ��° �ٿ��� ȸ�� �ʹ� ��Ʈ�� ���� ������ �� N, �ʹ��� ������ d, �����ؼ� �Դ� ������ �� k, ���� ��ȣ c�� ���� �ϳ��� �� ĭ�� ���̿� �ΰ� �־�����. ��, 2��N��30,000, 2��d��3,000, 2��k��3,000 (k��N), 1��c��d�̴�. �� ��° �ٺ��� N���� �ٿ��� ��Ʈ�� �� ��ġ���� �����Ͽ� ȸ�� ������ ���� �� �ʹ��� ������ ��Ÿ���� 1 �̻� d ������ ������ �� �ٸ��� �ϳ��� �־�����.
���
�־��� ȸ�� �ʹ� ��Ʈ���� ���� �� �ִ� �ʹ��� �������� �ִ밪�� �ϳ��� ������ ����Ѵ�.
*/

// �� ������ ���̵��� k���� �ʹ信 ���ؼ� �̸� ����� �� ���� ��
// ���� �ϳ��� �ʹ��� �߰��ϸ�, �� ó�� �ʹ��� ������ ���� ������ ���� ���̵���̴�.

#include <stdio.h>
#define DISH 30000 + 3000 + 10
#define SUSHI 3000 + 10
#define EMPTY 0
#define GIVE 1
#define COLLECT 0

int dish[DISH], sushi[SUSHI];
int N, d, k, c, cnt, max = 0x80000000;

int main(void){

	freopen("in.txt", "r", stdin);

	int i, j, prev = 0;
	scanf("%d %d %d %d", &N, &d, &k, &c);
	for (i = 0; i < N; i++) scanf("%d", &dish[i]);
	for (i = N; i < N + k; i++) dish[i] = dish[i - N];

	sushi[c]++; cnt++;

	for (i = 0; i < k; i++)
	{
		if (sushi[dish[i]] == EMPTY) cnt++;
		sushi[dish[i]]++;
	}
	if (max < cnt) max = cnt;


	for (i = k; i <= N; i++){
		if (max == (k + 1)) break;
		if (sushi[dish[i]] == EMPTY) cnt++;
		sushi[dish[i]]++;

		sushi[dish[i - k]]--;
		if (sushi[dish[i - k]] == EMPTY) cnt--;
		if (max < cnt) max = cnt;
	}


	printf("%d", max);

	return 0;
}
#endif

// ���� ��ȣ A: [LAB]�������
#if 0
#include <stdio.h>

int N, l, M;
int x[100 + 10], y[100 + 10];
int row[100 + 10], col[100 + 10];
int max, cnt_r, cnt_c;
int Find_Diff_Cnt(int *p, int n){
	int i, j, tmp, cnt = 0;
	for (i = 0; i < n; i++)
	{
		tmp = p[i];
		if (p[i] == -1) continue;
		for ( j = 0; j < n; j++)
		{
			if (p[j] == tmp) { p[j] = -1; }
		}
		cnt++;
	}
	return cnt;
}
int Catch_Fisn(int r, int c, int m, int n){
	int cnt = 0;
	int i, j;
	for (i = 0; i < cnt_r; i++)
	{
		if (row[m] <= row[i] && row[i] <= row[m] + r){
			for (j = 0; j < cnt_c; j++)
			{
				if (col[n] <= col[j] && col[j] <= col[n] + c){
					cnt++;
				}
			}
		}
	}
	return cnt;
}
void sort(int *p){
	int i, j, tmp;
	for ( i = 1; i <N-1; i++)
	{
		for ( j = i+1; j <N; j++)
		{
			if (p[i] > p[j]){
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}
int main(void)
{
	int i, fish;
	int r = 0, c,m,n,j, cnt;
	// �Է¹޴� �κ�
	scanf("%d %d %d", &N, &l, &M);

	for (i = 0; i<M; i++)
	{
		scanf("%d %d", &row[i], &col[i]);
		y[i] = row[i]; x[i] = col[i];
	}

	// ���⼭���� �ۼ�
	cnt_r = Find_Diff_Cnt(y, M);
	cnt_c = Find_Diff_Cnt(x, M);
	sort(row); sort(col);

	while (r != (l/2 -1))
	{
		r++; c = l / 2 - r;
		for ( m = 0; m < cnt_r; m++)
		{
			for ( n = 0; n < cnt_c; n++)
			{
				fish = Catch_Fisn(r, c, m, n);
				if (max < fish) max = fish;
			}
		}
	}


	// ����ϴ� �κ�
	printf("%d", max);
	return 0;
}
#endif


#if 0
#include <stdio.h>
typedef struct _rod{
	int r, h;
} Rod;

int map[1010][1010];
int N;

int main(void){

	int i, j, r, len;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d %d", &r, &len);
		for ( j = 0; j < len; j++)
		{
			map[r][j] = 1;
		}
	}

 


	return 0;
}
#endif