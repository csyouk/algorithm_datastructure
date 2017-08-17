#include <stdio.h>
//#include <time.h>
#include <assert.h>

#if 1
#include <stdio.h>

int  B;

char N[300+10][20+10];
char M[300+10][20+10];
int cnt;
char nums[] = "0123456789ABCDEFGHIJ";

int trans(char*N, int t)
{
	int p = 0;

	while(t != 0)
	{
		N[p++] = nums[t%B];
		t/=B;
	}
	N[p] = '\0';
	return p;
}

void reverse(char*N, int p)
{
	int temp, j;
	for(j=0; j<p/2; j++)
	{
		temp = N[j];
		N[j] = N[p-1-j];
		N[p-1-j] = temp;
	}
}

int main(void)
{
	int i, j, p;


	scanf("%d", &B);


	for(i=1;i<=300;i++)
	{
		p = trans(N[cnt], i*i);

		for(j=0; j<=p/2; j++)
		{
			if (N[cnt][j] != N[cnt][p-j-1])
				break;
		}

		if (j>p/2)
		{
			p = trans(M[cnt], i);
			reverse(M[cnt], p);
			cnt++;
		}
	}

	for (i=0; i<cnt; i++)
	{
		printf("%s %s\n", M[i], N[i]);
	}

	return 0;
}
#endif

#if 0
#include <stdio.h>

char str[200 + 10];

char *strp[200 + 10];
char sol[100 + 10][200 + 10];
int  sp;

unsigned int strlen(const char *d)
{
	unsigned int cnt = 0;

	while (*d++)
	{
		cnt++;
	}

	return cnt;
}

int strcmp(const char *s1, const char *s2)
{
	for (;;)
	{
		if (*s1 > *s2) return 1;
		else if (*s1 < *s2) return -1;
		else if (*s1 == 0) return 0;
		s1++;
		s2++;
	}
}

int main(void)
{
	int i, j, len, n, cnt;

	for (;;)
	{

		gets(str);
		if (str[0] == 'E' && str[1] == 'N' && str[2] == 'D' && str[3] == '\0') break;


		len = (int)strlen(str);
		n = 0;
		strp[0] = &str[0];
		for (i = 1; i<len; i++)
		{
			if (str[i] == ' ')
			{
				str[i] = 0;
				n++;
				strp[n] = &str[i + 1];
			}
		}
		n++;

		/* �������� ���� */
		for (i = 0; i<n - 1; i++)
		{
			for (j = i + 1; j<n; j++)
			{
				if (strcmp(strp[i], strp[j])>0)
				{
					char *p;
					p = strp[i];
					strp[i] = strp[j];
					strp[j] = p;
				}
			}
		}

		cnt = 1;
		sp = 0;
		for (i = 1; i<n; i++)
		{
			if (strcmp(strp[i], strp[i - 1]) != 0)
			{
				sprintf(sol[sp++], "%s : %d", strp[i - 1], cnt);
				cnt = 1;
			}
			else
			{
				cnt++;
			}
		}
		sprintf(sol[sp++], "%s : %d", strp[i - 1], cnt);

		for (i = 0; i<sp; i++)
		{
			printf("%s\n", sol[i]);
		}
	}

	return 0;
}
#endif

#if 0
char Buffer[201];
char * addressBuffer[201];
char database[110][210];
int address_size;
int str_cmp(char *p, char *q)
{
	if (p == 0) return -1;
	if (q == 0) return 1;
	while (*p || *q)
	{
		if (*p == *q) { p++; q++; continue; }
		return (*p > *q) ? 1: -1;
	}
	return 0;
}
void store_addresses(char *p)
{
	// clear before store(init)
	for (int i = 0; i < 201; i++)
	{
		addressBuffer[i] = 0;
	}

	int i = 0;
	addressBuffer[i] = p;
	address_size = 1;
	i++; p++;
	while (*p)
	{
		if (*p != ' ' && *(p-1) == ' ') 
		{ 
			*(p-1) = 0;
			addressBuffer[i] = p;
			address_size++;
			i++;
			p++;
			continue;
		}

		p++;
	}
}
void sort_address(void)
{
	char * tmp;
	for (int i = 0; i < address_size-1; i++)
	{
		for (int j = i; j < address_size; j++)
		{
			if (str_cmp(addressBuffer[i], addressBuffer[j]) > 0)
			{
				tmp = addressBuffer[i];
				addressBuffer[i] = addressBuffer[j];
				addressBuffer[j] = tmp;
			}
		}
	}
}
void pprint(void)
{

	if (address_size == 0) return;
	int cnt = 0;
	char * leading_word = addressBuffer[0];
	printf("%s : ", leading_word);
	cnt++;
	for (int i = 1; i < address_size; i++)
	{
		if (str_cmp(leading_word, addressBuffer[i]) == 0)
		{
			cnt++;
			leading_word = addressBuffer[i];
		}
		else //  (str_cmp(tmp, addressBuffer[i]) != 0)
		{ 
			printf("%d\n", cnt);
			cnt = 0;
			leading_word = addressBuffer[i];
			printf("%s : ", addressBuffer[i]);
			cnt++;
		}
	}
	printf("%d", cnt);
}
int main(void)
{
	//freopen("170814-3.txt", "r", stdin);
	while (1)
	{

		gets(Buffer);
		if (Buffer[0] == 0) continue;
		if (Buffer[0] == 'E' && Buffer[1] == 'N' && Buffer[2] == 'D' && Buffer[3] == '\0') break;
		store_addresses(Buffer);
		sort_address();
		pprint();
	}
}
#endif

#if 0
for (int j = i; j < address_size; j++)
{
	if (str_cmp(tmp, addressBuffer[i]) == 0) {
		cnt++;
		tmp = addressBuffer[i];
	}
	if (str_cmp(tmp, addressBuffer[i]) != 0)
	{ 
		//tmp = addressBuffer[i];
		cnt = 0;
		printf("%s : ", addressBuffer[i]);
		cnt++;
	}
}
#endif

#if 0
#include <stdio.h>

int N;
char s[100000+10][20+10];

int strcmp(const char *s1, const char *s2)
{
	for(;;)
	{
		if(*s1 > *s2) return 1;
		else if(*s1 < *s2) return -1;
		else if(*s1 == 0) return 0;
		s1++;
		s2++;
	}
}

