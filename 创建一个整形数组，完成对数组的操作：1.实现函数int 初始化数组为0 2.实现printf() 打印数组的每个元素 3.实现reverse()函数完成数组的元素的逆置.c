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
int main()//����һ���������飬��ɶ�����Ĳ�����1.ʵ�ֺ���int ��ʼ������Ϊ0 2.ʵ��printf() ��ӡ�����ÿ��Ԫ�� 3.ʵ��reverse()������������Ԫ�ص�����
{
	int sz = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	sz = sizeof(arr) / sizeof(arr[0]);
	//init(arr, sz);//��ʼ��
	print(arr, sz);
	printf("\n");
	reverse(arr, sz);//���ú���
	print(arr, sz);
	return 0;
}