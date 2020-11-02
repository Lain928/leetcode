#include <iostream>
using namespace std;

class Slution
{
public:
	//使用递归的方式 时间复杂度：O(2^n) ，空间复杂度：O(n)
	int Method1(int num);
	//自底向上 迭代求解 时间复杂度：O(n) ，空间复杂度：O(1)
	int Method2(int num);
	//创建一个数组，每次将前两个数相加后直接赋给后一个数
	//所以空间复杂度为O(N)；时间复杂度为O(N)。
	int Method3(int num);
protected:
private:
};

int Slution::Method1(int num)
{
	if (num == 0)
		return 0;
	if (num == 1 || num == 2)
		return 1;
	else
		return Method1(num - 1) + Method1(num - 2);
}

int Slution::Method2( int num )
{
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;
	int first = 0;
	int second = 1;
	int third = 0;
	for (int i = 2; i <= num; i++)
	{
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}

int Slution::Method3( int num )
{
	//非递归
	int* array = new int[num+1];
	array[0] = 0;
	array[1] = 1;
	for (int i = 2; i <= num; i++)
	{
		array[i] = array[i-1] + array[i-2];
	}
	return array[num];
}

int main()
{


	system("pause");
	return 0;
}