int main(void)
{
	int i;
	int j, cnt, unique=1;


	scanf("%d", &N);

	for(i=1; i<=N; i++)
	{
		scanf("%s", s[i]);
	}


	for(i=1; i<N; i++)
	{
		cnt = 0;
		if(s[i][0] == 0) continue;

		for(j=i+1; j<=N; j++)
		{
			if(s[j][0] == 0) continue;
			if(strcmp(s[i], s[j]) == 0)
			{
				if(cnt==0)
				{
					printf("%s %d %d", s[i], i, j);
				}
				else
				{
					printf(" %d", j);
				}
				cnt++;
				s[j][0] = 0;
				unique = 0;
			}
		}
		if(cnt) printf("\n");
	}

	if(unique) printf("unique");

	return 0;
}
#endif

#if 0
#include <stdio.h>

char str[200 + 10];

char *strp[200+10];
char sol[100+10][200+10];
int  sp;

unsigned int strlen(const char *d)
{
	unsigned int cnt = 0;

	while(*d++)
	{
		cnt++;
	}

	return cnt;
}

int strcmp(const char *s1, const char *s2)
{
	for(;;)
	{
		if(*s1 > *s2) return 1;
		else if(*s1 < *s2) return -1;
		else if(*s1 == 0) return 0;
		s1++;
		s2++;
	}
}

int main(void)
{
	int i, j, len, n, cnt;

	for(;;)
	{

		gets(str);
		if(str[0]=='E' && str[1]=='N' && str[2]=='D' && str[3]=='\0') break;


		len = (int)strlen(str);
		n = 0;
		strp[0] = &str[0];
		for(i=1; i<len;i++)
		{
			if(str[i] == ' ')
			{
				str[i] = 0;
				n++;
				strp[n] = &str[i+1];
			}
		}
		n++;

		/* �������� ���� */
		for(i=0; i<n-1; i++)
		{
			for(j=i+1; j<n; j++)
			{
				if(strcmp(strp[i], strp[j])>0)
				{
					char *p;
					p = strp[i];
					strp[i] = strp[j];
					strp[j] = p;
				}
			}
		}

		cnt = 1;
		sp = 0;
		for(i=1; i<n; i++)
		{
			if(strcmp(strp[i], strp[i-1])!=0)
			{
				sprintf(sol[sp++], "%s : %d", strp[i-1], cnt);
				cnt = 1;
			}
			else
			{
				cnt++;
			}
		}
		sprintf(sol[sp++], "%s : %d", strp[i-1], cnt);

		for (i=0; i<sp; i++)
		{
			printf("%s\n", sol[i]);
			}
	  }

	return 0;
}
#endif


#if 0
int N;
char database[10000][21];
unsigned int str_length(const char);
int str_cmp(char *p, char *q);
unsigned int compute_length(const char *d)
{
	int length = 0;
	while (*d)
	{
		*d++;
		length++;
	}
	return length;
}
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

int main(void)
{
	freopen("170814-3.txt","r",stdin);
	int unique_flag = 1;
	int cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", database[i]);
	}

	for (int i = 0; i < N; i++)
	{
		if (database[i][0] == 0) continue;
		for (int j = i+1; j < N; j++)
		{
			if (compute_length(database[i]) != 0 &&
				str_cmp(database[i], database[j]) == 0)
			{
				unique_flag = 0;
				break;
			}
			unique_flag = 1;
		}

		if (unique_flag) { cnt++; continue; }
		int word_flag = 0;
		for (int k = i+1; k < N; k++)
		{
			if (compute_length(database[i]) != 0 &&
				str_cmp(database[i], database[k]) == 0)
			{
				if (word_flag == 0)
				{
					printf("%s", database[i]);
					printf(" %d", i + 1);
					database[k][0] = 0;
					word_flag = 1;
				}
				printf(" %d", k + 1);
				database[k][0] = 0;
			}
		}
		printf("\n");
	}

	if (cnt == N) { 
		printf("unique"); 
		return 0; 
	}
	return 0;
}

#endif

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

	// �Է�
	for (i = 0; i < N; i++)
	{
		j = 0;
		while (1)
		{
			// ���������� ���� ���ڿ��� �̹� ������ ���, 
			// index�� �߰�. 
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
			// ���ڿ��� �������� ���� ��� �ٷ� �߰�. 
			// ���ڿ�, �ε��� �߰�. 
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

	// ���
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


#if 0
int N;
char paper[1024 * 1024 +1];
char backup[1024 * 1024 + 1];
void pprint(int n);
int pow(int b, int e)
{
	int t = 1;
	while (e)
	{
		t *= b;
		e--;
	}
	return t;
}
void assemble(int n)
{
	char* p = paper;
	if (n == 1) return;

	// �߰����� index ���ϱ�.
	int cur_paper_len = 0, middle;
	while (*p){
		cur_paper_len++; p++;
	}

	//backup
	int b_range = pow(2, N-(n - 1));
	//printf("-------------> backup range : %d\n", b_range);
	for (int i = 0; i < b_range; i++)
	{
		backup[i] = paper[i];
	}
	
	middle = 2*cur_paper_len-1;
	//paper[middle] = paper[(middle-1)/2];
	paper[middle] = 'V';
	//printf("middle : %d / cur : %d \n", middle, cur_paper_len);

	//printf("before : %s\n", paper);
	//printf("backup : %s\n", backup);

	// �߰����� ��������, �� ������ ä�����´�.
	// ¦�� �ܰ�� ���� ������ �־��ش�.
	for (int i = 0; i < (middle); i += 2)
	{
		if (i / 2 % 2 == 0)
		{
			paper[i] = '^';
		}
		else
		{
			paper[i] = 'V';
		}
	}
	//printf("even %s\n", paper);

	// �߰����� ��������, �� ������ ä�����´�.
	// Ȧ����°�� ���� �ܰ��� ������ �����´�.
	for (int i = 0; i < (middle); i ++)
	{
		//printf("i : %d / cur : %c / backup : %c\n", i, paper[2*i+1], backup[i]);
		//paper[i] = backup[(i + 1) / 2];
		paper[2 * i + 1] = backup[i];
	}
	//printf("odd  %s\n", paper);

	return assemble(n - 1);
}
void pprint(int n)
{
	int len = 0;
	char *p = paper;

	while (*p)
	{
		printf("%c", *p);
		p++; len++;
	}
	p--; p--; len--;

	
	while (len)
	{
		if (*p == 'V'){
			printf("^");
		}
		else
		{
			printf("V");
		}

		p--; len--;
	}

}
int main(void)
{
	paper[0] = 'V';
	scanf("%d", &N);	
	assemble(N);
	pprint(N);
	//N = 5;
	//assemble(N);
	//pprint(N);
	//printf("%d", assemble(9));
}
#endif

#if 0
int matrix[99][99];
int main(void)
{
	int N, row, col, cnt=0, val=1;
	scanf("%d", &N);
	cnt = N*N;

	// 1 �ֱ�.
	row = 0;
	col = (N - 1) / 2;
	matrix[row][col] = val;
	cnt--; val++;
	row--; col--;

	while (cnt)
	{
		if (row < 0) row = N - 1;
		if (col < 0) col = N - 1;
		matrix[row][col] = val;
		row--; col--;
		if (!(val % N))
		{
			row++; row++; col++;
			if (row < 0) row = N - 1;
			if (col < 0) col = N - 1;
		}

		val++;
		cnt--;
	}


	if (!(val % 3))
	{
		row++;
		if (row < 0) row = N - 1;
		if (col < 0) col = N - 1;
	}



	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
#endif


#if 0
int songs[200];
int main(void)
{
	//freopen("170814-3.txt", "r", stdin);

	int N, T, tmp, i, cnt=0;
	scanf("%d %d", &N, &T);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &songs[i]);
	}

	for (i = 0; i < N-1; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (songs[i] > songs[j])
			{
				tmp = songs[i];
				songs[i] = songs[j];
				songs[j] = tmp;
			}
		}
	}

	i = 0;
	while (1)
	{
		T -= songs[i];
		cnt++; i++;
		if (T == 0) { break; }
		if (T < 0) { cnt--; break; }
	}

	printf("%d", cnt);
}
#endif

