#if 0
/*
2017�� 8�� 22�� ��ũ������

1. �ڷ��� �𵨸�
�˸��� �ڷ��� Ÿ���� ���ϰ�, ����� �̸��� ����, ����ü�� Type �̸��� typedef �̿��Ͽ� PARTS �� ����
* ID : ��ȣ
* ��ǰ�� : ���ڿ�, ���� 20�ڱ��� �Է� ����
* ��ǰ ������ : ���ڿ�, ���� 10�ڱ��� �Է� ����
* �ܰ� : ����(�� ����), 1~4000000 ���� ���尡���ؾ� ��
* �������� : ����

�ش� �ڷḦ 20�� ������ �� �ִ� ��������Ʈ(�迭) �޸� ����


2. �ڷ���� �Է� �Լ� �ۼ� : int Parts_Create_Data(PARTS * p)
* parameter : PARTS * p -> �Է��ڷḦ ������ ����ü�� �ּ�
* function : ��ǰ�� ���� (ID, ��ǰ��, ������, �ܰ�, ��������)�� �Է¹޾� parameter�� ���޹��� p�� ����Ű��
�޸𸮿� ����
* return : �Է� ���� �� 1, ���� �� -1 (������ ���� ���������� ����)


3. ��������Ʈ�� �ڷ� �߰� �Լ� �ۼ� : int Parts_Insert_Data(PARTS * p)
* parameter : PARTS * p -> ��������Ʈ�� �߰� �� �ڷᱸ��ü�� �ּ�
* function : �ش� �ڷḦ ��������Ʈ�� �� ������ �߰� ��
* return : �߰� ���� �� ���� ����Ʈ �� �߰��� ��ġ�� ��� ��ȣ ����
����� ���� �� -1, �ش� ID ������ �̹� �ִ� ��� -2


4. ��������Ʈ�� Ư�� ��ȣ �ڷ� �μ� �Լ� �ۼ�: int Parts_Print_Data(int id)
* parameter : int id -> �μ��ϰ��� �ϴ� �ڷ��� ID
* function : �ش� ID�� �ڷ� ���
* return : ��� ���� �� 1, ��� ���� �� -1 (�ش� ID�� �ڷ� X)


5. Ư�� �ڷ� ���� �Լ� �ۼ� : int Parts_Delete_Data(int id)
* parameter : int id -> �����ϰ��� �ϴ� �ڷ��� ID (��ҹ�ȣ �ƴ�)
* function : �ش� id�� ���� �ڷ� ���� ( ���� �� �� ���� �ڷ�� ������ �Ѱ����� ��� - �ڷᰡ ����� ���� �����ǵ��� �ϱ� ����)
* return : ���� ���� �� 1, ���� ���� �� -1 ( �ش� �ڷᰡ ���� ���� �ʴ� ���)


6. ��ü �ڷ� ���� �Լ� �ۼ� : int Parts_Sort_All_Data(void)
* parameter : ����
* function : ��ü �ڷḦ ID ������ ���� �ǵ��� �� (Insertion Sort �̿�)
* return : ������ ��ü �������� �� return


7. ��ü �ڷ� ���� �Լ� �ۼ� : int Parts_Print_All_Data(void)
* parameter : ����
* function : ��ü �ڷḦ ȭ�鿡 ���
* return : �μ��� ��ü �������� �� return


8. ���� �����ϸ� �ڷḦ �߰��ϴ� �Լ� �ۼ� : int Parts_Insert_n_Sort_Data(PARTS * p)
* parameter : PARTS * p -> �߰��ϰ��� �ϴ� �ڷ�
* function : �ش� �ڷḦ ��������Ʈ�� �߰��ϵ�, ID �� ���Ļ��¸� �����ϵ��� ��
( ���� �� �Լ��� ��ü �ڷᰡ ���� �Ǿ��ִ� ��쿡�� ���������� ���� ���� ���� )
* return : �߰� ���� �� ���� ����Ʈ �� �߰��� ��ġ�� ��� ��ȣ ����
����� ���� �� -1, �ش� ID ������ �̹� �ִ� ��� -2


9. �� �Լ��� �̿��� ��ü � ���α׷� �ۼ�

�� �޴��� �Լ��� �����Ͽ�, �����Լ������� �޴��� ����� �ְ� ,
�ش� �޴��� ���� �� �� �� �޴��� �ش��ϴ� �Լ��� ȣ���ϴ� ������ ���α׷����� �ۼ�
�� �޴� ��� �Ϸ�� �ٽ� �������� ���ƿ�.

�� �޴� �Լ� ���� �� ������ ���� �Լ��� �̿�


- �޴� :

(1) ��ǰ �ڷ� �߰�(������ �ڸ��� �߰�) : void Parts_Insert_No_sort(void)
- �߰� �ڷḦ �Է¹޾�, �Է� �� ������ ��ǰ �ڷḦ �迭 ������ �ڸ��� �߰�
- �߰� ���� �� ���� �޽��� ���, �߰� ���� �� �߰� ���� �޽��� ���

(2) ��ǰ �ڷ� �߰� (���� ����) : void Parts_Insert_sort(void)
- �߰� �ڷḦ �Է¹޾�, �Է� �� ������ ��ǰ �ڷḦ ID������ ���ĵ� ���¿��� �߰�
- �߰� ���� �� ���� �޽��� ���, �߰� ���� �� �߰� ���� �޽��� ���

(3) ��ǰ ���� ��� : void Parts_Print_by_ID(void)
- ID�� �Է� �ް� �ش� ID �ڷḦ ���, �ش� ID �ڷ� ���� ��� ���� �޽��� ���

(4) ��ü ���� ���� : void Parts_Sort(void)
- ��ü ������ ���� �� �� ���ĵ� �������� ������ ���ĿϷ� �޽��� ���

(5) ��ü ����Ʈ ��� : void Parts_Print_All(void)
- ��ü �ڷḦ ������ִ� ���, �ڷ� ���� ��� - �ڷ���� �޽��� ���
*/
#endif

