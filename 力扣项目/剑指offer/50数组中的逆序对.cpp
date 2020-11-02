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
	//排序的辅助数组
	vector<int> copy;
	for (int i = 0; i < data.size(); i++)
	{
		copy.push_back(data[i]);
	}
	return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
}

long Slution::InversePairsCore( vector<int> &data, vector<int> &copy, int begin, int end )
{
	//如果指向相同的位置，则没有逆序对
	if (begin == end)
		return 0;

	//求中点
	int mid = (end - begin) >> 1;
	//使data左半段有序，并返回左半段逆序对的数目
	long left = InversePairsCore(data, copy, begin, mid);
	//使data右半段有序，并返回右半段逆序对的数目
	long right = InversePairsCore(data, copy, mid + 1, end);
	//前半段最后一个下标
	int i = mid;
	//后一段最后一个数字的下标
	int j = end;
	//辅助数组的最后一个数字下标
	int indexcopy = end;
	//计数 逆序对的个数 注意类型
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