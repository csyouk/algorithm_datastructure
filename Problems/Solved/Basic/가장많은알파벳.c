// 문제 번호 T: [TST]가장 많은 알파벳은?
#if 0
#include <stdio.h>
#include <string.h>
int l_alpha[26];
char d[31];
int main(void)
{
	int max = -1, pos = -1;
	// 여기서부터 작성
	scanf("%s", d);

	for (int i = 0; i < strlen(d); i++)
	{
		if ('a' <= d[i] && d[i]<= 'z')
		{
			l_alpha[d[i] - 'a']++;
		}
	}

	for (char s = 'a'; s < 'z'+1; s++)
	{
		if (max < l_alpha[s - 'a'])
		{
			max = l_alpha[s - 'a'];
			pos = s - 'a';
		}
	}

	printf("%c", pos+'a');

	return 0;
}
#endif
