#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//将数组A中的内容和数组B中的内容进行交换.(数组一样大)
void exchange(int arr1[5], int arr2[5], int sz)
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < sz; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}
void print(int arr[5], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int sz = 0;
	int arr1[5] = { 1, 3, 5, 7, 9 };
	int arr2[5] = { 2, 4, 6, 8, 10 };
	sz = sizeof(arr1) / sizeof(arr1[0]);
	exchange(arr1, arr2, sz);
	print(arr1, sz);
	print(arr2, sz);
	return 0;
}