#include <iostream>
using namespace std;

//同样可以归结为跳台阶的问题
int Method2( int num )
{
	if (num <= 0)
		return 0;
	if (num == 1)
		return 1;
	if (num == 2)
		return 2;

	int first = 1;
	int second = 2;
	int third = 0;
	for (int i = 3; i <= num; i++)
	{
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}

int main()
{
	system("pause");
	return 0;
}