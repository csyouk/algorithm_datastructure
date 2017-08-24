#if 0
/*
2017년 8월 23일 워크샵문제

0. 배열기반 링크드 리스트 자료구조 이용

0. 구조체 멤버는 사번(int), 이름(char [12]), 국어(short), 영어(short), 수학(short),
평균(double) (평균은 자동계산) , next(자기참조 구조체)
메모리 절약을 생각해서 최대한 적게 사용하도록 순서정할 것. 36B 되도록 할것

0. 메뉴를 구성한다
(1.자료추가, 2.자료삭제, 3. 자료수정, 4.전체인쇄, 5.자료인쇄, 6.정렬인쇄)

1. 자료추가
Create_Data 함수를 이용해서 자료를 입력받아
Insert_Data 함수를 이용해서 저장한 후 Insert_Node 함수를 이용하여 링크를 구성하라. 사번순으로 오름차순 정렬되도록 할 것
배열이 꽉 차있는 경우 자료추가 못한다는 메시지를 보여줘라
같은 사번인 경우도 메시지를 보여줌
정상적으로 저장시 각 노드의 정보를 모두 출력한다

2. 자료삭제
사번 또는 이름으로 삭제하도록 서브 메뉴 구성
동일 이름시 모두 삭제

3. 자료수정
사번을 입력하면 이름, 국어, 영어, 수학을 수정할 수 있다(단, 사번 수정 불가)

4. 전체인쇄
각 노드의 정보를 모두 출력한다

5. 자료인쇄
서브 메뉴 구성 필요 (사번, 이름, 국어, 영어, 수학, 평균)
사번 또는 이름을 입력하면 해당 자료를 모두 인쇄
국어, 영어, 수학, 평균을 두개의 값(이상, 이하) 입력받아 그 값 이상~이하인 자료를 모두 인쇄

6. 정렬인쇄
서브 메뉴 구성 필요 (사번, 이름, 국어, 영어, 수학, 평균, 오름차순, 내림차순)
해당 자료를 원하는 방법으로 정렬해서 출력함

프로그램을 종료하기 전까지 계속 실행되도록 만들것

*/
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#pragma warning( disable : 4996 )

#define MAX_ST 10

typedef struct _student
{
	unsigned int id;
	char name[12];
	short korean;
	short english;
	short math;
	double avg;
	struct _student * next;
	struct _student * prev;
}STUDENT;

STUDENT students[MAX_ST];

STUDENT Head;

// 자료 추가 / 배열에 추가, 노드에 추가
#if 1
int Insert_Data(STUDENT *p)
{
	// 배열에 데이터가 차있으면, -1
	// 저장 성공시 배열의 요소를 반환.
	int i;
	if (students[MAX_ST - 1].id != 0) return -1;

	for (i = 0; i < MAX_ST; i++)
	{
		if (students[i].id != 0) continue;
		students[i] = *p;
		break;
	}
	return i;
}

int Insert_Node(STUDENT *head, STUDENT *d)
{
	// return -1 : 노드가 꽉 차있을 때.
	// return 1 : 노드 추가 성공 시
	// 동일한 id 존재시 -2

	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		if ((head->next == NULL) || (d->id < head->next->id))
		{
			d->next = head->next;
			head->next = d;
			return 1;
		}
		if (head->next->id == d->id) return -2;
		head = head->next;
	}

	return 1;
}

void Print_Node(STUDENT * d)
{
	printf("=======================================================================\n");

	printf(" ID=%d\n NAME=%s\n KOREAN=%d\n ENGLISH=%d\n MATH=%d\n AVG=%f\n next=0x%.8X\n", 
				d->id, d->name, d->korean, d->english, d->math, d->avg, d->next);

	printf("=======================================================================\n");
}

int Create_Data(void)
{
	STUDENT tmp;
	int id;

	printf("데이터를 생성합니다. ID, 이름, 국어,영어 수학 점수를 기입해주세요. \n");

	// 입력 성공시 1
	printf("ID : ");
	scanf("%d", &tmp.id);
	printf("이름 : ");
	scanf("%s", tmp.name);
	printf("국어점수 : ");
	scanf("%d", &tmp.korean);
	printf("영어점수 : ");
	scanf("%d", &tmp.english);
	printf("수학점수 : ");
	scanf("%d", &tmp.math);
	tmp.next = NULL;
	tmp.prev = NULL;

	tmp.avg = (tmp.math + tmp.korean + tmp.english) / 3.0;
	if (Insert_Data(&tmp) < 0)
	{
		printf("저장공간이 부족합니다.\n");
		return -1;
	}
	printf("데이터를 배열에 성공적으로 저장했습니다.\n");
	id = Insert_Node(&Head, &tmp);
	if (id < 0)
	{
		printf("저장공간이 부족합니다.\n");
		return -1;
	}
	Print_Node(&tmp);
	printf("데이터를 노드에 성공적으로 저장했습니다.\n");
	return 1;
}
// 메뉴 출력
#if 1
void Print_Menu()
{
	printf("1 : 자료 추가\n");
	printf("2 : 자료 삭제\n");
	printf("3 : 자료 수정\n");
	printf("4 : 전체 인쇄\n");
	printf("5 : 자료 인쇄\n");
	printf("6 : 정렬 인쇄\n");
}
#endif
#endif

