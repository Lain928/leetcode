#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution 
{
public:  
	bool IsBst(vector<int> result);
private:
	bool Bst(vector<int> result, int begin, int end);
};

bool Solution::IsBst( vector<int> result )
{
	return Bst(result, 0, result.size() - 1);
}

bool Solution::Bst( vector<int> result, int begin, int end )
{
	if (result.empty() || begin > end)
		return false;
	int root = result[end];

	int i = begin;
	//�����ֳ����ڵ����������
	for (; i < end; i++)
	{
		if (result[i] > root)
			break;
	}

	//�ֳ���������ʱ�����ж��������Ƿ񶼴��ڸ��ڵ�
	for (int j = i; j < end; j++)
	{
		if (result[j] < root)
			return false;
	}

	//�ж��������Ƿ�Ϊ����������
	bool left = true;
	if (i > begin)
		left = Bst(result, begin, i - 1);
	//�ж��������Ƿ�Ϊ����������
	bool right = true;
	if (i < end - 1)
		right = Bst(result, i, end - 1);

	return left && right;
}

int main()
{
	Solution slu;

	vector<int> res;
	res.push_back(3);
	res.push_back(5);
	res.push_back(4);
	res.push_back(7);
	res.push_back(9);
	res.push_back(8);
	res.push_back(6);

	if (slu.IsBst(res))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	system("pause");
	return 0;
}