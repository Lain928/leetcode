#include <iostream>
#include <vector>
using namespace std;
//�ⷨ1
//ע����� ��Ŀ�б�ʾ��Ϊ���ֳ���һ��ģ����������ź���֮�� �м����ֱض�Ϊ����ֵ
//���Ը���ת��Ϊ���������⣨�Ƚ������㷨��ʱ�临�ӶȺͿռ临�Ӷȣ�


//�ⷨ2
//���ָ�������һ�� ��϶���������ͬ�ĸ���������
//����ʱ ֻҪȷ���ĸ�������Ϊ0
class Slution
{
public:
	int FindNum(vector<int> data);

protected:
private:
};

int Slution::FindNum( vector<int> data )
{
	if (data.empty())
		return 0;
	//�ҳ��ظ�������ߵ�����
	//����ÿ��Ԫ�أ���¼����������ǰһ����ͬ��һ ��ͬ��һ
	int result = data[0];
	int times = 1;

	for (int i = 1; i < data.size(); i++)
	{
		if (times == 0)
		{
			result = data[i];
			times = 1;
		}
		else if (data[i] == result)
		{
			times++;
		}
		else
			times--;
	}
	//�ж�result�Ƿ����Ҫ�󣬳��ִ�������һ��
	times = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == result)
		{
			times++;
		}
	}
	return (times > (data.size() >> 1) ? result : 0);
}

int main()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(4);
	data.push_back(6);
	data.push_back(3);
	data.push_back(1);
	data.push_back(1);
	data.push_back(1);



	Slution slu;
	cout << slu.FindNum(data) << endl;

	system("pause");
	return 0;
}