
#if 0
//최대 30자의 단어를 입력 받은 후 단어에서 가장 많은 소문자를 인쇄하라.
//대문자(‘A’~’Z’)와 소문자(‘a’~’z’)가 아닌 문자는 입력되지 않으며, 30자를 초과하여 입력하는 경우는 없다고 가정하고, 이에 대한 예외 처리는 하지 않는다.
//30자 이하의 단어를 입력한다.
//
//가장 많은 소문자를 인쇄한다.
//빈도가 동일한 경우 ‘a’와 가까운 소문자를 인쇄한다.
#include <stdio.h>

char str[30 + 10];
char sol;

int  cnt[26];

int main(void)
{
	int i, max = 0, maxi;


	scanf("%s", str);


	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			cnt[str[i] - 'a']++;
		}
	}

	for (i = 0; i<26; i++)
	{
		if (cnt[i]>max)
		{
			max = cnt[i];
			maxi = i;
		}
	}
	sol = maxi + 'a';


	printf("%c", sol);

	return 0;
}
#endif
