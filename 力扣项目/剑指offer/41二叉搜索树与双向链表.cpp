#include <iostream>
#include <queue>
using namespace std;

struct TreeNode 
{
	int m_nValue;
	TreeNode* left;
	TreeNode* right;
};
class Solution
{
public:
	TreeNode* CreatTree();

	TreeNode* Convert(TreeNode* root)
	{
		if(root == nullptr) 
			return nullptr;

		// 双向链表尾节点
		TreeNode* list_last = nullptr;

		// 递归建立双向链表
		ConvertNode(root, list_last);

		// 查找双向链表首节点
		while(list_last->left != nullptr)
		{
			list_last = list_last->left;
		}

		// 返回双向链表的首节点
		return list_last;
	}

	// 对BST中序遍历，得到有序序列；调整序列元素的指针，将有序序列调整为双向链表
	void ConvertNode(TreeNode* cur,TreeNode *&list_last) // 注意形参
	{
		// 边界条件(递归出口)
		if(cur==nullptr) 
			return ;

		// 遍历左子树
		if(cur->left != nullptr) 
			ConvertNode(cur->left,list_last);

		// 建立双向链接
		cur->left = list_last;                           // 单侧链接
		if(list_last != nullptr) 
			list_last->right = cur; // 单侧链接
		list_last = cur;

		//遍历右子树
		if(cur->right != nullptr)
			ConvertNode(cur->right,list_last);
	}
};


TreeNode* Solution::CreatTree()
{
	//                8(node1)
	//        6(node2)      10(node3)
	//  5(node4) 13(node5) 9(node6)  11(node7)	
	TreeNode* node1  = new TreeNode;
	TreeNode* node2  = new TreeNode();
	TreeNode* node3  = new TreeNode();	
	TreeNode* node4  = new TreeNode();	
	TreeNode* node5  = new TreeNode();	
	TreeNode* node6  = new TreeNode();	
	TreeNode* node7  = new TreeNode(); 
	//node1
	node1->m_nValue = 10;	
	node1->left = node2;	
	node1->right = node3; 	
	//node2	
	node2->m_nValue = 6;	
	node2->left = node4;	
	node2->right = node5; 	
	//node3	
	node3->m_nValue = 14;	
	node3->left = node6;
	node3->right = node7;
	//node4
	node4->m_nValue = 4;	
	node4->left = nullptr;
	node4->right = nullptr;	
	//node5	
	node5->m_nValue = 8;
	node5->left = nullptr;	
	node5->right = nullptr;	 
	//node6
	node6->m_nValue = 12;
	node6->left = nullptr;	
	node6->right = nullptr;	 
	//node7	
	node7->m_nValue = 16;	
	node7->left = nullptr;
	node7->right = nullptr;

	return node1;
}



int main()
{
	Solution slu;
	TreeNode* root = slu.CreatTree();
	TreeNode* list_head = slu.Convert(root);

	cout << "从前往后:";
	while (list_head->right != NULL)
	{
		cout << list_head->m_nValue << " ";
		list_head = list_head->right;
	}
	cout << list_head->m_nValue << endl;

	cout << "从后往前:";
	while (list_head != NULL)
	{
		cout << list_head->m_nValue << " " ;
		list_head = list_head->left;
	}




	system("pause");
	return 0;
}