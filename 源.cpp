#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

								ö��
	ö������
enum Sex
{
	  ö�ٵĿ���ȡֵ - ö�ٳ���
	Male=2,	//  ��ʼ���������ʼֵ���˺󽫲����ٱ��޸�
	Female=4,
	Baby,	// �����û�б���ʼ��������ǰ���ֵ4+1=5 
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
 ö�ٵ��ŵ�
1.���Ӵ���Ŀɶ��ԺͿ�ά����
2.��#define����ı�ʶ���Ƚ�ö�������ͼ�飬�����Ͻ���
3.��ֹ��������Ⱦ����װ|�ظ�)
4.���ڵ���
5.ʹ�÷��㣬һ�ο��Զ���������
int main()
{
	enum Sex s = Male;
	enum Color c = Red;
	enum Color d = 2;// ���������enum Color���ͣ��ұ���int���ͣ�����ֱ�Ӹ�ֵ
	printf("%d %d %d \n", Red, Green, Blue);
						0    1      2  ȡֵĬ�ϴ�0��ʼ�����ε���1
	printf("%d %d %d %d ", Male, Female, Baby,Secret);
							2     4       5      8
	return 0;
}

							����
				������ = ������
union Un
{
	char a;
	int c;			//  ��ͬ�ı���������ͬһ��ռ�
	double b;		//  ��ˣ�ÿ������֮�䲻��ͬʱ���ڣ�Ҫô��aҪô��bcd
	double d;
};
int main()
{
	union Un u;
	printf("%d\n ", sizeof(u));// �������С����������Ա�Ĵ�С���˴�Ϊdouble�Ĵ�С
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
		printf("С��");
	}
	else
	{
		printf("��");
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
	 ������Ա������arr5��5������������4��������ʱ�����뵽����������������
	   �������������ʱ���ĳ�Ա��char����С���������ܴ�С
}u;
int main()
{
	printf("%d ", sizeof(u));
	return 0;
}