/*
	��������֮��
	���üӼ��˳�
*/
#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	int res,carry;
	do
	{
		// ��һ���������ǽ�λ���ӷ�����������
		res = num1^num2;

		// �ڶ��������Ǽӷ��Ľ�λ��������+���ƣ�
		carry = (num1&num2)<<1;

		// ����������һ���͵ڶ������
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

//���������µĶ������ʵ���������ֵ��滻
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
	cout << "������������ֵ" ;
	cin >> a >> b;

	cout << SumNum(a, b) << endl;


	ChangeNum(a, b);
	system("pause");
	return 0;
}