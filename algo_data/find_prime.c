#include <stdio.h>

int is_prime(int n){
		int i;
		if (n == 1 || n == 2) return 1;
		for ( i = 3; i*i <= n; i++)
		{
				if (!(n%i)) return 0;
		}
		return 1;
}



// �����佺�׳׽��� ü
// �迭�� ����� ����, �Ҽ��� ������� �Ҽ��� �ƴϴ�, ǥ�ø� �س��´�.
#include <math.h>
#define MAX 10000000
#define PRIME 0
#define NOT_PRIME 1

int nums[MAX]; 
int Eratos(){
// ���� ���ڵ���� ���������� Ȯ���� �ϸ鼭 
//  �Ҽ��� 0, �Ҽ��� �ƴϸ� 1�� nums �迭�� üũ�س��´�.
// ���࿡ Ž�������� 10000000�̶��, Ž�� ������ sqrt(10000000) ������ �ϸ� �ȴ�.
		int i, j;
		nums[0] = nums[1] = 1;
		for (i = 2; i <= sqrt(MAX); i++)
		{
				if (!nums[i]){
						for (j = 2 * i; j <= MAX; j += i)
						{
								nums[j] = 1;
						}
				}
		}
}

int main(void){
	
  printf("%d", is_prime(324161900711111));

	Eratos();
	return 0;
}