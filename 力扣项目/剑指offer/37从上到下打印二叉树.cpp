#include <iostream>
#include <queue>
using namespace std;

struct TreeNode 
{
	char data;
	TreeNode* pLeft;
	TreeNode* pRight;
};

class Solution 
{
public:  
	//����������
	void CreatTree(TreeNode*& root);
	void PrintTree(TreeNode* root);
	//���ϵ��´�ӡ������
	void PrintTreeFromTopToEnd(TreeNode* root);
private:
};

void Solution::CreatTree( TreeNode*& root )
{
	char c;
	cin >> c;

	if (c == '#')
		root = NULL;
	else
	{
		root = new TreeNode;
		root->data = c;
		CreatTree(root->pLeft);
		CreatTree(root->pRight);
	}

}

void Solution::PrintTree( TreeNode* root )
{
	if (root == NULL)
		return;
	//ǰ��
	cout << root->data << endl;
	PrintTree(root->pLeft);
	PrintTree(root->pRight);
}

void Solution::PrintTreeFromTopToEnd( TreeNode* root )
{
	if (root == NULL)
		return;

	//�洢ָ������
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty())
	{
		cout << que.front()->data << " ";
		if (que.front()->pLeft != NULL)
			que.push(que.front()->pLeft);
		if (que.front()->pRight != NULL)
			que.push(que.front()->pRight);
		que.pop();
	}
	cout << endl;

}

int main()
{
	Solution slu;
	TreeNode* tree1;

	slu.CreatTree(tree1);
	slu.PrintTreeFromTopToEnd(tree1);

	system("pause");
	return 0;
}