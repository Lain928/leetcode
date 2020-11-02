#include <iostream>
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
	bool HasSubTree(TreeNode* tree1, TreeNode* tree2);
private:
	bool IsTree1hasTree2(TreeNode* tree1, TreeNode* tree2);
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

bool Solution::HasSubTree( TreeNode* tree1, TreeNode* tree2 )
{
	bool res = false;
	if (tree1 && tree2)
	{
		if (tree1->data == tree2->data)
			res = IsTree1hasTree2(tree1,tree2);
		//�ж�������
		if (!res)
			res = HasSubTree(tree1->pLeft,tree2);
		//�ж�������
		if (!res)
			res = HasSubTree(tree1->pRight,tree2);
	}
	return res;
}

bool Solution::IsTree1hasTree2( TreeNode* tree1, TreeNode* tree2 )
{
	if (tree2 == NULL)
		return true;
	if (tree1 == NULL)
		return false;
	if (tree1->data != tree2->data)
		return false;

	return IsTree1hasTree2(tree1->pLeft, tree2->pLeft) && IsTree1hasTree2(tree1->pRight, tree2->pRight);
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


int main()
{
	Solution slu;
	TreeNode* tree1;
	TreeNode* tree2;
	
	cout << "����������" << endl;
	slu.CreatTree(tree1);
	//slu.PrintTree(tree1);
	
	cout << "��������" << endl;
	slu.CreatTree(tree2);

	if (slu.HasSubTree(tree1, tree2))
		cout << "������" << endl;
	else
		cout << "��������" << endl;

	system("pause");
	return 0;
}