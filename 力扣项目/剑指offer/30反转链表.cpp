#include <iostream>
using namespace std;
struct ListNode 
{
	int data;
	ListNode* next;
};

class Slution
{
public:
	ListNode* ReverseList(ListNode* head);
protected:
private:
};

ListNode* Slution::ReverseList( ListNode* head )
{
	if (head == NULL)
		return NULL;
	ListNode* pReverseHead = NULL;
	ListNode* pPre = NULL;
	ListNode* pCur = head;

	while(pCur != NULL)
	{
		ListNode* next = pCur->next;
		if (next == NULL)
		{
			pReverseHead = pCur;
		}
		pCur->next = pPre;
		pPre = pCur;
		pCur = next;
	}
	return pReverseHead;
}


int main()
{
	system("pause");
	return 0;
}