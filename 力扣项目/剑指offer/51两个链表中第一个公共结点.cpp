#include <iostream>
#include <stack>
using namespace std;

//����1 �����ⷨ ˫��ѭ������
//����2 ����������ֱ�ѹ��ջ�� ��ջ�ж�ȡ��ַ����

struct Node
{
	int data;
	Node* next;
};

class Slution
{
public:
	Node* FindFirstPublicNode1(Node* node1, Node* node2);

	//�Ƚ����ȱȽϳ�����n - m�� �ڽ��б����Ƚ�
	Node* FindFirstPublicNode2(Node* node1, Node* node2);
protected:
private:
	stack<Node*> stack1;
	stack<Node*> stack2;
};

//ʱ�临�Ӷȣ�m + n�� �ռ临�Ӷȣ�m + n��
Node* Slution::FindFirstPublicNode1( Node* node1, Node* node2 )
{
	while (node1 != NULL)
	{
		stack1.push(node1);
		node1 = node1->next;
	}
	while (node2 != NULL)
	{
		stack2.push(node2);
		node2 = node2->next;
	}
	Node* temp = NULL;

	while (!stack1.empty() && !stack2.empty())
	{
		if (stack1.top() != stack2.top())
		{
			return stack1.top();
		}
		else
		{
			stack1.pop();
			stack2.pop();
		}
	}
	return NULL;
}

Node* Slution::FindFirstPublicNode2( Node* node1, Node* node2 )
{
	int count1 = 0;
	int count2 = 0; 
	Node* Temp1 = node1;
	Node* Temp2 = node2;
	while (Temp1 != NULL)
	{
		count1++;
		Temp1 = Temp1->next;
	}
	while (Temp2 != NULL)
	{
		count2++;
		Temp2 = Temp2->next;
	}

	int diff = count1 - count2;
	if (diff >= 0)
	{
		for (int i = 0; i < diff; i++)
			node1 = node1->next;
	}
	else
	{
		for (int i = 0; i < abs(diff); i++)
			node2 = node2->next;
	}

	while (node1 != NULL && node2 != NULL)
	{
		if (node1 == node2)
		{
			return node1;
		}
		else
		{
			node1 = node1->next;
			node2 = node2->next;
		}
	}

	return NULL;
}

int main()
{

	system("pause");
	return 0;
}