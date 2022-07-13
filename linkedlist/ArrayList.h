#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef int data;

typedef struct __ArrayList
{
	data arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List *plist);
void LInsert(List *plist, data data);

int LFirst(List *plist, data *pdata);
int LNext(List *plist, data *pdata);

data LRemove(List *plist);
int LCount(List *plist);

#endif
