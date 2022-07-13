#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1; // ���� ������ �����Ƿ� -1 (0�ƴ�)
}

void LInsert(List *plist, data data)
{
	if (plist->numOfData >= LIST_LEN) // ���� ���
	{
		printf("can not insert!\n");
		return;
	}

	plist->arr[plist->numOfData++] = data; // ������ ���� �� ũ������
}

int LFirst(List *plist, data *pdata)
{
	if (plist->numOfData == 0) // ����� �����;��� ���
		return FALSE;

	plist->curPosition = 0;
	*pdata = plist->arr[plist->curPosition];

	return TRUE;
}

int LNext(List *plist, data *pdata)
{
	if (plist->curPosition == plist->numOfData-1) // ������ �ε����� ���
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	
	return TRUE;
}

int LRemove(List *plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	data rdata = plist->arr[plist->curPosition];

	// �����ε��� �� �迭�� ��ĭ�� ��ܿ��� //
	for (i = rpos; i < num-1; i++)
		plist->arr[i] = plist->arr[i+1];

	(plist->numOfData)--;
	(plist->curPosition)--;

	return rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}

