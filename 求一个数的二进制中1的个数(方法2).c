#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count_bite_1(unsigned int n)//针对负数 将负数的原码转化成无符号数
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
int main()//求一个数的二进制中1的个数
{
	int n = 0;
	scanf("%d", &n);
	int count=count_bite_1(n);
	printf("%d", count);
	return 0;
}