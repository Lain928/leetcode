#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class leetcode
{
public:
	vector<int> leetcode_twoSum1(vector<int>& nums, int target);
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