#if 0																			
#define ULL unsigned long long int
ULL find_bound(double min, double max, double a)
{
	double mid = (min + max) / 2;
	//printf(">>>>%lf %lf %lf\n", min, mid, max);
	if (((((mid + 1)*mid) / 2 + 1) <= a) && (a < (((mid + 3)*mid) / 2 + 1))) return (ULL)mid;
	if ((((mid + 1)*mid) / 2 + 1) < a)
	{
		return find_bound(mid, max, a);
	}
	else
	{
		return find_bound(min, mid, a);
	}
	
}
ULL find_index(ULL a)
{
	ULL i = 1;
	ULL min = 100000000;
	ULL max = 1000000000000000000;
	if (a < min)
	{
		if (a == i) return i;
		while (i)
		{
			if (((i - 1)*i) / 2 <= a && a < (i*(i + 1)) / 2) break;
			i++;
		}
	}
	else
	{
		i = find_bound(1, max, a);
		//printf("i is ==> %d //  %llu \n", i, a);
		while (i)
		{
			if (((i - 1)*i) / 2 <= a && a <= (i*(i + 1)) / 2) break;
			i++;
		}
		//printf("i is ==> %d %llu \n", i, a);
	}
	return i;
}
int main(void)
{
	//assert(1 == find_index(1));
	//assert(3 == find_index(4));
	//assert(45 == find_index(1000));
	//assert(1234567890 == find_index(762078938126809995));
	//assert(447213595 == find_index(99999999999999994));
	//assert(1234568 == find_index(762078456029));
	//ULL test = 99999999999999994;
	//printf("==> %llu\n", find_index(test));

	//assert(1414213562 == find_index(1000000000000000000));

	unsigned long long int N;
	scanf("%llu", &N);
	printf("%llu", find_index(N));
}
#endif


#if 0
int main(void)
{
	int N, cnt = 2, i =0;
	scanf("%d", &N);

	while (N != i)
	{
		cnt = 2 * cnt - 1;
		i++;
	}	
	printf("%d", cnt*cnt);
}
#endif

#if 0
int N;
int matrix[100][100];
int main(void)
{
	scanf("%d", &N);

	int row = -1, col = -1;
	int val = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			matrix[i][j] = -1;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			if (i % 3 == 0)
			{
				row++; col++;
			}
			else if (i % 3 == 1)
			{
				col--;
			}
			else if (i % 3 == 2)
			{
				row--;
			}
			matrix[row][col] = (val++) % 10;
		}
	}


	// ���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] == -1)continue;
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

}
#endif

#if 0
int N;
int matrix[100][100];
void pprint(void)
{
	// ���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] == -1)continue;
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
int main(void)
{
	
	int loop = 0;
	int row = 0, col = 0;
	int index = 0;

	scanf("%d", &N);


	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			matrix[i][j] = -1;
		}
	}

	do{
		//printf("s==> %d %d %d\n", row, col, index % 10);
		// \ ����
		for (; row < (N-1) - loop; row++, col++, index++)
		{
			matrix[row][col] = index %10;
		}
		//printf("==> %d %d %d\n", row, col, index%10);


		// <-- ����
		for (; col > 0 + loop; col--, index++)
		{
			matrix[row][col] = index % 10;
		}


		// ��
		// |
		for (; row > 0 + loop; row--, index++)
		{

			
			printf("==> %d %d %d\n", row, col, index);
			if (index == (N*(N + 1) / 2)) {
				printf("break==> %d %d %d\n", row, col, index);
				break;
			}
			matrix[row][col] = index % 10;
			pprint();
		}

		row++; row++; col++;
		//printf("==> %d %d %d\n", row, col, index % 10);

		loop++;


	} while (index < (N*(N + 1)) / 2);

	pprint();


	return 0;
}
#endif

