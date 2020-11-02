#include <iostream>
using namespace std;
struct ListNode 
{
	int data;
	ListNode* next;
};
//知识点总结
//采用两个指针的做法（一个指针先走一个指针再走）
//快慢指针的做法（查找链表中入环口的指针地址和数据）
class Slution
{
public:
	ListNode* FindKNodeFromEnd(ListNode* root, int k);
protected:
private:
};

ListNode* Slution::FindKNodeFromEnd( ListNode* root ,int k)
{
	if (root == NULL)
		return NULL;
	ListNode* pFirst = root;
	ListNode* pSecond = root;

	for (int i = 0; i < k - 1; i++)
	{
		//加判断条件是判断链表的长度是否大于k
		if (pFirst != NULL)
			pFirst = pFirst->next;
		else
			return NULL;
	}

	while (pFirst->next != NULL)
	{
		pFirst = pFirst->next;
		pSecond = pSecond->next;
	}
	return pSecond;
}


int main()
{
	system("pause");
	return 0;
}