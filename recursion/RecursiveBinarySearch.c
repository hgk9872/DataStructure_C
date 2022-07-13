#include <stdio.h>

int BSearch(int arr[], int first, int last, int target)
{
	int mid;

	if (first > last)
		return -1;     // 탐색 실패
	mid = (first + last)/2;

	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return BSearch(arr, first, mid-1, target);
	else
		return BSearch(arr, mid+1, last, target);
}

int main(void)
{
	int arr[] = {1, 3, 5, 7, 9, 11, 13};
	int idx; // target 값의 index

	idx = BSearch(arr, 0, sizeof(arr)/sizeof(int)-1, 13);
	if (idx == -1)
		printf("Cannot find! \n");
	else
		printf("target index = %d \n", idx);

	return 0;
}
