#include <iostream>
#include <vector>
using namespace std;

/*
һ����������������Ѱ��������֮��ΪS �ж������������˻��˻���С��
����������
���������飬�Ͷ�ΪSʱ����˻���С��Ϊ�������������������
*/

class Slution
{
public:
	vector<int> findNums(vector<int> data, int num);
protected:
private:
	vector<int> MinData;
};

vector<int> Slution::findNums( vector<int> data, int num )
{
	if (data.size() < 2)
		return MinData;

	int length = data.size();
	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		int CurSum = data[left] + data[right];
		if (CurSum == num)
		{
			MinData.push_back(data[left]);
			MinData.push_back(data[right]);
			break;
		}
		else if (CurSum < num)
			left++;
		else
			right--;
	}
	return MinData;
}

int main()
{
	system("pause");
	return 0;
}