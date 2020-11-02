#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution 
{
public:    
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)    //size���������Ĵ�СΪ����
	{       
		vector<int> result;       
		if(size < 1 || num.size() < size)
		{           
			return result;  
		}
		//dequeΪ˫�˶���
		deque<int> qmax;
		for(int i = 0; i < num.size(); ++i)
		{         
			//�����ʲôʱ����whileʲôʱ����if
			while(!qmax.empty() && num[qmax.back()] <= num[i])
			{               
				qmax.pop_back();         
			}            
			qmax.push_back(i);  
			//������ͷ�洢�ĵ�Ԫ��λ�ò��ڻ���������ʱ���䵯��
			if(qmax.front() == i-size)  
			{               
				qmax.pop_front();     
			} 
			//�ӵ�size�������д洢�����ӻ�������Сλ��ʱ���д洢
			if(i >= size - 1)
			{              
				result.push_back(num[qmax.front()]);
			}       
		}        
		return result;      
	}
};


int main()
{

	Solution slu;
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(2);
	a.push_back(6);
	a.push_back(2);
	a.push_back(5);
	a.push_back(1);

	vector<int> b = slu.maxInWindows(a,3);

	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << endl;
	}
	system("pause");
	return 0;
}