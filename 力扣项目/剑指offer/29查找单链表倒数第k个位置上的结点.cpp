#include <iostream>
using namespace std;
struct ListNode 
{
	int data;
	ListNode* next;
};
//֪ʶ���ܽ�
//��������ָ���������һ��ָ������һ��ָ�����ߣ�
//����ָ��������������������뻷�ڵ�ָ���ַ�����ݣ�
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
		//���ж��������ж�����ĳ����Ƿ����k
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