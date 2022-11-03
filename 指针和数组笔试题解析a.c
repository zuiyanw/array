#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()//指向函数指针数组 的指针
{ 
	//数组名是首元素的地址
	//1.sizeof(数组名) - 数组名表示整个数组
	//2.&数组名 - 数组名表示整个数组
	//一维数组
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//4*4=16 sizeof(数组名) - 计算的是数组的总大小-单位是字节 - 16
	printf("%d\n", sizeof(a + 0));//4/8  a-这里表示首元素地址 因为是32位系统 显示4
	printf("%d\n", sizeof(*a));//4  a是首元素地址 解引用a找到 1-int-4个字节
	printf("%d\n", sizeof(a + 1));//4/8  a是首元素地址 +1找到下一个元素的地址 也是4/8
	printf("%d\n", sizeof(a[1]));//4 2的大小-int-4
	printf("%d\n", sizeof(&a));//&a取出的是数组的地址  4/8 
	printf("%d\n", sizeof(*&a));//16 &a是数组的地址 数组的地址解引用访问的是数组 sizeof(数组名) 
	printf("%d\n", sizeof(&a + 1));//4/8  &a-数组的地址 +1跳过一个数组的大小 还是地址
	printf("%d\n", sizeof(&a[0]));//4/8  a[0]=1   1的地址 4/8
	printf("%d\n", sizeof(&a[0] + 1));//4/8  a[0]=1    +1为'2'的地址 4/8
	//字符数组
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));// 6 sizeof(数组名) - 计算整个数组的大小 -单位是字节
	printf("%d\n", sizeof(arr + 0));// 4/8 arr是首元素地址 地址+0  地址的大小都是4/8
	printf("%d\n", sizeof(*arr));//1 对首元素地址解引用-找到'a'-char是一个字节
	printf("%d\n", sizeof(arr[1]));//1 ‘b’的大小-char-1
	printf("%d\n", sizeof(&arr));//&arr-取出的是数组的地址- 4/8  指针大小有不同  地址大小都是4/8
	printf("%d\n", sizeof(&arr + 1));// 取出的是数组的地址  +1为跳过一个数组的大小  4/8
	printf("%d\n", sizeof(&arr[0] + 1));//a的地址  地址+1——>b的地址  地址：4/8

	//1.sizeof和strlen()没有联系
	//2.strlen()只跟字符串有关，计算字符串的长度 - 库函数 - string.h
	//3.sizeof 计算变量，数组，类型的大小 - 单位是字节 - 操作符


	printf("%d\n", strlen(arr));//随机数 找不到'\0'
	printf("%d\n", strlen(arr + 0));//arr为首元素地址  +0还是首元素地址 与strlen(arr)相同 还是随机值
	// printf("%d\n", strlen(*arr));  //对首元素的地址解引用-找到‘a’  strlen('a') a的ASCII码值是97  
	// strlen的参数接收的是一个地址  然后就会把97当作地址然后从97的起始位置查找字符  属于非法访问内存  程序崩溃
	// printf("%d\n", strlen(arr[1]));  //程序崩溃 ‘b’ 98 也是当作地址
	printf("%d\n", strlen(&arr));//取出的是数组的地址 数组的地址还是从'a'开始数字符 依旧找不到'\0'
	printf("%d\n", strlen(&arr + 1));//数组的地址+1 跳过一个数组的大小 依旧是随机值 但是因为跳过了一个数组的大小 等于少数了6个元素 则比上一个少6-1个char是一个字节
	printf("%d\n", strlen(&arr[0] + 1));//&arr[0]-取出的是a的地址  地址+1——>找到了b的地址  然后从b的地址向后数 依旧是随机数 少数了a 则比上上个少了1

	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//计算的是数组的大小-a b c d e f /0 7个元素-每个元素1个字节-7
	printf("%d\n", sizeof(arr + 0));//4/8  首元素地址+0
	printf("%d\n", sizeof(*arr));//对首元素地址解引用-a-char类型-1
	printf("%d\n", sizeof(arr[1]));//b-1 arr[1]是第二个元素
	printf("%d\n", sizeof(&arr));//&arr取出的是整个数组的地址  4/8
	printf("%d\n", sizeof(&arr + 1));//新的地址 跳过一个数组的大小 4/8
	printf("%d\n", sizeof(&arr[0] + 1));//a的地址+1 找到b的地址-4/8

	printf("%d\n", strlen(arr));//arr是首元素地址 从a开始向后数 遇到\0停止 -6  
	printf("%d\n", strlen(arr + 0));//首元素地址+0还是首元素地址 -6
	//printf("%d\n", strlen(*arr));//对首元素地址解引用-a-a的ASCII码值97 非法访问 -程序崩溃
	//printf("%d\n", strlen(arr[1]));//b-98-非法访问-程序崩溃
	printf("%d\n", strlen(&arr));//&arr-数组的地址-应该存在数组指针中 char(*p)[7]-char(*)[7]  
	// strlen(const char* str)  可以运行 但会出警告  从首元素地址开始访问 - 遇到\0停止 - 6
	printf("%d\n", strlen(&arr + 1));//&arr 取出的是数组的地址 +1跳过一个数组的大小 \0后面开始数-随机值
	printf("%d\n", strlen(&arr[0] + 1));// &a-a的地址+1-找到b的地址-向后访问 5

	char *p = "abcdef";//p里面放的是‘a’的地址因为p是地址 最多只能放4个字节 不可能把所有的元素都放进去  
	printf("%d\n", sizeof(p));//计算指针变量p的大小-a的地址-4/8
	printf("%d\n", sizeof(p + 1));//a的地址+1-找到b的地址  4/8
	printf("%d\n", sizeof(*p));//*p-对指针解引用-找到字符'a'-char*-1
	printf("%d\n", sizeof(p[0]));// 例：int arr[10]={0}; arr[0] == *(arr+0) 右边的arr为首元素地址 +0还是为首元素地址
	// p[0]=*(p+0)  p为a的地址  *p == 'a'  1
	printf("%d\n", sizeof(&p));// 取出变量p的地址 4/8
	printf("%d\n", sizeof(&p + 1));//4/8
	printf("%d\n", sizeof(&p[0] + 1));//4/8  p[0]=*(p+0)='a'  &a取出a的地址+1 - b的地址 4/8
	
	
	printf("%d\n", strlen(p));//p-取出的是a的地址-6
	printf("%d\n", strlen(p + 1));//p+1得到的字符b的地址 5
	//printf("%d\n", strlen(*p));//对首元素解引用-a-97-非法访问-系统崩溃
	//printf("%d\n", strlen(p[0]));//p[0]=*(p+0)=='a'  -97-非发访问-系统崩溃
	printf("%d\n", strlen(&p));//p放的是a的地址 假设a的地址是 0x11003344 在内存中的存储方式 如小端：0x4433001
	//4 4 3 3只有4 假设是大端为1   随机值
	printf("%d\n", strlen(&p + 1));//同上 随机值
	printf("%d\n", strlen(&p[0] + 1));//p[0]=*(p+0)=='a'  &a+1-找到'b'的地址-从b开始数 5

	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));// sizeof(a)-整个数组的大小 3*4=12
	printf("%d\n", sizeof(a[0][0]));//首元素-int-4个字节
	printf("%d\n", sizeof(a[0]));//a[0]相当于第1行作为一维数组的数组名,
	//sizeof(a[0])相当于计算第一行的大小-4个元素-16  第二行是a[1]  第三行为a[2]
	
	printf("%d\n", sizeof(a[0] + 1));//a[0]是第一行的数组名-数组名此时是首元素的地址-  所以+1为第一行第二个首元素的地址
	printf("%d\n", sizeof(*(a[0] + 1)));//第一行第二个元素的大小 -4
	printf("%d\n", sizeof(a + 1));//首元素(a[0])的地址+1 跳过一个数组的大小-第二行数组的地址 4/8
	//a为二维数组的数组名 因为没有sizeof(数组名)和&a 所以为首元素地址(第一行数组的地址)
	printf("%d\n", sizeof(*(a + 1)));//a为首元素的地址(第一行数组的地址) +1为第2个行的地址-解引用找到第二行的数组-int-16
	printf("%d\n", sizeof(&a[0] + 1));//a[0]为第一行数组的数组名-&(数组名)-为第一行整个数组的地址  +1-跳过一个数组的地址  4/8
	printf("%d\n", sizeof(*(&a[0] + 1)));//第二行的地址解引用-16
	printf("%d\n", sizeof(*a));//a为首元素地址-a[0]整个数组的地址-解引用-16
	printf("%d\n", sizeof(a[3]));//a[3]为第四行的数组名 sizeof(数组名)-计算整个数组的大小 sizeof()本身不计算不去访问 只根据类型计算大小 	//a[3]在这里等同与a[0] -16                                               

	return 0;
}
 