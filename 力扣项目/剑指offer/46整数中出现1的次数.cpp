#include <iostream>
using namespace std;

//求出整数区间内出现1的次数
class Slution
{
public:
	int NumOfOne(int num);
protected:
private:
};

int Slution::NumOfOne( int num )
{
	//统计次数
	int count = 0;
	for (int i =1; i <= num; i *= 10)
	{
		//计算高低位
		int a = num / i;
		int b = num % i;
		count += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
	}
	return count;

}


int main()
{


	system("pause");
	return 0;
}