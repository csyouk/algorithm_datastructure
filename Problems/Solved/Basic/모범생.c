// 모범생
#if 0

typedef struct st
{
	int id;
	unsigned int score;
} ST;

ST sts[30000];

int main(void)
{
	// 여기서부터 작성

	int N;
	ST tmp;

	//freopen("test.txt", "r", stdin);

	scanf("%d", &N);


	for (int i = 0; i < N; i++)
	{
		sts[i].id = i + 1;
		scanf("%d", &sts[i].score);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (sts[i].score < sts[j].score)
			{
				tmp = sts[i];
				sts[i] = sts[j];
				sts[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", sts[i].id);
	}


	return 0;
}

#endif

//	모범생
#if 0

#include <stdio.h>
int N;
typedef struct {
	int id;
	int n;
}st;
st a[30000 + 10];
int main(void){
	int i, j;
	st tmp;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i].n);
		a[i].id = i + 1;
	}
	for (i = 0; i < 3; i++){
		for (j = i + 1; j < N; j++){
			if (a[i].n < a[j].n){
				tmp = a[i]; a[i] = a[j]; a[j] = tmp;
			}
		}
	}
	for (i = 0; i < 3; i++) printf("%d ", a[i].id);
	return 0;
}
#endif