#if 0
int matrix[100][100] = { 0, }; //1~100
int main()
{

	int N; // Input

	scanf("%d", &N);

	int row = 0, col = 0; // index
	int val = 1; 
	int loop = 0; // �� �ѹ����� ��������,  loop�� ������Ŵ.

	do
	{
		// --> ����
		for (; col < N - loop; col++){
			matrix[row][col] = val++;
		}
		col--; // ���� index�� matrix ���� ũ�⸦ �ʰ������Ƿ�, �Ѵܰ� ��������
		row++; // ���� index�� �����ؼ� ���� ��ҷ� �̵��� �ִ´�.


		//  |
		//  v  ����
		for (; row < N - loop; row++){
			matrix[row][col] = val++;
		}

		col--; // ���� index�� �����ؼ� ���� ��ҷ� �̵��� �ִ´�.
		row--; // ���������� ���� index�� ���� ũ�⸦ �ʰ������Ƿ�, �Ѵܰ� �������� �̵�.


		// <-- ����
		for (; col >= 0 + loop; col--){
			matrix[row][col] = val++;
		}

		col++;
		row--;

		//  ��
		//  | ����
		for (; row > 0 + loop; row--){
			matrix[row][col] = val++;
		}

		col++;
		row++;

		loop++;

	} while (val < N*N + 1);


	// ���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
#endif


#if 0
int N;
int val[100][100];
int main(void)
{
	int depth = 0, weight = 0, width = 0, bump_cnt = 0, backup;
	//scanf("%d", &N);
	//depth = (N % 2) ? ((N + 1) / 2) : (N / 2);
	// backup = N;

	// test case
	N = 5;
	backup = N;
	depth = 1; 
	width = N - 1;

	if (N % 2)
	{
		//�Է°� Ȧ�� ���̽� 
		for (int i = 0; i < depth; i++)
		{
			bump_cnt = 0;
			// 1 direction
			for (int j = 0; j < width; j++)
			{
				val[i][j] = bump_cnt*(width)+(j + 1);
			}
			bump_cnt++;

			// 2 direction
			for (int j = 0; j < width; j++)
			{
				val[j][N-i] = bump_cnt * (width)+(j + 1);
			}
			bump_cnt++;


			// 3 direction
			for (int j = width; j > 0; j--)
			{
				val[N - i][j] = bump_cnt * (width)+(N - j);
			}
			bump_cnt++;

			// 4 direction
			for (int j = width; j > 0; j--)
			{
				val[j][i] = bump_cnt * (width)+(N - j);
			}
			bump_cnt++;


			weight += N*N - (N - 1)*(N - 1); N--;
		}

	}
	else
	{
	}
	


	N = backup;



	// ���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", val[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#endif


#if 0
int N;
char alpha_set[10000][21];
short cnt_set[10000][10000];
int main(void)
{
	scanf("%d", &N);


	return 0;
}
#endif



#if 0
int Cor_N, charset;

typedef struct{
	char origin;
	char correction;
} Table;

Table t[50];
char raw[100001];

int main(void)
{
	//freopen("170814-3.txt", "r", stdin);
	int len;

	scanf("%d", &Cor_N);
	for (int i = 0; i < Cor_N; i++)
	{
		scanf(" %c %c", &t[i].origin, &t[i].correction);
	}

	//printf("=====\n");
	//for (int i = 0; i < Cor_N; i++)
	//{
	//	printf("%c %c\n", t[i].origin, t[i].correction);
	//}
	//printf("=====\n");


	scanf("%d", &charset);
	for (int i = 0; i < charset; i++)
	{
		scanf(" %c", &raw[i]);
	}

	//printf("%s\n", raw);

	for (int i = 0; i < charset; i++)
	{
		for (int j = 0; j < Cor_N; j++)
		{
			//if (raw[i] == '0') printf("before %c ", raw[i]);
			if (raw[i] == t[j].origin)
			{
				raw[i] = t[j].correction;
				break;
				//printf("after %c\n", raw[i]);
			}
		}
	}

	printf("%s", raw);

	return 0;
}
#endif



#if 0
int N;
int degree = 1;
int matrix[50][50];
int tmp[50][50];
void pprint(void);
void clockwise(int cnt)
{
	if (cnt == 0) return;
	//do sth
	//90 degree rotate and copy to tmp-matrix
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tmp[j][(N-1)-i] = matrix[i][j];
		}
	}

	// backup to original matrix
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = tmp[i][j];
		}
	}


	clockwise(cnt - 1);
}
void pprint(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	while (degree)
	{
		scanf("%d", &degree);
		if (degree / 90 == 0) break;
		if (degree % 90 != 0) continue;
		clockwise(degree / 90);
		pprint();
	}

	return 0;
}
#endif

