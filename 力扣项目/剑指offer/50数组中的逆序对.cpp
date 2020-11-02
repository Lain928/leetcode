#include <iostream>
#include <vector>
using namespace std;


class Slution
{
public:
	int InversePairs(vector<int> data);
	long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end);
};

int Slution::InversePairs( vector<int> data )
{
	if (data.size() == 0)
	{
		return 0;
	}
	//����ĸ�������
	vector<int> copy;
	for (int i = 0; i < data.size(); i++)
	{
		copy.push_back(data[i]);
	}
	return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
}

long Slution::InversePairsCore( vector<int> &data, vector<int> &copy, int begin, int end )
{
	//���ָ����ͬ��λ�ã���û�������
	if (begin == end)
		return 0;

	//���е�
	int mid = (end - begin) >> 1;
	//ʹdata�������򣬲�������������Ե���Ŀ
	long left = InversePairsCore(data, copy, begin, mid);
	//ʹdata�Ұ�����򣬲������Ұ������Ե���Ŀ
	long right = InversePairsCore(data, copy, mid + 1, end);
	//ǰ������һ���±�
	int i = mid;
	//��һ�����һ�����ֵ��±�
	int j = end;
	//������������һ�������±�
	int indexcopy = end;
	//���� ����Եĸ��� ע������
	long count = 0;
	while (i > begin && j >= mid + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexcopy--] = data[i--];
			count += j - mid;
		}
		else
		{
			copy[indexcopy--] = data[j--];
		}
	}
	for (; i >= begin; i--)
	{
		copy[indexcopy--] = data[i];
	}
	for (; j >= mid + 1; j--)
	{
		copy[indexcopy--] = data[i];
	}
	return left + right + count;
}

int main()
{
	system("pause");
	return 0;
}