#include <iostream>
using namespace std;

class Slution
{
public:
	//ʹ�õݹ�ķ�ʽ ʱ�临�Ӷȣ�O(2^n) ���ռ临�Ӷȣ�O(n)
	int Method1(int num);
	//�Ե����� ������� ʱ�临�Ӷȣ�O(n) ���ռ临�Ӷȣ�O(1)
	int Method2(int num);
	//����һ�����飬ÿ�ν�ǰ��������Ӻ�ֱ�Ӹ�����һ����
	//���Կռ临�Ӷ�ΪO(N)��ʱ�临�Ӷ�ΪO(N)��
	int Method3(int num);
protected:
private:
};

int Slution::Method1(int num)
{
	if (num == 0)
		return 0;
	if (num == 1 || num == 2)
		return 1;
	else
		return Method1(num - 1) + Method1(num - 2);
}

int Slution::Method2( int num )
{
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;
	int first = 0;
	int second = 1;
	int third = 0;
	for (int i = 2; i <= num; i++)
	{
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}

int Slution::Method3( int num )
{
	//�ǵݹ�
	int* array = new int[num+1];
	array[0] = 0;
	array[1] = 1;
	for (int i = 2; i <= num; i++)
	{
		array[i] = array[i-1] + array[i-2];
	}
	return array[num];
}

int main()
{


	system("pause");
	return 0;
}