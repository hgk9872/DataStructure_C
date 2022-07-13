#include <stdio.h>
#include "ArrayList.h" // 배열 기반 링크드리스트

int main(void)
{
	// ArrayList 생성 및 초기화 //
	List list;
	int data;
	ListInit(&list);

	// 데이터 저장 //
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 33);

	// 리스트에 저장된 데이터 출력 //
	printf("Number of data in list : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// 리스트에 저장된 특정 데이터 모두 삭제 //
	if (LFirst(&list, &data))
	{
		if (data == 11)
			LRemove(&list); // LFirst와 LNext의 마지막 반환 데이터 삭제

		while (LNext(&list, &data))
		{
			if (data == 11)
				LRemove(&list);
		}
	}

	// 삭제 후 리스트의 데이터 다시 출력 //
	printf("Num of data after remove : %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}

	printf("\n\n");

	return 0;
}
