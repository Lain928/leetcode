#include <iostream>
using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode* next;
	RandomListNode* random;
};

//�����������ڱ�ķ���
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
	// ��һ�� �������������Ƶ�randomָ��ȫ����ΪNULL ֻ��ֵlabel �� next
	// �������Ƶ����� �ֱ����ԭ�����nextָ����
	void clonenode(RandomListNode *pHead)   //������һ����������������   
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
	//�ڶ��� ����randomָ�� 
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

	//������ �ֽ����� ����λΪԭ���� ż��λΪ��������
	RandomListNode* divorcelist(RandomListNode *pHead)    
	{       
		//��������ͷ��㣬������������ڵ㣬�����ڵ�
		RandomListNode* pcHead,*pcnode,*pnode = pHead;   

		//������������ͷ��㣬����ڵ����ͳһ����
		if(pnode)         
		{       
			//���������ͷ���ͱ����ڵ�ָ���������һ���ڵ� 
			pcHead = pcnode = pnode->next;      
			pnode->next = pcnode->next;            
			pnode = pnode->next;         
		}       

		while(pnode)          
		{          
			//��������
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