#include <iostream>
using namespace std;

int JumpNum(int n)
{
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	int first = 1;

	for (int i = 2; i <= n; i++)
	{
		first *= 2;
	}
	return first;
}

int main()
{
	cout << JumpNum(5) << endl;

	system("pause");
	return 0;
}