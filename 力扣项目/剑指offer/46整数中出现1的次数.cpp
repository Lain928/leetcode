#include <iostream>
using namespace std;

//������������ڳ���1�Ĵ���
class Slution
{
public:
	int NumOfOne(int num);
protected:
private:
};

int Slution::NumOfOne( int num )
{
	//ͳ�ƴ���
	int count = 0;
	for (int i =1; i <= num; i *= 10)
	{
		//����ߵ�λ
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