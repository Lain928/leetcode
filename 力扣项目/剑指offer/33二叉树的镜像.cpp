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
	//创建二叉树
	void CreatTree(TreeNode*& root);
	void PrintTree(TreeNode* root);
	//递归的方式
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
	//前序
	cout << root->data << endl;
	PrintTree(root->pLeft);
	PrintTree(root->pRight);
}

void Solution::Mirror( TreeNode *pRoot )
{
	// 空节点
	if(pRoot == NULL)
		return;

	// 叶子结点
	if(pRoot->pLeft == NULL && pRoot->pRight == NULL)
		return;

	// 二叉树有多个节点时，交换当前节点的左右节点
	TreeNode* temp = pRoot->pLeft;
	pRoot->pLeft = pRoot->pRight;
	pRoot->pRight = temp;

	// 二叉树的遍历
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