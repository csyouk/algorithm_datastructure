#if 0
/*
2017�� 8�� 23�� ��ũ������

0. �迭��� ��ũ�� ����Ʈ �ڷᱸ�� �̿�

0. ����ü ����� ���(int), �̸�(char [12]), ����(short), ����(short), ����(short),
���(double) (����� �ڵ����) , next(�ڱ����� ����ü)
�޸� ������ �����ؼ� �ִ��� ���� ����ϵ��� �������� ��. 36B �ǵ��� �Ұ�

0. �޴��� �����Ѵ�
(1.�ڷ��߰�, 2.�ڷ����, 3. �ڷ����, 4.��ü�μ�, 5.�ڷ��μ�, 6.�����μ�)

1. �ڷ��߰�
Create_Data �Լ��� �̿��ؼ� �ڷḦ �Է¹޾�
Insert_Data �Լ��� �̿��ؼ� ������ �� Insert_Node �Լ��� �̿��Ͽ� ��ũ�� �����϶�. ��������� �������� ���ĵǵ��� �� ��
�迭�� �� ���ִ� ��� �ڷ��߰� ���Ѵٴ� �޽����� �������
���� ����� ��쵵 �޽����� ������
���������� ����� �� ����� ������ ��� ����Ѵ�

2. �ڷ����
��� �Ǵ� �̸����� �����ϵ��� ���� �޴� ����
���� �̸��� ��� ����

3. �ڷ����
����� �Է��ϸ� �̸�, ����, ����, ������ ������ �� �ִ�(��, ��� ���� �Ұ�)

4. ��ü�μ�
�� ����� ������ ��� ����Ѵ�

5. �ڷ��μ�
���� �޴� ���� �ʿ� (���, �̸�, ����, ����, ����, ���)
��� �Ǵ� �̸��� �Է��ϸ� �ش� �ڷḦ ��� �μ�
����, ����, ����, ����� �ΰ��� ��(�̻�, ����) �Է¹޾� �� �� �̻�~������ �ڷḦ ��� �μ�

6. �����μ�
���� �޴� ���� �ʿ� (���, �̸�, ����, ����, ����, ���, ��������, ��������)
�ش� �ڷḦ ���ϴ� ������� �����ؼ� �����

���α׷��� �����ϱ� ������ ��� ����ǵ��� �����

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

// �ڷ� �߰� / �迭�� �߰�, ��忡 �߰�
#if 1
int Insert_Data(STUDENT *p)
{
	// �迭�� �����Ͱ� ��������, -1
	// ���� ������ �迭�� ��Ҹ� ��ȯ.
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
	// return -1 : ��尡 �� ������ ��.
	// return 1 : ��� �߰� ���� ��
	// ������ id ����� -2

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

	printf("�����͸� �����մϴ�. ID, �̸�, ����,���� ���� ������ �������ּ���. \n");

	// �Է� ������ 1
	printf("ID : ");
	scanf("%d", &tmp.id);
	printf("�̸� : ");
	scanf("%s", tmp.name);
	printf("�������� : ");
	scanf("%d", &tmp.korean);
	printf("�������� : ");
	scanf("%d", &tmp.english);
	printf("�������� : ");
	scanf("%d", &tmp.math);
	tmp.next = NULL;
	tmp.prev = NULL;

	tmp.avg = (tmp.math + tmp.korean + tmp.english) / 3.0;
	if (Insert_Data(&tmp) < 0)
	{
		printf("��������� �����մϴ�.\n");
		return -1;
	}
	printf("�����͸� �迭�� ���������� �����߽��ϴ�.\n");
	id = Insert_Node(&Head, &tmp);
	if (id < 0)
	{
		printf("��������� �����մϴ�.\n");
		return -1;
	}
	Print_Node(&tmp);
	printf("�����͸� ��忡 ���������� �����߽��ϴ�.\n");
	return 1;
}
// �޴� ���
#if 1
void Print_Menu()
{
	printf("1 : �ڷ� �߰�\n");
	printf("2 : �ڷ� ����\n");
	printf("3 : �ڷ� ����\n");
	printf("4 : ��ü �μ�\n");
	printf("5 : �ڷ� �μ�\n");
	printf("6 : ���� �μ�\n");
}
#endif
#endif

// �ڷ� ����
#if 1
int Delete_Data(void)
{
	printf("��� �Ǵ� �̸��� ������ �ּ���. ���=1, �̸�=2\n");

	for (;;)
	{
		int sel = getch() - '0';
		switch (sel)
		{
		case 1: {
			int id;
			printf("ID�� �Է����ּ���. ");
			scanf("%d", &id);
			for (int i = 0; i < MAX_ST; i++)
			{
				if (students[i].id == 0) break;
				if (students[i].id == id){
					students[i].id = 0;
				}
			}
			//Update_Node(&Head);
		}break;
		case 2: {
			char name[12];
			printf("�̸��� �Է����ּ���. ");
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
}
#endif

// �ڷ� ����
#if 0
void Modify_Data(void)
{
	STUDENT p;
	int id;

	printf("����� �Է����ּ���. : \n");
	scanf("%d", &id);

	for (int i = 0; i < MAX_ST; i++)
	{
		if (students[i].id == id)
		{
			printf("������ �����͸� �Է����ּ���.\n");
			printf("�̸� : ");
			scanf("%s", p.name);
			printf("�������� : ");
			scanf("%d", &p.korean);
			printf("�������� : ");
			scanf("%d", &p.english);
			printf("�������� : ");
			scanf("%d", &p.math);
			return;
		}
	}
}
#endif

// ��� ������ ���
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
		//printf("ID : %d / Name : %s / ���� : %hd / ���� : %hd / ���� : %hd \n",
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
		printf("ID : %d / Name : %s / ���� : %hd / ���� : %hd / ���� : %hd \n",
			students[i].id, students[i].name, students[i].korean, students[i].english, students[i].math);
	}
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
		case 2: Delete_Data(); break;
		//case 3: Modify_Data(); break;
		case 4: Print_All_Node(&Head); break;
		//case 5: Print_Data(); break;
		//case 6: Print_Sorted_Data(); break;
		case 7: Print_All_Data(); break;
		default: printf("1~6�� ������ �޴��� �������ּ���.\n"); break;
		}
	}


	return 0;
}
#endif