#include <iostream>
#include <vector>
using namespace std;

/*
���������ǰ�ֻ��������2��3��5������������

һһ��������ʱ��Ч�ʵ���

��ʹ�ñ��������k����������1��ʼ����������ǳ�����count++��ֱ��count=kΪֹ����ô����жϳ����أ�

  ���ݳ����Ķ��壬����ֻ��2��3��5���������ӣ���ô���Ǿ������ֳ������������ӡ������㷨���£�

  Step1.���һ�����ܹ���2��������ô������������2��

  Step2.���һ�����ܹ���3��������ô������������3��

  Step3.���һ�����ܹ���5��������ô������������5��

  Step4.�������������Ϊ1����ô��������ǳ����������ǡ�

  2.2 �ռ任ʱ�䷨��ʱ��Ч�ʽϸ�

  �����ݳ����Ķ��壬���ǿ���֪����������������һ����������2��3����5�õ���
	
	������ǿ��Դ���һ�����飬������������ź���ĳ�����ÿһ����������ǰ��ĳ�������2��3����5�õ��ġ�

	���ǰѵõ��ĵ�һ����������2�Ժ�õ��Ĵ���M�Ľ����ΪM2��ͬ�������ǰ����е�ÿһ����������3��5���ܵõ���һ������M�Ľ��M3��M5��
	
	��ôM�������һ������Ӧ����M2,M3��M5���е���Сֵ��Min(M2,M3,M5)��
	
	���罫���������е����ְ���С�������2��ֱ���õ���һ������M����Ϊֹ����ôӦ����2*2=4<M��3*2=6>M������M2=6��ͬ��M3=6��M5=10��������һ������Ӧ����6��
*/


//���k������
class Slution
{
public:
	int NormalAlgorithm(int index);

	int GetUglyNumber(int index);
protected:
private:
	bool IsUhly(int number);
	int MinNum(int n1, int n2,int n3);
};

int Slution::NormalAlgorithm( int index )
{
	if (index <= 0)
		return 0;
	int num = 0;
	int NumCount = 0;
	while (index > NumCount)
	{
		num++;
		if (IsUhly(num))
			NumCount++;
	}
	return num;
}

bool Slution::IsUhly( int number )
{
	while (number % 2 == 0)
		number /= 2;

	while (number % 3 == 0)
		number /= 3;

	while (number % 5 == 0)
		number /= 5;

	return (number == 1) ? true : false;
}

int Slution::GetUglyNumber( int index )
{
	if (index <= 0)
		return 0;
	vector<int> res(index);
	for (int i = 0; i < 6; i++)
	{
		res[i] = i + 1;
	}
	int t2 = 3;
	int t3 = 2;
	int t5 = 1;

	for (int i = 0; i < index;i++)
	{
		res[i] = min(res[t2] * 2,min(res[t3] * 3,res[t5] * 5));

		while (res[i] >= res[t2] * 2)
		{
			t2++;
		}
		while (res[i] >= res[t3] * 3)
		{
			t3++;
		}
		while (res[i] >= res[t5] * 5)
		{
			t5++;
		}
	}
	return res[index - 1];
}

int main()
{

	Slution slu;
	cout << slu.NormalAlgorithm(7) << endl; 

	system("pause");
	return 0;
}