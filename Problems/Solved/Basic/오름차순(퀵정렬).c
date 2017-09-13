// 문제 번호 Q: [TST]오름차순 정렬 (퀵정렬)
#if 0
int N;
unsigned int nums[30000 + 10];
void quick_sort(unsigned int *d, int s, int e)
{
	int pivot, left, target, tmp;
	target = s;
	pivot = e;

	if (e <= s) return;

	for (left = s; left < e; left++)
	{
		if (d[left] < d[pivot])
		{
			if (left != target)
			{
				tmp = d[left];
				d[left] = d[target];
				d[target] = tmp;
			}
			target++;
		}
	}

	if (target < pivot)
	{
		tmp = d[target];
		d[target] = d[pivot];;
		d[pivot] = tmp;
	}


	quick_sort(d, s, target - 1);
	quick_sort(d, target + 1, e);
}

int main(void)
{
	// 여기서부터 작성

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lu", &nums[i]);
	}

	quick_sort(nums,0,N-1);

	for (int i = 0; i < N; i++)
	{
		printf("%d ", nums[i]);
	}

	return 0;
}
#endif