// 자료 삭제
#if 1
int Delete_Data(void)
{
	// -1 해당하는 사번이 없음.
	// 1 삭제 성공시.
	printf("사번 또는 이름을 선택해 주세요. 사번=1, 이름=2\n");

	int sel = getch() - '0';
	switch (sel)
	{
	case 1: {
		int id;
		printf("ID를 입력해주세요. ");
		scanf("%d", &id);
		for (int i = 0; i < MAX_ST; i++)
		{
			if (students[i].id == 0) return -1;
			if (students[i].id == id){
				printf("ID : %d / Name : %s \n", students[i].id, students[i].name);
				students[i].id = 0;
				return 1;
			}
		}
		return -1;
		//Update_Node(&Head);
	}break;
	case 2: {
		char name[12];
		printf("이름을 입력해주세요. ");
		scanf("%s", name);
		for (int i = 0; i < MAX_ST; i++)
		{
			if (students[i].name[0] == 0) break;
			if (strcmp(students[i].name, name) == 0){
				students[i].name[0] = 0;
			}
		}
	}break;
	default:
		break;
	}
	
}
#endif

// 자료 수정
#if 0
void Modify_Data(void)
{
	STUDENT p;
	int id;

	printf("사번을 입력해주세요. : \n");
	scanf("%d", &id);

	for (int i = 0; i < MAX_ST; i++)
	{
		if (students[i].id == id)
		{
			printf("수정할 데이터를 입력해주세요.\n");
			printf("이름 : ");
			scanf("%s", p.name);
			printf("국어점수 : ");
			scanf("%d", &p.korean);
			printf("영어점수 : ");
			scanf("%d", &p.english);
			printf("수학점수 : ");
			scanf("%d", &p.math);
			return;
		}
	}
}
#endif

// 모든 데이터 출력
#if 1
int Print_All_Node(STUDENT * head)
{
	int i;
	printf("Head.next = %#.8x\n", head->next);

	for (i = 0; i < MAX_ST; i++)
	{
		if (head->next == NULL) break;
		if (head->next->id == 0) break;
		Print_Node(head);
		//printf("ID : %d / Name : %s / 국어 : %hd / 영어 : %hd / 수학 : %hd \n",
		//	head->next->id, head->next->name, head->next->korean, head->next->english, head->next->math);
		head = head->next;
	}
	return i;
}
#endif

#if 1
void Print_All_Data(void)
{
	for (int i = 0; i < MAX_ST; i++)
	{
		if (students[i].id == 0) break;
		printf("ID : %d / Name : %s / 국어 : %hd / 영어 : %hd / 수학 : %hd \n",
			students[i].id, students[i].name, students[i].korean, students[i].english, students[i].math);
	}
}
#endif


#if 1

void Sort(STUDENT *d, int order, int (* comp)(STUDENT *x, STUDENT *y), int )
{
	int max, i,j,k,t;
	for (max = 0; max < MAX_ST; max++);
	STUDENT tmp;

	// Insertion Sort
	for ( i = 1; i < MAX_ST; i++)
	{
		if (d[i].id == 0) break;
		for (j = 0; j < i; j++)
		{
			if (comp(&d[j], &d[i]) == order) break;
		}
		
		tmp = d[i];
		for ( k = i; k > j; k--)
		{
			d[k] = d[k - 1];
		}
		d[j] = tmp;
	}

	for ( t = 0; t < max; t++)
	{
		if (d[t].)
	}


	return;
}
#endif

int main(void)
{
	int sel;
	
	while (1)
	{
		Print_Menu();
		sel = getch() - '0';
		switch (sel)
		{
		case 1: {
			Create_Data();
		}break;
		case 2: printf((Delete_Data() > 0) ? "데이터를 성공적으로 삭제 했습니다.\n" : "해당 데이터는 존재하지 않습니다.\n"); break;
		//case 3: Modify_Data(); break;
		case 4: Print_All_Node(&Head); break;
		//case 5: Print_Data(); break;
		//case 6: Print_Sorted_Data(); break;
		case 7: Print_All_Data(); break;
		default: printf("1~6번 사이의 메뉴를 선택해주세요.\n"); break;
		}
	}


	return 0;
}
#endif