#include <iostream>
using namespace std;

struct ListNode 
{
	int val;
	ListNode* next;
};

class Solution 
{
public:    
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)  
	{       
		if(pHead1 == nullptr)   
			return pHead2;    
		if(pHead2 == nullptr)          
			return pHead1;   

		ListNode *pAns = nullptr; 

		if(pHead1->val < pHead2->val)
		{           
			pAns = pHead1;  
			pAns->next = Merge(pHead1->next, pHead2);     
		}      
		else
		{  
			pAns = pHead2;        
			pAns->next = Merge(pHead1, pHead2->next);  
		}        
		return pAns;   
	}
};


int main()
{
	system("pause");
	return 0;
}