#if 0

#include <stdio.h>
#pragma warning( disable : 4996 )  
#define MAX_PARTS 20

typedef struct _parts{
	int id;
	char name[24];
	char made[12];
	int price;
	int cnt;
} PARTS;

PARTS parts[MAX_PARTS];
PARTS test_data[MAX_PARTS] = {
	{ 20, "gear", "korea", 100, 30},
	{ 19, "locker", "china", 101, 31 },
	{ 18, "chair", "korea", 102, 32 },
	{ 17, "mirror", "korea", 103, 33 },
	{ 16, "handle", "korea", 104, 34 },
	{ 15, "brake", "korea", 112, 35 },
	{ 14, "bolts", "korea", 113, 36 },
	{ 13, "trunk", "korea", 116, 37 },
	{ 12, "metal", "korea", 119, 38 },
	{ 10, "left-mirror", "korea", 122, 39 },
	{  9, "right-mirror", "korea", 127, 40 },
	{  8, "seats", "korea", 139, 45 },
	{  3, "sponge", "korea", 158, 48 }
};

int Parts_Create_Data(PARTS * p)
{
	// �Է� ���� �� 1, ���� �� -1
	printf("��ǰ�� ���� (ID, ��ǰ��, ������, �ܰ�, ��������)�� ��ȣ ������ �Է��Ͻÿ�.\n��� ����� �����Ͻÿ�.\n");
	scanf("%d %s %s %d %d", &p->id, p->name, p->made, &p->price, &p->cnt);

	return 1;
}

int Parts_Insert_Data(PARTS * p)
{
	// �߰� ���� �� ���� ����Ʈ �� �߰��� ��ġ�� ��� ��ȣ ����
	// ����� ���� �� - 1, �ش� ID ������ �̹� �ִ� ��� - 2

	if (parts[MAX_PARTS - 1].id != 0) return -1;
	for (int i = 0; i < MAX_PARTS; i++)
	{
		if (parts[i].id == p->id) return -2;
		if (parts[i].id != 0) continue;
		parts[i] = *p;
		return i;
	}
}


int Parts_Print_Data(int id)
{
	// ��� ���� �� 1, ��� ���� �� -1 (�ش� ID�� �ڷ� X)
	for (int i = 0; i < MAX_PARTS; i++)
	{
		if (parts[i].id == 0) return -1;
		if (parts[i].id == id)
		{
			printf("ID : %d\n", parts[i].id);
			printf("Part Name : %s\n", parts[i].name);
			printf("Made in : %s\n", parts[i].made);
			printf("price : %d\n", parts[i].price);
			printf("cnt : %d\n", parts[i].cnt);
			return 1;
		}
	}
	return -1;
}


int Parts_Delete_Data(int id)
{
	// ���� ���� �� 1, ���� ���� �� -1 ( �ش� �ڷᰡ ���� ���� �ʴ� ��� )
	if (parts[MAX_PARTS - 1].id == id){
		parts[MAX_PARTS - 1].id = 0;
		return 1;
	}
	for (int i = 0; i < MAX_PARTS; i++)
	{
		if (parts[i].id == id)
		{
			for (int j = i; j < MAX_PARTS; j++)
			{
				if (parts[j].id == 0) break;
				parts[j] = parts[j + 1];
			}
			return 1;
		}
	}

	return -1;

}


