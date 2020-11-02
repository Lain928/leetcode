#include <iostream>
#include <vector>
using namespace std;

/*
丑数：我们把只包含因子2、3和5的数称作丑数

一一遍历法：时间效率低下

　使用遍历法求第k个丑数，从1开始遍历，如果是丑数则count++，直到count=k为止。那么如何判断丑数呢？

  根据丑数的定义，丑数只有2，3，5这三个因子，那么我们就拿数字除以这三个因子。具体算法如下：

  Step1.如果一个数能够被2整除，那么让他继续除以2；

  Step2.如果一个数能够被3整除，那么让他继续除以3；

  Step3.如果一个数能够被5整除，那么让他继续除以5；

  Step4.如果最后这个数变为1，那么这个数就是丑数，否则不是。

  2.2 空间换时间法：时间效率较高

  　根据丑数的定义，我们可以知道丑数可以由另外一个丑数乘以2，3或者5得到。
	
	因此我们可以创建一个数组，里面的数字是排好序的丑数，每一个丑数都是前面的丑数乘以2，3或者5得到的。

	我们把得到的第一个丑数乘以2以后得到的大于M的结果记为M2。同样，我们把已有的每一个丑数乘以3和5，能得到第一个大于M的结果M3和M5。
	
	那么M后面的那一个丑数应该是M2,M3和M5当中的最小值：Min(M2,M3,M5)。
	
	比如将丑数数组中的数字按从小到大乘以2，直到得到第一个大于M的数为止，那么应该是2*2=4<M，3*2=6>M，所以M2=6。同理，M3=6，M5=10。所以下一个丑数应该是6。
*/


//求第k个丑数
class Slution
{
public:
	int NormalAlgorithm(int index);

	int GetUglyNumber(int index);
protected:
private:
	bool IsUhly(int number);
	int MinNum(int n1, int n2,int n3);
};

int Slution::NormalAlgorithm( int index )
{
	if (index <= 0)
		return 0;
	int num = 0;
	int NumCount = 0;
	while (index > NumCount)
	{
		num++;
		if (IsUhly(num))
			NumCount++;
	}
	return num;
}

bool Slution::IsUhly( int number )
{
	while (number % 2 == 0)
		number /= 2;

	while (number % 3 == 0)
		number /= 3;

	while (number % 5 == 0)
		number /= 5;

	return (number == 1) ? true : false;
}

int Slution::GetUglyNumber( int index )
{
	if (index <= 0)
		return 0;
	vector<int> res(index);
	for (int i = 0; i < 6; i++)
	{
		res[i] = i + 1;
	}
	int t2 = 3;
	int t3 = 2;
	int t5 = 1;

	for (int i = 0; i < index;i++)
	{
		res[i] = min(res[t2] * 2,min(res[t3] * 3,res[t5] * 5));

		while (res[i] >= res[t2] * 2)
		{
			t2++;
		}
		while (res[i] >= res[t3] * 3)
		{
			t3++;
		}
		while (res[i] >= res[t5] * 5)
		{
			t5++;
		}
	}
	return res[index - 1];
}

int main()
{

	Slution slu;
	cout << slu.NormalAlgorithm(7) << endl; 

	system("pause");
	return 0;
}