#if 0
int val[100][100];
int main(void)
{
	// direction�� 3���� ���°� �ִ�. 1, 0, -1
	int N,backup, depth=0, row_dir = 0, col_dir = 1,  row_i = 0, col_i = 0, weight =0;
	scanf("%d", &N);
	backup = N;
	depth = (N + 1)/2;

	
	while (depth)
	{

		for (int i = 1; i <= depth; i++)
		{
			// direction 1
			if (row_dir == 0 && col_dir == 1)
			{
				for (int j = i; j <= ((2 * depth - 1) - 1); j++)
				{
					col_i = j - 1;
					val[row_i][col_i] = j + weight + 0 * ((2 * depth - 1) - 1);
				}
				if ((((2 * depth - 1) - 1) != 0) && (i % ((2 * depth - 1) - 1)))
				{
					row_dir = 1;
					col_dir = 0;
					col_i = (2 * depth - 1) - 1;
				}
			}

			// dir 2
			if (row_dir == 1 && col_dir == 0)
			{
				for (int j = i; j <= ((2 * depth - 1) - 1); j++)
				{
					row_i = j - 1;
					val[row_i][col_i] = j + weight + 1 * ((2 * depth - 1) - 1);
				}
				row_i += (2 * depth - 1) - 1;
				if ((((2 * depth - 1) - 1) != 0) && (i % ((2 * depth - 1) - 1)))
				{
					row_dir = 0;
					col_dir = -1;
					row_i = (2 * depth - 1) - 1;
				}
			}

			// dir3
			if (row_dir == 0 && col_dir == -1)
			{
				for (int j = i; j <= (N - 1); j++)
				{
					col_i = (2 * depth - 1) - j;
					val[row_i][col_i] = j + weight + 2 * ((2 * depth - 1) - 1);
				}
				if ((((2 * depth - 1) - 1) != 0) && (i % ((2 * depth - 1) - 1)))
				{
					
					row_dir = -1;
					col_dir = 0;
					col_i = col_i - 1;
				}
			}

			// dir 4
			if (row_dir == -1 && col_dir == 0)
			{
				for (int j = i; j <= ((2 * depth - 1) - 1); j++)
				{
					row_i = (2 * depth - 1) - j;
					val[row_i][col_i] = j + weight + 3 * ((2 * depth - 1) - 1);
				}
				if ((((2 * depth - 1) - 1) != 0) && (i % ((2 * depth - 1) - 1)))
				{
					row_dir = 0;
					col_dir = 1;
					row_i = row_i - 1;
					//printf(" row_i %d\n", row_i);
				}
			}


		}

		N -= 1;
		depth--;
		weight = (N*N) - ((N - 1)*(N - 1));
		row_i++; col_i++;
		printf("N ==> %d\n", N);
	}


	//N = backup;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", val[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#endif


#if 0
double val[10000];
int main(void)
{
	int N;
	double max = -1.0;
	freopen("170814-3.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &val[i]);
	}

	for (int i = 0; i < N-1; i++)
	{
		double tmp = 1.0;
		for (int j = i; j < N; j++)
		{
			tmp *= val[j];
			if (tmp > max)
			{
				max = tmp;
			}
		}
	}

	printf("%.3lf", max);


	return 0;
}
#endif



#if 0

int	numerator[100], denominator[100];
int GCD(int a, int b)
{
	int r = 1, tmp;
	if (a % b == 0) return b;
	if (a == 0 || b == 0) return 0;
	if (a == 1 || b == 1) return 1;
	while (r)
	{
		tmp = a%b;
		a = b;
		b = tmp;
		r = a%b;
	}
	return b;
}

int LCM(int a, int b)
{
	int gcd = GCD(a, b);
	if (gcd == 0) return 0;
	return gcd *(a / gcd) *(b / gcd);
}

int main(void)
{
	int N;
	int t_numerator = 0, t_lcm = 1;
	//freopen("170814-3.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &numerator[i], &denominator[i]);
	}

	// �Էµ� ���� ���� ���м�ȭ �ϱ�.
	for (int i = 0; i < N; i++)
	{
		//printf("i=%d %d %d\n", i, numerator[i], denominator[i]);
		if (denominator[i] == 0) { printf("0"); return 0; }
		if (numerator[i] == 0) { continue; }
		int gcd = GCD(numerator[i], denominator[i]);
		if (gcd < 0) gcd = -gcd;
		
		if (gcd == 1 || gcd == 0) continue;
		numerator[i] /= gcd;
		denominator[i] /= gcd;
	}
	
	//for (int i = 0; i < N; i++)
	//{
	//	printf("i=%d %d %d\n", i, numerator[i], denominator[i]);
	//}

	//�и� ���ϱ�. �ᱹ���� lcm �̴�.
	for (int i = 0; i < N; i++)
	{
		t_lcm = LCM(t_lcm, denominator[i]);
		//printf("lcm ==> %d\n", t_lcm);
	}

	//printf("lcm ==> %d\n", t_lcm);

	// ������ �� ���ϱ�.
	for (int i = 0; i < N; i++)
	{
		t_numerator += numerator[i]*(t_lcm / denominator[i]);
	}


	if (t_numerator == 0) { printf("0"); }
	else { 
		int _gcd = GCD(t_numerator, t_lcm);
		if (_gcd < 0) _gcd = -_gcd;
		printf("%d/%d", t_numerator/_gcd, t_lcm/_gcd); 
	}
	

	return 0;
}
#endif


#if 0
int freq_table[11] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };
int main(void)
{
	int N;
	double r;

	scanf("%d", &N);

	printf("%5.4lf%%", ((double)freq_table[N-2] / 36.0)*100.0);

	return 0;
}
#endif

#if 0
int val[6];
int main(void)
{
	int N, len=0, i =0;
	scanf("%d", &N);

	while (N)
	{
		val[len] = N % 10;
		N /= 10;
		len++;
	}
	len--;

	while (i != len)
	{
		printf("%d", val[i]);
		i++;
	}
	printf("%d", val[i]);

	return 0;
}
#endif

#if 0
int main(void)
{
	int N;
	scanf("%d", &N);

	printf("%d", (N + 1)*(N + 2) / 2);

	return 0;
}
#endif



#if 0
char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
char matrix[100][100];
int main(void)
{
	int N, k=0;
	scanf("%d", &N);

	for (int i = N - 1; i >=0; i--)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (k % 26 == 0) k = 0;
			matrix[j][i] = alpha[k];
			k++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#endif


#if 0

void print_star(int max, int type)
{
	if (type < 1 || type > 3)
	{
		printf("INPUT ERROR!");
		return;
	}
	
	if (max < 0 || max > 100)
	{
		printf("INPUT ERROR!");
		return;
	}

	if (type == 1)
	{
		for (int i = 0; i < max; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				printf("*");
			}
			printf("\n");
		}
		return;
	}

	if (type == 2)
	{
		for (int i = max; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				printf("*");
			}
			printf("\n");
		}
		return;
	}

	if (type == 3)
	{
		int row = max * 2 - 1;
		for (int i = 0; i < max; i++)
		{
			for (int j = 0; j < row; j++)
			{
				if (((max - 1) - i) <= j && j <= ((max - 1) + i))
				{
					printf("*");
					if (j == ((max - 1) + i)) break;
				}
				else
				{
					printf(" ");
				}

			}
			printf("\n");
		}

		return;
	}
}

int main(void)
{
	int N, type;
	scanf("%d %d", &N, &type);

	print_star(N, type);
	return 0;
}
#endif


#if 0
typedef struct{
	int row;
	int col;
	int t_row;
	int t_col;
} A;

typedef struct{
	int row;
	int col;
	int t_row;
	int t_col;
} B;
int main(void)
{
	A aa[4], bb[5], tmp;
	int a[4][5] = { { 3, -5, 12, 3, -21 }, { -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 }, { 9, 14, 39, -98, -1 } };

	//int aa[4][2] = { { 1, 0 }, { 2, 0 }, { 3, 0 }, {4, 0 }, { 5, 0 } };

	for (int i = 0; i < 4; i++)
	{
		aa[i].row = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		bb[i].col = i + 1;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			aa[i].t_row += a[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			bb[j].t_col += a[j][i];
		}
	}

	// ���� ������ ����
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 4; j++)
		{
			if (aa[i].t_row < aa[j].t_row)
			{
				tmp = aa[i];
				aa[i] = aa[j];
				aa[j] = tmp;
			}
		}
	}
	printf("%d ", aa[0].row);




	// ���� ������ ����
	for (int i = 0; i < 4; i++)
	{		
		for (int j = i; j < 5; j++)
		{
			if (aa[i].t_col < aa[j].t_col)
			{
				tmp = bb[i];
				bb[i] = bb[j];
				bb[j] = tmp;
			}
		}
	}
	printf("%d", bb[0].col);



	return 0;
}
#endif



