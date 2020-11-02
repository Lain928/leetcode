#include <iostream>
#include <vector>
using namespace std;

//̰���㷨
class Solution 
{
public:  
	int FindGreatestSumOfSubArray1(vector<int> array)
	{       
		int ans = array[0];
		int sum = array[0];  
		for(int i = 1; i < array.size(); ++ i)
		{           
			sum += array[i];   
			ans = max(sum, ans); 
			if(sum < 0)             
				sum = 0;    
		}      
		return ans; 
	}

	int FindGreatestSumOfSubArray2(vector<int> array)
	{
		if (array.empty())
			return 0;
		//��ʼ��������maxsumΪ���� cursumΪ��ǰ��
		int maxSum = array[0];
		int curSum = array[0];

		//��������Ԫ��
		for (int i = 0; i < array.size(); i++)
		{
			//�����ǰ��С�ڵ���0��˵��֮ǰ�ĺ��Ǹ�����������ǰ��ĺͣ����¼���
			if (curSum <= 0)
				curSum = array[i];
			else
				curSum += array[i];

			//��������
			if (curSum > maxSum)
				maxSum = curSum;
		}
		return maxSum;
	}

};

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(-2);
	vec.push_back(3);
	vec.push_back(10);
	vec.push_back(-4);
	vec.push_back(7);
	vec.push_back(2);
	vec.push_back(-5);

	Solution slu;
	cout << slu.FindGreatestSumOfSubArray2(vec) << endl;
	system("pause");
	return 0;
}