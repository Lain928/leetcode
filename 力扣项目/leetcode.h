#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class leetcode
{
public:
	//两数之和
	vector<int> leetcode_twoSum1(vector<int>& nums, int target);
	//整数反转
	int leet_reverse7(int x);
protected:
private:
};

std::vector<int> leetcode::leetcode_twoSum1(vector<int>& nums, int target)
{
	unordered_map<int, int> maptable;
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = maptable.find(target - nums[i]);
		if (it != maptable.end())
		{
			return {it->second, i};
		}
		maptable[nums[i]] = i;
	}
	return {};
}

int leetcode::leet_reverse7(int x)
{
	long num = 0;
	while (x != 0)
	{
		int pop = x % 10;
		num = num * 10 + pop;
		x /= 10;
	}
	return num > INT_MAX || num < INT_MIN ? 0 : num;
}
