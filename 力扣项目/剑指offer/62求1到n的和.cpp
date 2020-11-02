#include <iostream>
using namespace std;

class Slution
{
public:
	int SumFrom1ToN(int n);
protected:
private:
};

int Slution::SumFrom1ToN( int n )
{
	int ans = n;
	ans && (ans += SumFrom1ToN(n - 1));
	return ans;
}

int main()
{
	system("pause");
	return 0;
}