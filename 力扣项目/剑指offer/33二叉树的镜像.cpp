#include <iostream>
using namespace std;
/*
			8
	  6			 10
	5   7      9    11


			8
	  10		   6
	11   9      7    5
*/

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
	//�ݹ�ķ�ʽ
	void Mirror(TreeNode *pRoot);
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

void Solution::Mirror( TreeNode *pRoot )
{
	// �սڵ�
	if(pRoot == NULL)
		return;

	// Ҷ�ӽ��
	if(pRoot->pLeft == NULL && pRoot->pRight == NULL)
		return;

	// �������ж���ڵ�ʱ��������ǰ�ڵ�����ҽڵ�
	TreeNode* temp = pRoot->pLeft;
	pRoot->pLeft = pRoot->pRight;
	pRoot->pRight = temp;

	// �������ı���
	Mirror(pRoot->pLeft);
	Mirror(pRoot->pRight);
}

int main()
{
	Solution slu;
	TreeNode* tree1;

	slu.CreatTree(tree1);


	system("pause");
	return 0;
}