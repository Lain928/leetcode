/*
	求两个数之和
	不用加减乘除
*/
#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	int res,carry;
	do
	{
		// 第一步：不考虑进位做加法（异或操作）
		res = num1^num2;

		// 第二步：考虑加法的进位（与运算+左移）
		carry = (num1&num2)<<1;

		// 第三步：第一步和第二步相加
		num1 = res;
		num2 = carry;

	}while(num2 != 0);

	cout<<num1<<endl;
	return num1;
}

int SumNum(int a, int b)
{
	return b ? SumNum(a^b, (a & b) << 1) : a;
}

//不进行重新的定义变量实现两个数字的替换
void ChangeNum(int a, int b)
{
	cout << a << "	"<< b << endl;
	a = a + b;
	b = a - b;
	a = a - b;
	cout << a << "	"<< b << endl;
}

int main()
{
	int a = 0;
	int b = 0;
	cout << "请输入两个数值" ;
	cin >> a >> b;

	cout << SumNum(a, b) << endl;


	ChangeNum(a, b);
	system("pause");
	return 0;
}