int Parts_Sort_All_Data(void)
{
	// ������ ��ü �������� �� return
	// ��ü �ڷḦ ID ������ ���� �ǵ��� �� (Insertion Sort �̿�)
	// ������������ �����Ѵ�.
	int i, j, k;
	PARTS tmp;
	for (i = 0; i < MAX_PARTS; i++)
	{
		if (parts[i].id == 0) return i;
		for (j = 0; j < i; j++)
		{
			if (parts[j].id > parts[i].id) break;
		}
		tmp = parts[i];
		for (k = i; k > j; k--)
		{
			parts[k] = parts[k - 1];
		}
		parts[j] = tmp;
	}
	return i;
}

int Parts_Print_All_Data(void)
{
	int i;
	for (i = 0; i < MAX_PARTS; i++)
	{
		if (parts[i].id == 0) break;
		printf("ID : %d | ", parts[i].id);
		printf("Part Name : %s | ", parts[i].name);
		printf("Made in : %s | ", parts[i].made);
		printf("price : %d | ", parts[i].price);
		printf("cnt : %d\n", parts[i].cnt);
	}
	return i;
}


int Parts_Insert_n_Sort_Data(PARTS * p)
{
	int i, j, max;
	// �߰� ���� �� ���� ����Ʈ �� �߰��� ��ġ�� ��� ��ȣ ����
	// ����� ���� �� - 1, �ش� ID ������ �̹� �ִ� ��� - 2
	if (parts[MAX_PARTS - 1].id != 0) return -1;

	for (max= 0; max < MAX_PARTS; max++)
	{
		if (parts[MAX_PARTS - 1].id != 0) break;
	}


	for (i = 0; i < MAX_PARTS; i++)
	{
		if (parts[i].id == p->id) return -2;
		if (parts[i].id > p->id)
		{
			for (j = max; i > i; i--)
			{
				parts[j] = parts[j - 1];
			}
			parts[i] = *p;
			return i;
		}
	}
	return -1;
}


void Parts_Insert_No_sort(void)
{
	PARTS tmp;
	if (Parts_Create_Data(&tmp) > 0)
	{
		int result = Parts_Insert_Data(&tmp);
		switch (result)
		{
		case -1: printf("���� ������ �����մϴ�.\n"); break;
		case -2: printf("�ش� ������ �̹� �����մϴ�.\n"); break;
		default:
			printf("�����Ͱ� ���������� %d��° ��ġ�� ����Ǿ����ϴ�.!\n", result+1);
			break;
		}
	}
}


void Parts_Insert_sort(void)
{
	// �߰� �ڷḦ �Է¹޾�, �Է� �� ������ ��ǰ �ڷḦ ID������ ���ĵ� ���¿��� �߰�
	// �߰� ���� �� ���� �޽��� ���, �߰� ���� �� �߰� ���� �޽��� ���

	PARTS tmp;
	Parts_Sort_All_Data();
	if (Parts_Create_Data(&tmp) > 0)
	{
		int result = Parts_Insert_n_Sort_Data(&tmp);
		switch (result)
		{
		case -1: printf("���� ������ �����մϴ�.\n"); break;
		case -2: printf("�ش� ������ �̹� �����մϴ�.\n"); break;
		default:
			printf("�����Ͱ� ���������� %d��° ��ġ�� ����Ǿ����ϴ�.!\n", result+1);
			break;
		}
	}
}


void Parts_Print_by_ID(void)
{
	int id;
	printf("ID �� �Է����ּ��� : ");
	scanf("%d", &id);
	if (Parts_Print_Data(id) > 0) return;
	printf("��ȸ�� �����Ͽ����ϴ�.\n");
}


void Parts_Sort(void)
{
	printf("%d���� �����Ͱ� ���ĵǾ����ϴ�.\n", Parts_Sort_All_Data());
}

void Parts_Print_All(void)
{
	if (Parts_Print_All_Data() < 1)
	{
		printf("�ڷ� ����..\n");
	}
}


void Print_Menu(void)
{
	printf("1 : ��ǰ �ڷ� �߰�(������ �ڸ��� �߰�)\n");
	printf("2 : ��ǰ �ڷ� �߰� (���� ����)\n");
	printf("3 : ��ǰ ���� ���\n");
	printf("4 : ��ü ���� ����\n");
	printf("5 : ��ü ����Ʈ ���\n");
}


void make_test_data(int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		parts[i] = test_data[i];
	}
}

int main(void){


	make_test_data(12);

	int sel;
	while (1)
	{
		Print_Menu();
		sel = getch() - '0';
		switch (sel)
		{
			case 1: Parts_Insert_No_sort(); break;
			case 2: Parts_Insert_sort(); break;
			case 3: Parts_Print_by_ID(); break;
			case 4: Parts_Sort(); break;
			case 5: Parts_Print_All(); break;
			default: break;
		}
	}


	return 0;
}


#endif