# Dynamic Array
- 배열의 크기가 고정되어 있지 않고, 유동적으로 변하는 배열.
- 5가지 방식으로 동적 배열을 생성해보자.


## 1. 2차원 동적 배열을 생성하는 코드이다.
  - 메모리가 연속적으로 붙어있지 않다.
  - 메모리 환산법이 가능하지 않다.
  - 계산에 시간이 걸린다.
```cpp

#include <stdio.h>
#include <malloc.h>

void main(void)
{
	int ** p, x, i, j;

	scanf("%d", &x);

	p = malloc(x * sizeof(int *));

	for(i=0;i < x; i++){
		p[i] = malloc(4 * sizeof(int));
	}

	p[2][3] = 10;

	for(i=0;i<x;i++){
		for(j=0; j < 4; j++){
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<x;i++){
		free(p[i]);
	}
	free(p);
}
```


## 2. 선형 메모리로 할당한 동적 배열
  - 할당 받은 메모리가 선형적이다.
  - 메모리를 연속적으로 접근하는 것이 가능하다.
  - 만약 2차원 배열을 받는 함수에 전달할때, 변수 p를 2차원 배열처럼 사용하는 것이 불가능하다.
    - p가 아닌, p[0]를 전달해야 사용하는 것이 가능하다.

```cpp

#include <stdio.h>
#include <malloc.h>

void main(void)
{
	int ** p, x, i, j;

	scanf("%d", &x);

	p = malloc(x * sizeof(int *));
	p[0] = malloc (x * 4 * sizeof(int));

	for(i=1; i < x; i++){
		p[i] = p[0] + i * 4;
	}

	p[2][3] = 10;
	for(i=0;i<x;i++){
		for(j=0; j < 4; j++){
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	free(p[0]);
	free(p);
}

```


## 3. 등가포인터를 이용한 동적 배열
  - 가장 깔끔한 방법이라고 생각한다.

```cpp

#include <stdio.h>
#include <malloc.h>

void main(void)
{
  // 요소수 4개씩 바라보는 4배열 포인터를 선언.
	int (*p)[4], i, j;

	scanf("%d", &x);

	p = malloc(x * sizeof(int [4]));

	for(i=0; i< x; i++){
		for(j = 0; j < 4; j++){
			p[i][j] = i*4 + j;
		}
	}

	p[2][3] = 10;
	for(i=0;i<x;i++){
		for(j=0; j < 4; j++){
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}


	free(p);
}
```

## 4. 모든 요소수가 가변인 배열
  - 모든 요소수가 가변이므로, 등가포인터를 생성할 수가 없다.
  - 어쩔수 없이 선형메모리를 이용한 동적배열을 사용해야 한다.  

```cpp

#include <stdio.h>
#include <malloc.h>

void main(void)
{
	int ** p, i, j, m, n;

	scanf("%d %d", &m, &n);

	p = malloc(m * sizeof(int *));
	p[0] = malloc (m * n * sizeof(int));

	for(i = 1; i < m; i++){
		p[i] = p[0] + i*n;
	}

	p[2][3] = 10;

	for(i=0;i<m;i++){
		for(j=0; j < n; j++){
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	free(p[0]);
	free(p);
}
```

## 5. 2차원 배열을 1차원 배열로 에뮬레이션
  - int [m][n] 배열을 int[m*n] 배열로 만들어서 활용한다.

```cpp

#include <stdio.h>
#include <malloc.h>

void main(void)
{
	int * p, i, j, m, n;

	scanf("%d %d", &m, &n);

	p = malloc(m * n * sizeof(int));

	for(i=0;i<m;i++){
		for(j=0; j < n; j++){
			p[i * n + j] = i * n + j;			
		}
	}

	p[2][3] = 10;

	for(i = 0; i < m * n; i++){
		printf("%d ", p[i]);
		if(!i%4)printf("\n");
	}

	free(p[0]);
	free(p);
}
```
