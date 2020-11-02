#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution 
{
public:    
	int MinInArray(const vector<int> num);
	int midorder(vector<int> num, int left, int right);
};
  
int Solution::MinInArray( const vector<int> num )
{
	int size = num.size();
	if (size == 0)
	{
		return 0;
	}
	int left = 0;
	int right = size - 1;
	int mid = 0;
	//���ö��ֲ��ҷ�
	while (1)
	{
		if (right - left == 1)
		{
			mid = right;
			return num[mid];
		}
		mid = left + (right - left) / 2;
		if (num[mid] == num[left] && num[mid] == num[right])
		{
			//��������������ֵ�����ʱ��ֻ�ܴ�ͷ��β�Ľ��д�С�ж�
			return midorder(num, left, right);
		}
		
		if (num[mid] >= num[left])
			left = mid;
		else
			right = mid;
	}
}

int Solution::midorder( vector<int> num, int left, int right )
{
	int solut = num[left];
	for (int i = left + 1; i <= right; i++)
	{
		if (num[i] < solut)
			return num[i];
	}
	return solut;
}


int main()
{
	Solution slu;
	vector<int> a;
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(1);
	a.push_back(2);

	cout << slu.MinInArray(a) << endl;

	system("pause");
	return 0;
}