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
1. ���� ȸ�� �ʹ��� �մ��� ������� �ʹ��� ������, ���� �ʹ丸ŭ 
�Ĵ븦 ���������, ��Ʈ�� ������ �� ��ġ���� k���� ���ø� �����ؼ� 
���� ��� ���ε� ���� �������� �����Ѵ�.
2. �� �������� �ʹ��� ���� �ϳ��� ���� ������ �����ϰ�, 
1�� ��翡 ������ ��� �� ������ ������ ������ �ʹ� �ϳ��� 
�߰��� ����� �����Ѵ�. ���� �� ��ȣ�� ������ �ʹ��� ���� 
��Ʈ ���� ���� ���, �丮�簡 ���� ����� �մԿ��� �����Ѵ�.
�� ���� ��翡 �����Ͽ� ������ �� �پ��� ������ �ʹ��� �������� �Ѵ�.
�� �׸��� ���� ������ �����غ���. k=4�̰�, 30�� �ʹ��� �������� 
�޾Ҵٰ� ��������. 
������ �������� ������ 4���� �ٸ� �ʹ��� ���� �� �ִ� ���� 
(9, 7, 30, 2), (30, 2, 7, 9), (2, 7, 9, 25) �� ���� ��찡 �ִµ�, 
30�� �ʹ��� �߰��� �������� ���� �� �����Ƿ� (2, 7, 9, 25)�� ������ 
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
