#include <iostream>
#include <vector>
using namespace std;

//贪心算法
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
		//初始化变量，maxsum为最大和 cursum为当前和
		int maxSum = array[0];
		int curSum = array[0];

		//遍历所有元素
		for (int i = 0; i < array.size(); i++)
		{
			//如果当前和小于等于0，说明之前的和是负数，则抛弃前面的和，重新计算
			if (curSum <= 0)
				curSum = array[i];
			else
				curSum += array[i];

			//更新最大和
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