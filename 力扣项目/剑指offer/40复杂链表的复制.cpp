#include <iostream>
using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode* next;
	RandomListNode* random;
};

//链接两个相邻表的方法
class Solution 
{  
public:   
	RandomListNode* Clone(RandomListNode* pHead)  
	{       
		if(pHead == nullptr)
			return nullptr;   

		clonenode(pHead);    
		clonerandom(pHead);     
		return divorcelist(pHead);  
	}
private:
	// 第一步 复制链表，将复制的random指针全部置为NULL 只赋值label 和 next
	// 并将复制的链表 分别插入原链表的next指针中
	void clonenode(RandomListNode *pHead)   //复制在一个链表并将其连起来   
	{
		RandomListNode* pclone;
		while(pHead)    
		{           
			pclone = new RandomListNode;   
			pclone->label = pHead->label;
			pclone->next = pHead->next;
			pclone->random = NULL;

			pHead->next = pclone;          
			pHead = pclone->next;  
		}    
	} 
	//第二步 复制random指针 
	void clonerandom(RandomListNode *pHead)
	{      
		RandomListNode *pclone;    
		while(pHead)      
		{       
			pclone = pHead->next;       
			if(pHead->random)              
				pclone->random = pHead->random->next; 

			pHead = pclone->next;     
		}   
	}   

	//第三步 分解链表 奇数位为原链表 偶数位为复制链表
	RandomListNode* divorcelist(RandomListNode *pHead)    
	{       
		//复制链表头结点，复制链表遍历节点，遍历节点
		RandomListNode* pcHead,*pcnode,*pnode = pHead;   

		//解决两个链表的头结点，后面节点可以统一操作
		if(pnode)         
		{       
			//复制链表的头结点和遍历节点指向复制链表第一个节点 
			pcHead = pcnode = pnode->next;      
			pnode->next = pcnode->next;            
			pnode = pnode->next;         
		}       

		while(pnode)          
		{          
			//交叉连接
			pcnode->next = pnode->next; 
			pcnode = pcnode->next;          
			pnode->next = pcnode->next;       
			pnode = pnode->next;        
		}
		return pcHead; 
	} 
};


int main()
{
	system("pause");
	return 0;
}