
// UNIQUENESS
#if 0
int N;
char database[10000][21];
typedef struct{
	char word[24];
	short index[10000];
} WORD;
WORD words[10000];
int str_cmp(char *p, char *q)
{
	// return 0 when two strings are same
	while (*p || *q)
	{
		if (*p == *q){ p++; q++; continue; }
		return (*p > *q) ? 1 : -1;
		p++; q++;
	}
	return 0;
}
void str_cpy(char *d, const char *s)
{
	while (*d++ = *s++);
}
int main(void)
{
	int i, j, k;
	//freopen("170814-3.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", database[i]);
	}

	// 입력
	for (i = 0; i < N; i++)
	{
		j = 0;
		while (1)
		{
			// 순차적으로 비교후 문자열이 이미 존재할 경우,
			// index만 추가.
			if (str_cmp(&words[j].word, database[i]) == 0)
			{
				k = 0;
				while (1)
				{
					if (words[j].index[k] == 0){
						words[j].index[k] = i + 1;
						break;
					}
					k++;
				}
				break;
			}
			// 문자열이 존재하지 않을 경우 바로 추가.
			// 문자열, 인덱스 추가.
			else
			{
				if (words[j].index[0] != 0){ j++; continue; }
				str_cpy(&words[j].word, database[i]);
				k = 0;
				while (1)
				{
					if (words[j].index[k] == 0){
						words[j].index[k] = i + 1;
						break;
					}
					k++;
				}
				break;
			}
			j++;
		}

	}


	if (words[N-1].index[0] != 0)
	{
		printf("unique");
		return;
	}

	// 출력
	for (i = 0; i < N; i++)
	{
		if (words[i].index[1] == 0) continue;
		printf("%s ", words[i].word);
		j = 0;
		while (1)
		{
			if (words[i].index[j] == 0) break;
			printf("%d ", words[i].index[j]);
			j++;
		}
		printf("\n");

	}

}
#endif
