#include <iostream>
using namespace std;

int  NumberOf1(int n) 
{
	int num = 0;
	while(n != 0)
	{
		num ++;
		//&����ԭ��
		n &= (n -1);//ÿ�ζ�����һ��1
	}
	return num;
}

int main()
{
	system("pause");
	return 0;
}