#include <iostream>
using namespace std;

int JumpNum(int n)
{
	if (n <= 0)
		return 0;
	else if (n < 3)
		return n;
	int first = 2;
	int second = 3;
	int three = 0;

	for (int i = 4; i <= n; i++)
	{
		three = first + second;
		first = second;
		second = three;
	}
	return three;
}

int main()
{
	cout << JumpNum(5) << endl;

	system("pause");
	return 0;
}