#if 0
void main(void)
{
	int k_cnt = 0, i_cnt = 0, i = 0;
	char inputs[10000] = { 0 };

	scanf("%s", inputs);

	while (inputs[i])
	{
		if ((inputs[i] == 'K') && (inputs[i + 1] == 'O') && (inputs[i + 2] == 'I')){
			k_cnt++;
		}
		if ((inputs[i] == 'I') && (inputs[i + 1] == 'O') && (inputs[i + 2] == 'I')){
			i_cnt++;
		}
		i++;
	}

	printf("%d\n", k_cnt);
	printf("%d\n", i_cnt);
}

#endif



#if 0
// ���ڿ� ������ 2 �⺻2. koi 008c
char toUpper(char c){
	if (!('a' <= c && c <= 'z')) return c;
	c = c - 'a' + 'A';
	return c;
}
void reverse_print(char *p, int n){
	int i;
	for (i = 1; i < n+1; i++)
	{
		printf("%c", toUpper(p[-i]));
	}
}
int main(void)
{
	char a[51] = { 0 };
	gets(a);
	int k = 0;
	int cnt = 0;

	while (a[k]){
		if (a[k] == ' ' || a[k] == '.' || a[k] =='!')
		{
			reverse_print(a + k, cnt);
			cnt = 0;
			printf("%c", a[k]);
		}
		else
		{
			cnt++;
		}
		k++;
	}
	reverse_print(a + k, cnt);
	printf("\n");
}

#endif

#if 0
char set[51];
int str_len(char *p)
{
	int len = 0;
	while (*p)
	{
		len++; p++;
	}
	return len;
}
int main(void)
{
	char *p;
	int cnt;
	//freopen("test170814-3.txt", "r", stdin);
	gets(set);
	cnt = str_len(set)-1;
	p = set + str_len(set) - 1;

	while (cnt)
	{
		printf("%c", *p); 
		p--; cnt--;
	}
	printf("%c", *p);


	return 0;
}
#endif


#if 0
char set[256];
int str_len(char *p)
{
	int len = 0;
	while (*p)
	{
		if (len == 10) break;
		if ('a' <= (*p) && (*p) <= 'z')
		{
			len++; p++;
			continue;
		}
		if ('A' <= (*p) && (*p) <= 'Z')
		{
			len++; p++;
			continue;
		}
		break;
	}
	return len;
}
int main(void)
{
	char *p;
	int cnt = 10;
	scanf("%s", set);

	p = set + str_len(set) - 1;

	while (cnt)
	{
		if ('a' <= (*p) && (*p) <= 'z')
		{
			printf("%c", *p); 
		}
		if ('A' <= (*p) && (*p) <= 'Z')
		{
			printf("%c", *p); 
		}
		p--; cnt--;
	}


	return 0;
}
#endif

#if 0

int main(void)
{
	int i=-1;
	char c;
	scanf("%c", &c);

	if ('a' <= c && c <= 'z') {
		while ((c-'a')-i)
		{
			i++;
			printf("%c", 'a' + i);
			
		}
		return 0;
	}

	if ('A' <= c && c <= 'Z') {
		while ((c + i) != 'Z')
		{
			i++;
			printf("%c", c + i);
		}
		return 0;
	}

	printf("Error");
	return 0;
}

#endif


#if 0
int val[200][3] = { 0 };
int player[200];
int main(void)
{
	//0
	//84
	//99
	//120
	//46
	//133
	//61
	//132
	//184
	//74
	freopen("test170814-3.txt", "r", stdin);
	int N;
	scanf("%d", &N);


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &val[i][j]);
		}
	}

	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < N; k++)
		{
			if (val[0][j] == val[0][k]) continue;
			if (val[0][j] == val[0][k]) continue;
			//player[j] += val[j];
		}
		//if (val[j][0] != val[j][1] && val[j][0] != val[j][2])
		//{
		//	player[j] += val[j][0];
		//}
		//if (val[j][1] != val[j][0] && val[j][1] != val[j][2])
		//{
		//	player[j] += val[j][1];
		//}
		//if (val[j][2] != val[j][0] && val[j][2] != val[j][1])
		//{
		//	player[j] += val[j][2];
		//}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", player[i]);
	}

	return 0;
}

#endif

#if 0
int memo[90];
unsigned long long int f(int n)
{
	if (n == 1 || n == 2) return memo[n] = 1;
	if (memo[n] != 0) return memo[n];

	return memo[n] = f(n - 1) + f(n - 2);
}

int main(void)
{
	// ���⼭���� �ۼ�
	int N;
	scanf("%d", &N);
	printf("%llu", f(N));
	//printf("%d", f(N));
	return 0;
}

#endif

#if 0
int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		if (i % 2) // Ȧ��
		{
			for (int j = N; j > 0; j--)
			{
				printf("%d ", i*N + j);
			}
		}
		else
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d ", i*N + 1 + j);
			}
		}
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int val[10];
int main(void)
{
	int N;
	int *p = val;
	p++;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &val[i]);
	}

	while (p != &val[0])
	{
		if (p == &val[N]) {
			p = &val[0];
			printf("%d", *p);
			break;
		}
		printf("%d ", *p);
		p++;
	}



	return 0;
}
#endif

#if 0
typedef struct{
	char id;
	int cnt;
} ALPHA;
ALPHA alpha[26];
char val[31];

int main(void)
{
	ALPHA tmp;
	char *p = val;
	scanf("%s", val);

	for (int i = 0; i < 26; i++)
	{
		(alpha + i)->id = 'a' + i;
	}

	while (*p)
	{
		if ('a' <= *p && *p <= 'z'){
			(alpha + (*p) - 'a')->cnt++;
		}
		p++;
	}


	for (int i = 0; i < 25; i++)
	{
		for (int j = i; j < 26; j++)
		{
			if (alpha[i].cnt < alpha[j].cnt)
			{
				tmp = alpha[i];
				alpha[i] = alpha[j];
				alpha[j] = tmp;

			}
		}
	}

	//for (int i = 0; i < 26; i++)
	//{
	//	printf("%c %d\n", alpha[i].id, alpha[i].cnt);
	//}
	printf("%c", alpha[0].id);


	return 0;
}

#endif


