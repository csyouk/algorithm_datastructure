#if 0
/*
2017년 8월 22일 워크샵문제

1. 자료의 모델링
알맞은 자료의 타입을 정하고, 멤버의 이름도 결정, 구조체의 Type 이름은 typedef 이용하여 PARTS 로 설정
* ID : 번호
* 부품명 : 문자열, 영문 20자까지 입력 가능
* 부품 생산지 : 문자열, 영문 10자까지 입력 가능
* 단가 : 가격(원 단위), 1~4000000 까지 저장가능해야 함
* 보유수량 : 갯수

해당 자료를 20개 저장할 수 있는 순차리스트(배열) 메모리 생성


2. 자료생성 입력 함수 작성 : int Parts_Create_Data(PARTS * p)
* parameter : PARTS * p -> 입력자료를 저장할 구조체의 주소
* function : 부품의 정보 (ID, 부품명, 생산지, 단가, 보유수량)을 입력받아 parameter로 전달받은 p가 가리키는
메모리에 저장
* return : 입력 성공 시 1, 실패 시 -1 (실패의 경우는 없을것으로 예상)


3. 순차리스트에 자료 추가 함수 작성 : int Parts_Insert_Data(PARTS * p)
* parameter : PARTS * p -> 순차리스트에 추가 할 자료구조체의 주소
* function : 해당 자료를 순차리스트의 빈 공간에 추가 함
* return : 추가 성공 시 순차 리스트 상 추가된 위치의 요소 번호 리턴
빈공간 없을 시 -1, 해당 ID 정보가 이미 있는 경우 -2


4. 순차리스트에 특정 번호 자료 인쇄 함수 작성: int Parts_Print_Data(int id)
* parameter : int id -> 인쇄하고자 하는 자료의 ID
* function : 해당 ID의 자료 출력
* return : 출력 성공 시 1, 출력 실패 시 -1 (해당 ID의 자료 X)


5. 특정 자료 삭제 함수 작성 : int Parts_Delete_Data(int id)
* parameter : int id -> 삭제하고자 하는 자료의 ID (요소번호 아님)
* function : 해당 id를 가진 자료 삭제 ( 삭제 후 그 뒤의 자료는 앞으로 한공간씩 당김 - 자료가 빈공간 없이 나열되도록 하기 위함)
* return : 삭제 성공 시 1, 삭제 실패 시 -1 ( 해당 자료가 존재 하지 않는 경우)


6. 전체 자료 정렬 함수 작성 : int Parts_Sort_All_Data(void)
* parameter : 없음
* function : 전체 자료를 ID 순서로 정렬 되도록 함 (Insertion Sort 이용)
* return : 정렬한 전체 데이터의 수 return


7. 전체 자료 정렬 함수 작성 : int Parts_Print_All_Data(void)
* parameter : 없음
* function : 전체 자료를 화면에 출력
* return : 인쇄한 전체 데이터의 수 return


8. 정렬 유지하며 자료를 추가하는 함수 작성 : int Parts_Insert_n_Sort_Data(PARTS * p)
* parameter : PARTS * p -> 추가하고자 하는 자료
* function : 해당 자료를 순차리스트에 추가하되, ID 순 정렬상태를 유지하도록 함
( 물론 이 함수는 전체 자료가 정렬 되어있는 경우에만 정상적으로 동작 함을 가정 )
* return : 추가 성공 시 순차 리스트 상 추가된 위치의 요소 번호 리턴
빈공간 없을 시 -1, 해당 ID 정보가 이미 있는 경우 -2


9. 위 함수를 이용한 전체 운영 프로그램 작성

각 메뉴는 함수로 구성하여, 메인함수에서는 메뉴를 출력해 주고 ,
해당 메뉴를 선택 할 시 각 메뉴에 해당하는 함수를 호출하는 형태의 프로그램으로 작성
각 메뉴 기능 완료시 다시 메인으로 돌아옴.

각 메뉴 함수 구현 시 위에서 만든 함수를 이용


- 메뉴 :

(1) 부품 자료 추가(마지막 자리에 추가) : void Parts_Insert_No_sort(void)
- 추가 자료를 입력받아, 입력 된 내용의 부품 자료를 배열 마지막 자리에 추가
- 추가 성공 시 성공 메시지 출력, 추가 실패 시 추가 실패 메시지 출력

(2) 부품 자료 추가 (정렬 유지) : void Parts_Insert_sort(void)
- 추가 자료를 입력받아, 입력 된 내용의 부품 자료를 ID순으로 정렬된 상태에서 추가
- 추가 성공 시 성공 메시지 출력, 추가 실패 시 추가 실패 메시지 출력

(3) 부품 내용 출력 : void Parts_Print_by_ID(void)
- ID를 입력 받고 해당 ID 자료를 출력, 해당 ID 자료 없을 경우 실패 메시지 출력

(4) 전체 내용 정렬 : void Parts_Sort(void)
- 전체 내용을 정렬 한 후 정렬된 데이터의 갯수와 정렬완료 메시지 출력

(5) 전체 리스트 출력 : void Parts_Print_All(void)
- 전체 자료를 출력해주는 기능, 자료 없을 경우 - 자료없음 메시지 출력
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
	// 입력 성공 시 1, 실패 시 -1
	printf("부품의 정보 (ID, 부품명, 생산지, 단가, 보유수량)를 괄호 순으로 입력하시오.\n띄어 쓰기로 구분하시오.\n");
	scanf("%d %s %s %d %d", &p->id, p->name, p->made, &p->price, &p->cnt);

	return 1;
}

int Parts_Insert_Data(PARTS * p)
{
	// 추가 성공 시 순차 리스트 상 추가된 위치의 요소 번호 리턴
	// 빈공간 없을 시 - 1, 해당 ID 정보가 이미 있는 경우 - 2

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
	// 출력 성공 시 1, 출력 실패 시 -1 (해당 ID의 자료 X)
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
	// 삭제 성공 시 1, 삭제 실패 시 -1 ( 해당 자료가 존재 하지 않는 경우 )
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
	// 정렬한 전체 데이터의 수 return
	// 전체 자료를 ID 순서로 정렬 되도록 함 (Insertion Sort 이용)
	// 오름차순으로 정렬한다.
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
	// 추가 성공 시 순차 리스트 상 추가된 위치의 요소 번호 리턴
	// 빈공간 없을 시 - 1, 해당 ID 정보가 이미 있는 경우 - 2
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
		case -1: printf("저장 공간이 부족합니다.\n"); break;
		case -2: printf("해당 정보가 이미 존재합니다.\n"); break;
		default:
			printf("데이터가 성공적으로 %d번째 위치에 저장되었습니다.!\n", result+1);
			break;
		}
	}
}


void Parts_Insert_sort(void)
{
	// 추가 자료를 입력받아, 입력 된 내용의 부품 자료를 ID순으로 정렬된 상태에서 추가
	// 추가 성공 시 성공 메시지 출력, 추가 실패 시 추가 실패 메시지 출력

	PARTS tmp;
	Parts_Sort_All_Data();
	if (Parts_Create_Data(&tmp) > 0)
	{
		int result = Parts_Insert_n_Sort_Data(&tmp);
		switch (result)
		{
		case -1: printf("저장 공간이 부족합니다.\n"); break;
		case -2: printf("해당 정보가 이미 존재합니다.\n"); break;
		default:
			printf("데이터가 성공적으로 %d번째 위치에 저장되었습니다.!\n", result+1);
			break;
		}
	}
}


void Parts_Print_by_ID(void)
{
	int id;
	printf("ID 를 입력해주세요 : ");
	scanf("%d", &id);
	if (Parts_Print_Data(id) > 0) return;
	printf("조회에 실패하였습니다.\n");
}


void Parts_Sort(void)
{
	printf("%d개의 데이터가 정렬되었습니다.\n", Parts_Sort_All_Data());
}

void Parts_Print_All(void)
{
	if (Parts_Print_All_Data() < 1)
	{
		printf("자료 없음..\n");
	}
}


void Print_Menu(void)
{
	printf("1 : 부품 자료 추가(마지막 자리에 추가)\n");
	printf("2 : 부품 자료 추가 (정렬 유지)\n");
	printf("3 : 부품 내용 출력\n");
	printf("4 : 전체 내용 정렬\n");
	printf("5 : 전체 리스트 출력\n");
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