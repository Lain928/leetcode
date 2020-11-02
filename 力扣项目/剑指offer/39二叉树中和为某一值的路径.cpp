#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode 
{
	char m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution 
{
public:  
	vector<vector<int> > FindPath(BinaryTreeNode* root, int num);
	void test01();

private:
	vector<vector<int> > result;
	vector<int> temp;

};

vector<vector<int> > Solution::FindPath( BinaryTreeNode* root, int num )
{
	if (root == NULL)
		return result;

	temp.push_back(root->m_nValue);
	if (num - root->m_nValue == 0 && root->m_pLeft == NULL && root->m_pRight == NULL)
		result.push_back(temp);

	//遍历左子树
	FindPath(root->m_pLeft,num - root->m_nValue);

	//遍历右子树
	FindPath(root->m_pRight,num - root->m_nValue);


	temp.pop_back();
	return result;
}

void Solution::test01()
{
	//                8(node1)
	//        6(node2)      10(node3)
	//  5(node4) 13(node5) 9(node6)  11(node7)	
	BinaryTreeNode* node1  = new BinaryTreeNode;
	BinaryTreeNode* node2  = new BinaryTreeNode();
	BinaryTreeNode* node3  = new BinaryTreeNode();	
	BinaryTreeNode* node4  = new BinaryTreeNode();	
	BinaryTreeNode* node5  = new BinaryTreeNode();	
	BinaryTreeNode* node6  = new BinaryTreeNode();	
	BinaryTreeNode* node7  = new BinaryTreeNode(); 
	//node1
	node1->m_nValue = 8;	
	node1->m_pLeft = node2;	
	node1->m_pRight = node3; 	
	//node2	
	node2->m_nValue = 6;	
	node2->m_pLeft = node4;	
	node2->m_pRight = node5; 	
	//node3	
	node3->m_nValue = 10;	
	node3->m_pLeft = node6;
	node3->m_pRight = node7;
	//node4
	node4->m_nValue = 5;	
	node4->m_pLeft = nullptr;
	node4->m_pRight = nullptr;	
	//node5	
	node5->m_nValue = 13;
	node5->m_pLeft = nullptr;	
	node5->m_pRight = nullptr;	 
	//node6
	node6->m_nValue = 9;
	node6->m_pLeft = nullptr;	
	node6->m_pRight = nullptr;	 
	//node7	
	node7->m_nValue = 11;	
	node7->m_pLeft = nullptr;
	node7->m_pRight = nullptr;	
	//测试部分
	vector<vector<int> > result = FindPath(node1, 27);  

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	delete node1;delete node2;	
	delete node3;delete node4;
	delete node5;delete node6;	
	delete node7;

}


int main()
{
	Solution slu;
	slu.test01();

	system("pause");
	return 0;
}