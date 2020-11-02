#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution 
{
public:    
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)    //size代表滑动窗的大小为多少
	{       
		vector<int> result;       
		if(size < 1 || num.size() < size)
		{           
			return result;  
		}
		//deque为双端队列
		deque<int> qmax;
		for(int i = 0; i < num.size(); ++i)
		{         
			//分清楚什么时间用while什么时间用if
			while(!qmax.empty() && num[qmax.back()] <= num[i])
			{               
				qmax.pop_back();         
			}            
			qmax.push_back(i);  
			//当队列头存储的单元格位置不在滑动窗口内时将其弹出
			if(qmax.front() == i-size)  
			{               
				qmax.pop_front();     
			} 
			//从第size个数进行存储，即从滑动窗大小位置时进行存储
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