#if 0
int digits(int a)
{
	int length = 0;
	while (a)
	{
		a /= 10;
		length++;
	}
	return length;
}
int nums[100000];
int main(void)
{
	int N;
	int total1 = 0, total2 = 0, total3 = 0;

	`
		scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &nums[i]);
	}

	for (int i = 0; i < N; i++)
	{
		switch (digits(nums[i]))
		{
		case 1: total1 += nums[i]; break;
		case 2: total2 += nums[i]; break;
		case 3: total3 += nums[i]; break;
		}
	}

	printf("%d %d %d", total3, total2, total1);

	return 0;
}

#endif

#if 0
int main(void)
{
	int N;
	int total = 0;
	int i = 0;
	scanf("%d", &N);

	while (total < 10000)
	{
		i++;
		total += N*i;
	}
	printf("%d", N*(i - 1));

	return 0;
}

#endif


#if 0

#include <stdio.h>
typedef struct {
	int id;
	int total;
	int ping;
	int bad;
	int ball;
	int pocket;

} P;
P p[10];

int main(void)
{
	int N;

	//freopen("test170814-3.txt", "r",stdin);
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d%d%d", &p[i].id, &p[i].ping, &p[i].bad, &p[i].ball, &p[i].pocket);
	}



	for (int i = 0; i < N; i++)
	{
		p[i].total = p[i].ping + p[i].bad + p[i].ball + p[i].pocket;
	}


	P tmp;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (p[i].total < p[j].total)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i; j < N; j++)
		{
			if ((p[i].total == p[j].total) && (p[i].id > p[j].id))
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}


	//for (int i = 0; i < N; i++)
	//{
	//	printf("%d %d %d %d %d %d\n", p[i].id, p[i].ping, p[i].bad, p[i].ball, p[i].pocket, p[i].total);
	//}
	int gold_p = 0, silver_p = 0, bronze_p = 0;

	printf("GOLD :");
	while (1)
	{
		if (p[0].total == p[gold_p].total){
			printf(" %d", p[gold_p].id);
			gold_p++;
			continue;
		}
		break;
	}
	printf("\n");





	printf("SILVER :");
	while (1)
	{
		if (gold_p + silver_p >= N) break;
		if (p[gold_p].total == p[gold_p + silver_p].total){
			printf(" %d", p[gold_p + silver_p].id);
			silver_p++;
			continue;
		}
		break;
	}
	printf("\n");


	printf("BRONZE :");
	while (1)
	{
		if (gold_p + silver_p + bronze_p >= N) break;
		if (p[gold_p + silver_p].total == p[gold_p + silver_p + bronze_p].total){
			printf(" %d", p[gold_p + silver_p + bronze_p].id);
			bronze_p++;
			continue;
		}
		break;
	}


	return 0;
}

#endif

#if 0

#include <stdio.h>
int sum(int n)
{
	int total = 0;
	while (n)
	{
		total += n;
		n--;
	}
	return total;
}


int find_k(int sum, int given, int N)
{
	// return -1 when error
	int diff = sum - given;
	if ((diff + 1) % 4) return -1;
	if ((diff + 1) / 2 > N) return -1;
	int k = (diff + 1) / 4;
	return k;
}

void test()
{
	assert(55 == sum(10));
	assert(66 == sum(11));
	assert(1 == sum(1));
	assert(5050 == sum(100));
	assert(406 == sum(28));
	assert(3 == find_k(sum(10), 44, 10));
	assert(-1 == find_k(sum(150), 11028, 150));

	assert(1 == find_k(sum(10), 52, 10));
	assert(50 == find_k(sum(100), 4851, 100));
	assert(-1 == find_k(sum(100), 4852, 100));
	assert(-1 == find_k(sum(28), 347, 28));
}
int main(void)
{
	int N, given_sum;
	scanf("%d %d", &N, &given_sum);
	int k = find_k(sum(N), given_sum, N);

	if (k == -1)
	{
		printf("Error");
	}
	else
	{
		printf("%d %d", 2 * k - 1, 2 * k);
	}

	test();




	return 0;
}

#endif


#if 0

#include <stdio.h>


int gcd_two(int a, int b)
{
	int r = 1;
	while (r)
	{
		r = a % b;
		if (r == 0) return b;
		a = b;
		b = r;
	}

}

int lcm_two(int a, int b)
{
	int gcd = gcd_two(a, b);
	return gcd*(b / gcd)*(a / gcd);
}

int lcm(int gcd, int *p, int cnt)
{
	int r = p[0];
	for (int i = 1; i < cnt; i++)
	{
		if (!(r%p[i])) continue;
		r = lcm_two(r, p[i]);

	}

	return r;
}

int gcd(int *val, int cnt)
{
	int i;
	int size = cnt;
	int gcd = 0;

	for (i = 0; i < size - 1; i++)
	{
		if (!gcd)
		{
			gcd = gcd_two(val[i], val[i + 1]);
		}
		else
		{
			gcd = gcd_two(gcd, val[i + 1]);
		}
	}
	return gcd;
}
void test()
{
	assert(27 == lcm_two(27, 9));
	assert(9 * 9 * 10 == lcm_two(81, 90));

	int test1[] = { 243, 270, 270 };
	assert(27 * 9 * 10 == lcm(27, test1, 3));

	int test2[] = { 243, 270, 270, 108 };
	assert(27 * 9 * 10 * 2 == lcm(27, test2, 4));

	int test3[] = { 243, 270, 270, 108, 54, 189, 297 };
	assert(27 * 9 * 10 * 2 * 7 * 11 == lcm(27, test3, 7));
}

int main(void)
{
	int n;
	int val[10];

	//freopen("test170814-3.txt", "r",stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val[i]);
	}

	test();
	int gcdr = gcd(val, n);
	int lcdr = lcm(gcdr, val, n);

	printf("%d %d", gcdr, lcdr);

	return 0;
}

#endif



#if 0


#include <stdio.h>

int main(void)
{
	int a, b;
	int gcd, lcm;
	scanf("%d%d", &a, &b);

	for (gcd = b / 2; gcd > 0; gcd--)
	{
		if (b % gcd == 0 && a % gcd == 0) break;
	}

	if (a == b)
	{
		printf("%d\n", a);
		printf("%d", a);
	}
	else
	{
		printf("%d\n", gcd);
		printf("%d", gcd*(b / gcd)*(a / gcd));
	}




	return 0;
}


#endif

#if 0
#include <malloc.h>
double sqrt(const double d)
{
	/*
	�ٺ��δϾƹ�:
	Xn+1 = (Xn + d / Xn) / 2 ���� n�� ��� ������Ű�� Xn�� d�� �����ٿ� ����
	Xn�� �ʱⰪ X0�� ������ ���� �Ǽ��� �����ϸ� �Ǵµ� ���� 1.0�� ���
	���� ��(Xn)�� x, ���� ��(Xn+1)�� n�� �� �ڵ� ������ ������ ����
	*/

	double n = d / 2.0;
	double x = 0.0;

	while (n != x)
	{
		x = n;
		n = (n + d / n) / 2.0;
	}
	return n;

}

double get_std(int *price, int avg, int cnt)
{
	double sqrsum_of_deviation = 0;

	for (int i = 0; i < cnt; i++)
	{
		int tmp = (price[i] - avg);
		sqrsum_of_deviation += (double)tmp*tmp;
	}

	return sqrt(sqrsum_of_deviation / cnt);
}

void pprint(double d)
{
	int digit = (d + 0.05) * 10;
	if (digit % 10)
	{
		printf("%.1lf\n", d);
	}
	else
	{
		printf("%.lf\n", d);
	}
}

int main(void)
{
	//freopen("test170814-3.txt", "r", stdin);

	int num;

	int total = 0;
	double avg = 0;
	double std = 0;

	scanf("%d", &num);


	int * price = malloc(num*sizeof(int));


	for (int i = 0; i < num; i++)
	{
		scanf("%d", &price[i]);
	}

	for (int i = 0; i < num; i++)
	{
		total += price[i];
	}

	avg = (double)total / num;

	std = get_std(price, avg, num);


	printf("%d\n", total);

	pprint(avg);
	pprint(std);
	//printf("%.1lf\n", avg);
	//printf("%.1lf", std);


	return 0;
}


#endif

#if 0
int main(void)
{
	freopen("test170814-3.txt", "r", stdin);

	int	l1s, l1e, l2s, l2e, tmp;

	scanf("%d%d", &l1s, &l1e);
	scanf("%d%d", &l2s, &l2e);


	if (l1s > l1e)
	{
		tmp = l1s;
		l1s = l1e;
		l1e = tmp;
	}

	if (l2s > l2e)
	{
		tmp = l2s;
		l2s = l2e;
		l2e = tmp;
	}

	if (l1s > l2s)
	{
		tmp = l1s;
		l1s = l2s;
		l2s = tmp;

		tmp = l2e;
		l2e = l1e;
		l1e = tmp;
	}


	if ((l1s <= l2s && l2s <= l1e) && ((1 <= l2e && l2e <= l1s) || l1e <= l2e))
	{
		printf("cross");
	}
	else {
		printf("not cross");
	}


	return 0;
}

#endif

#if 0
//1. 5�ϰ��� �ð��� �ٹ� ���� �ð� s�� ���� �ð� e�� �־�����. (16.0 <= s <= e <= 24.0)
//2. 30�� ������ �Է��� �����ϸ�, 30���� 0.5�� �Էµȴ�. (���� ���, 16�� 30���� 16.5�� ǥ��)
#define WEEK 5
#define BONUS 5000
int cal(double *p)
{
	double work_time = 0;
	double total_t = 0;
	double reward = 0;

	for (int i = 0; i < WEEK; i++)
	{
		work_time = p[2 * i + 1] - p[2 * i];
		if (work_time< 1.0) continue;
		if ((work_time) >= 5.0) {
			total_t += 4.0;
			continue;
		}
		total_t += p[2 * i + 1] - p[2 * i] - 1.0;
	}

	//printf("%f", work_time);

	if (total_t >= 15.0)
	{
		reward = ((total_t * 2) * BONUS)*(0.95);
	}
	if (total_t <= 5.0)
	{
		reward = ((total_t * 2) * BONUS)*(1.05);
	}
	if (5.0 < total_t && total_t < 15.0)
	{
		reward = ((total_t * 2) * BONUS);
	}

	return (int)reward;
}

int main(void)
{
	double times[WEEK * 2] = { 0 };
	double *p = times;


	freopen("test170814-3.txt", "r", stdin);

	for (int i = 0; i < WEEK; i++)
	{
		scanf("%lf %lf", &times[2 * i], &times[2 * i + 1]);
	}

	//for (int i = 0; i < WEEK*2; i++)
	//{
	//	printf("%lf", times[i]);
	//}

	printf("%d", cal(p));


	return 0;
}


#endif

#if 0

double sqrt(const double d)
{
	/*
	�ٺ��δϾƹ�:
	Xn+1 = (Xn + d / Xn) / 2 ���� n�� ��� ������Ű�� Xn�� d�� �����ٿ� ����
	Xn�� �ʱⰪ X0�� ������ ���� �Ǽ��� �����ϸ� �Ǵµ� ���� 1.0�� ���
	���� ��(Xn)�� x, ���� ��(Xn+1)�� n�� �� �ڵ� ������ ������ ����
	*/

	double n = d / 2.0;
	double x = 0.0;

	while (n != x)
	{
		x = n;
		n = (n + d / n) / 2.0;
	}
	return n;

}


int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b); // 4 10

	//printf("%d", find_divisors_cnt(a, b));

	printf("%d", b - a + 1 - (int)sqrt(b) + (int)sqrt(a - 1));

	//printf("%d %d %d", (int)sqrt(b), (int)sqrt(a), (int)sqrt(a - 1));

	return 0;
}
#endif


#if 0
int N;
int sol;

double sqrt_bruteforce(const double d)
{
	double i = 1;
	while (1)
	{
		if (i*i <= d && d < (i + 1)*(i + 1))
		{
			break;
		}
		i++;
	}
	return i;
}

double sqrt_bibilonia(const double d)
{
	/*
	�ٺ��δϾƹ�:
	Xn+1 = (Xn + d / Xn) / 2 ���� n�� ��� ������Ű�� Xn�� d�� �����ٿ� ����
	Xn�� �ʱⰪ X0�� ������ ���� �Ǽ��� �����ϸ� �Ǵµ� ���� 1.0�� ���
	���� ��(Xn)�� x, ���� ��(Xn+1)�� n�� �� �ڵ� ������ ������ ����
	*/

	double n = d / 2.0;
	double x = 0.0;

	while (n != x)
	{
		x = n;
		n = (n + d / n) / 2.0;
	}
	return n;

}


int main(void)
{
	clock_t begin;
	clock_t end;
	double time_spent;

	scanf("%d", &N);



	begin = clock();
	sol = (int)sqrt_bruteforce(N);
	printf("%d", sol);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("brute force, time spent : %f\n", time_spent);



	begin = clock();
	sol = (int)sqrt_bibilonia(N);
	printf("%d", sol);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("sqrt_bibilonia, time spent : %f\n", time_spent);



	return 0;

}

#endif