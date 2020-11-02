#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
using namespace std;

/*
约瑟夫环问题
*/
class Slution
{
public:
	int LastPeople(int n, int m);
protected:
private:
};

int Slution::LastPeople( int n, int m )
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	int last = 0;
	for (int i = 2; i <= n; i++)
	{
		last = (last + m) % i;
		cout << last << endl;
	}
	return last;
}


int main()
{
	Slution slu;
	slu.LastPeople(10,4);
	system("pause");
	return 0;
}