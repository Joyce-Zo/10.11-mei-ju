#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

								枚举
	枚举类型
enum Sex
{
	  枚举的可能取值 - 枚举常量
	Male=2,	//  初始化，赋予初始值，此后将不能再被修改
	Female=4,
	Baby,	// 如果其没有被初始化，则是前面的值4+1=5 
	Secret=8
};

enum Color
{
	Red,
	Green,
	Blue
};

#define Red 2
#define Green 2
#define Blue 2
 枚举的优点
1.增加代码的可读性和可维护性
2.和#define定义的标识符比较枚举有类型检查，更加严谨。
3.防止了命名污染（封装|重复)
4.便于调试
5.使用方便，一次可以定义多个常量
int main()
{
	enum Sex s = Male;
	enum Color c = Red;
	enum Color d = 2;// 报错，左边是enum Color类型，右边是int类型，不能直接赋值
	printf("%d %d %d \n", Red, Green, Blue);
						0    1      2  取值默认从0开始，依次递增1
	printf("%d %d %d %d ", Male, Female, Baby,Secret);
							2     4       5      8
	return 0;
}

							联合
				联合体 = 共用体
union Un
{
	char a;
	int c;			//  不同的变量，共用同一块空间
	double b;		//  因此，每个变量之间不能同时存在，要么用a要么用bcd
	double d;
};
int main()
{
	union Un u;
	printf("%d\n ", sizeof(u));// 联合体大小至少是最大成员的大小，此处为double的大小
	printf("%d\n ", sizeof(u.a));
	printf("%d\n ", sizeof(u.c));

	printf("%p\n ", &(u));
	printf("%p\n ", &(u.a));
	printf("%p\n ", &(u.c));
	return 0;
}

int check_sys(int a)
{
	 1.
	return *(char*)&a;
	2.
	union un
	{
		char a;
		int b;
	}u;
	u.b = 1;
	return u.a;
}
int main()
{
	int a = 1;
	a = (char)1;
	int ret=*(char*)&a;
	int ret=check_sys(a);
	if (ret == 1)
	{
		printf("小端");
	}
	else
	{
		printf("大");
	}
	printf("%d ", a);
	return 0;
}

int main()
{
	int a[10] = { 10 * 1 };
	printf("%d", a);
	return 0;
}

union un
{
	int a;	
	char arr[5] = { 0 };
	 当最大成员（数组arr5）5不是最大对齐数4的整数倍时，对齐到最大对其数的整数倍
	   数组的最大对齐数时他的成员（char）大小，不是其总大小
}u;
int main()
{
	printf("%d ", sizeof(u));
	return 0;
}