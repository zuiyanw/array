#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count_bite_1(unsigned int n)//��Ը��� ��������ԭ��ת�����޷�����
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n = n / 2;
	}
	return count;
}
int main()//��һ�����Ķ�������1�ĸ���
{
	int n = 0;
	scanf("%d", &n);
	int count=count_bite_1(n);
	printf("%d", count);
	return 0;
}