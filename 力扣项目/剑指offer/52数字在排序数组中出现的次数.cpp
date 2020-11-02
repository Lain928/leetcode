// #include <iostream>
// using namespace std;
// 
// int main()
// {
// 
// 	system("pause");
// 	return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
	// 查找元素k在有序数组中出现的次数
	int GetNumberOfK(vector<int> data ,int k)
	{
		// 特殊输入
		if(data.size() == 0)
			return 0;

		// 在有序数组中查找k第一次出现的位置
		int first = GetFirstK(data,k,0,data.size()-1);

		// 在有序数组中查找k最后一次出现的位置
		int last = GetLastK(data,k,0,data.size()-1);

		// 计算次数
		if(first != -1 && last != -1)
			return last - first + 1;

		// 未找到元素
		return 0;
	}

	// 二分查找法，查找第一个k的位置
	int GetFirstK(vector<int> data,int k,int l,int r)
	{
		// 递归出口
		if(l > r)
			return -1;

		int mid = (l + r) >> 1;

		if(k < data[mid])
		{
			r = mid - 1;
		}
		else if (k > data[mid])
		{
			l = mid + 1;
		}
		else
		{
			//当前判断data[mid] == k 情况下判断左一个数字是否为k
			if((mid>0 && data[mid-1] != k) || mid == 0)
				return mid;
			else
				r = mid - 1;
		}
		return GetFirstK(data,k,l,r);
	}

	// 二分查找法，查找最后一个k的位置
	int GetLastK(vector<int> data,int k,int l,int r)
	{
		if(l>r)
			return -1;

		int mid = (l+r)>>1;

		if(k<data[mid])
			r = mid-1;
		else if(k>data[mid])
			l = mid+1;
		else
		{
			if((mid < data.size() - 1 && data[mid+1]!=k) || mid == data.size()-1)
				return mid;
			else
				l = mid + 1; //当
		}
		return GetLastK(data,k,l,r);
	}
};
int  main()
{

	vector<int> arr2;
	arr2.push_back(1);
	arr2.push_back(2);
	arr2.push_back(2);
	arr2.push_back(2);
	arr2.push_back(2);
	arr2.push_back(2);
	arr2.push_back(3);
	arr2.push_back(4);
	arr2.push_back(5);

	Solution solution;
	cout << solution.GetNumberOfK(arr2, 2) << endl;

	system("pause");
	return 0;
}