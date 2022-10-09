#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void init(int arr[10], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}
void print(int arr[10], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void reverse(int arr[10], int sz)
{
	int left = 0;
	int right = sz-1;
	while (left<right)
	{
		int tmp = 0;
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
int main()//创建一个整形数组，完成对数组的操作：1.实现函数int 初始化数组为0 2.实现printf() 打印数组的每个元素 3.实现reverse()函数完成数组的元素的逆置
{
	int sz = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	sz = sizeof(arr) / sizeof(arr[0]);
	//init(arr, sz);//初始化
	print(arr, sz);
	printf("\n");
	reverse(arr, sz);//逆置函数
	print(arr, sz);
	return 0;
}