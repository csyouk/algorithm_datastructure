# Hash Table
- 해시 테이블은 자료 구조의 검색을 효율적으로 하기 위한 방법이다.
- 장점은 탐색 속도가 매우 빠르 다는 것이다.
- 하지만, 같은 hash값의 결과로 동일한 자료가 발생하는 경우가 생기는데, 공간은 한 군데 이므로 저장이 불가능한 경우가 생긴다.
- 이러한 경우를 Collision(충돌)이라고 한다.
- 해시테이블에서 충돌 해결(Collision Resolution)을 하는 방법은 2가지 이다.
  - Open Addressing
  - Chaining Method


## Open Addressing
- 개요.
 - 공간이 차 있으면 순차적으로 빈 공간을 탐색해서 저장한다.

- **장점**
  - 구현이 단순하다.

- **단점**
  - 해시값의 결과로 나오는 방에 이미 데이터가 채워져 있을 경우 다른 방을 탐색해 나가는데, 시간이 걸릴 수 있다.

### CRUD
다음과 같은 데이터 구조가 있다고 해보자.
```cpp
typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
}SCORE;

#define MAX_ST		20
#define HASH_KEY	10
#define STEP		1
#define EMPTY -1
#define EXIST 1
#define NOT_EXIST -1
#define DELETE_SUCCESS -2
SCORE Hash_table[MAX_ST];
```

#### Hash Key 생성 방법
```cpp
int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}
```

#### Hash Table의 생성
```cpp
void Init_Hash_Table(void)
{
	int i;

	for (i = 0; i<MAX_ST; i++)
	{
		Hash_table[i].id = -1;
	}
}
```

#### STEP에 따른 검색 속도의 차이
- STEP의 수를 HASH_KEY와 서로수인 수를 선택해주면, 검색 속도가 빨라진다.
```cpp
#if 1

// 누적 loop횟수 120번
#define HASH_KEY	10
#define STEP 1

#else

// 누적 loop횟수 63번
#define HASH_KEY	7  // 가급적 소수
#define STEP				8  // 테이블의 요소수와 서로 소 관계인 수

#endif
```

#### Create
```cpp
int Insert_Data(SCORE * d)
{
  // 원본 키는 벡업해 놓는다.
	int key = Get_Hash_Key(d->id);
	int pos = key;

	while (1)
	{
		if ((Hash_table[pos].id == NOT_EXIST) || (Hash_table[pos].id == DELETED)) {
			Hash_table[pos] = *d;
			return pos;
		}
		pos += STEP;
		if (pos > MAX_ST-1) pos %= MAX_ST;
		if (pos == key) return -1;
	}
}
```

#### Retrieve
```cpp
SCORE * Search_Data(int id)
{
	int key, pos;
	pos = key = Get_Hash_Key(id);

	while (1)
	{
		if (Hash_table[pos].id == NOT_EXIST){
			return NULL;
		}
		if (Hash_table[pos].id == id){
			return &Hash_table[pos];
		}

		pos += STEP;
		if (pos > MAX_ST - 1) pos = 0;
		if (pos == key) return NULL;
	}
}
```

#### Update
```cpp

```

#### Delete
```cpp
int Delete_Data(int id)
{
	SCORE *p;
	p = Search_Data(id);
	if (p == NULL) return NOT_EXIST;
	p->id = DELETED;
	return DELETE_SUCCESS;
}

```

----------------------------------

## Chaining Method
- 개요
  - 공간이 차 있으면, 그 공간을 head로 하는 linked list를 생성한다.
  - 해시 값으로 공간을 찾았는데 다른 자료가 차 있으면 linked list를 통해 list를 늘려나간다.

- **장점**
  - 탐색 시간이 상대적으로 open addressing 방식보다 적다.
  - 구현이 까다롭지만, 구현하고 나면, open addressing 방식보다 데이터의 구조가 더 직관적이다.

- **단점**
  - 특정 해시 값의 자료가 많을 경우, 그 자료를 찾는 시간이 증가되게 된다.

### CRUD

- 다음과 같은 자료구조가 있다고 하자.
```cpp
typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score * next;
}SCORE;

#define MAX_ST		20
#define HASH_KEY	5

// 큰 Head가 5개 있다고 생각하자.
SCORE Hash_table[HASH_KEY];
```

#### Hash Key 생성 방식 및 테이블 초기화
```cpp
int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}

void Init_Hash_Table(void)
{
	int i;

	for (i = 0; i<MAX_ST; i++)
	{
		Hash_table[i].next = (SCORE *)0;
	}
}
```

#### Create
```cpp
int Insert_Data(SCORE * d)
{
	int key;
	key = Get_Hash_Key(d->id);

	SCORE *head = &Hash_table[key];
	SCORE *node = calloc(1, sizeof(SCORE));
	if (!p) return -1;

	*node = *d;
	while (1)
	{
    if(head->next == NULL) // 무조건적으로 node의 맨 뒤에 추가하는 방식.
    {
      node = node->next;
      head->next = node;
      node->next = NULL;
      return 1 ;
    }
		if (head->next == NULL || head->next->id > node->id) // id순으로 삽입하는 방법.
		{
      node->next = head->next;
      head->next = node;
      return 1;      
    }
	}

	head->next = node;
	node->next = NULL;
	return 1;
}
```

#### Retrieve
```cpp
SCORE * Search_Data(int id)
{
	SCORE * p;

	p = Hash_table[Get_Hash_Key(id)].next;

	while(1)
	{
		if (p->id == id) return p;
		if (p->next == (SCORE *)0) return (SCORE *)0;
		p = p->next;
	}
}
```

#### Update
```cpp

```

#### Delete
```cpp
int Delete_Data(int id)
{
	SCORE * target;
	SCORE * head;

	head = &Hash_table[Get_Hash_Key(id)];
	while (1)
	{
		if (head->next == NULL) return -1;
		if (head->next->id == id)
		{
			target = head->next;
			head->next = head->next->next;
			free(target);
		}
		head = head->next;
	}
}
```

#### 참고
- Python에서 dict는 hash table의 일종이다. [이곳](https://mail.python.org/pipermail/python-list/2000-March/048085.html)을 참고한다.
- Java Collection Set에 있는 HashMap이 어떻게 구현되어 있는지 분석한 글은 [이곳](http://d2.naver.com/helloworld/831311)을 참고한다.
