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
	//用来分出根节点的左右子树
	for (; i < end; i++)
	{
		if (result[i] > root)
			break;
	}

	//分出左右子树时用于判断右子树是否都大于根节点
	for (int j = i; j < end; j++)
	{
		if (result[j] < root)
			return false;
	}

	//判断左子树是否为二叉搜索树
	bool left = true;
	if (i > begin)
		left = Bst(result, begin, i - 1);
	//判断右子树是否为二叉搜索树
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