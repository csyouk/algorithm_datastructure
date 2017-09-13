
// 경비원
#if 0
#define ABS(a) (((a) < (0))?-(a):(a))
int W, H, S, round, sum;
typedef struct
{
	int x;
	int y;
} Pos;
Pos positions[110];
int square[110][110];
int pos, len;
int x, y;
void check(int pos, int len, int i)
{
	switch (pos)
	{
		case 1:
			x = 0; y = len;
			break;
		case 2:
			x = H; y = len;
			break;
		case 3:
			x = len; y = 0;
			break;
		case 4:
			x = len; y = W;
			break;
		default:
			break;
	}

	square[x][y] = 1;

	positions[i].x = x;
	positions[i].y = y;
}

int main(void)
{
	//freopen("test.txt", "r", stdin);
	scanf("%d %d", &W, &H);
	scanf("%d", &S);
	round = 2 * (W + H);

	for (int i = 0; i < S + 1; i++)
	{
		scanf("%d %d", &pos, &len);
		check(pos, len, i);
	}

	for (int i = 0; i < S; i++)
	{
		int len = 0, other = 0;

		if (ABS(positions[i].x - x) == H)
		{
			len = y + positions[i].y + H;
		}
		else if (ABS(positions[i].y - y) == W)
		{
			len = x + positions[i].x + W;
		}
		else
		{
			len = ABS(positions[i].x - x) + ABS(positions[i].y - y);
		}
		other = round - len;
		sum += (len > other)? other : len;
	}

	printf("%d", sum);

	return 0;
}
#endif

#if 0
#define ABS(a) (((a) < (0))?-(a):(a))
int W, H, N, sol, a[110];
int main(void)
{
	int i, d, l,dis;
	scanf("%d %d %d", &W, &H, &N);
	for ( i = 0; i < N+1; i++)
	{
		scanf("%d %d", &d, &l);
		switch (d)
		{
			case 1: a[i] = l; break;
			case 2: a[i] = 2 * W + H - l; break;
			case 3: a[i] = 2 * W + 2 * H - l;
			case 4: a[i] = W + l;
			default: break;
		}
	}

	for (i = 0; i < N+1; i++)
	{
		dis = ABS(a[N] - a[i]);
		if (dis < H + W) sol += dis;
		else sol += 2 * H + 2 * W - dis;
	}
	printf("%d", sol);
	return 0;
}
#endif
