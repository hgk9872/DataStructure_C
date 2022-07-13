#include <stdio.h>
#include "ArrayList.h" // �迭 ��� ��ũ�帮��Ʈ

int main(void)
{
	// ArrayList ���� �� �ʱ�ȭ //
	List list;
	int data;
	ListInit(&list);

	// ������ ���� //
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 33);

	// ����Ʈ�� ����� ������ ��� //
	printf("Number of data in list : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// ����Ʈ�� ����� Ư�� ������ ��� ���� //
	if (LFirst(&list, &data))
	{
		if (data == 11)
			LRemove(&list); // LFirst�� LNext�� ������ ��ȯ ������ ����

		while (LNext(&list, &data))
		{
			if (data == 11)
				LRemove(&list);
		}
	}

	// ���� �� ����Ʈ�� ������ �ٽ� ��� //
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
