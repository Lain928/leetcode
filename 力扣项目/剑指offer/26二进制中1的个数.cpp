#include <iostream>
using namespace std;

int  NumberOf1(int n) 
{
	int num = 0;
	while(n != 0)
	{
		num ++;
		//&运算原理
		n &= (n -1);//每次都消除一个1
	}
	return num;
}

int main()
{
	system("pause");
	return 0;
}