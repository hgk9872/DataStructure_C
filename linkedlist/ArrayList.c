#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1; // 현재 데이터 없으므로 -1 (0아님)
}

void LInsert(List *plist, data data)
{
	if (plist->numOfData >= LIST_LEN) // 꽉찬 경우
	{
		printf("can not insert!\n");
		return;
	}

	plist->arr[plist->numOfData++] = data; // 데이터 저장 후 크기증가
}

int LFirst(List *plist, data *pdata)
{
	if (plist->numOfData == 0) // 저장된 데이터없는 경우
		return FALSE;

	plist->curPosition = 0;
	*pdata = plist->arr[plist->curPosition];

	return TRUE;
}

int LNext(List *plist, data *pdata)
{
	if (plist->curPosition == plist->numOfData-1) // 마지막 인덱스인 경우
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

	// 삭제인덱스 뒤 배열을 한칸씩 당겨오기 //
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

