#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class leetcode
{
public:
	//1 两数之和
	vector<int> leetcode_twoSum1(vector<int>& nums, int target);
	//7 整数反转
	int leet_reverse7(int x);
	//9 整数是否为回文数
	bool leet_isPalindrome9(int x);
	//13 罗马数字转换
	int leet_romanToInt13(string s);
	//14 最长公共前缀
	string leet_longestCommonPrefix14(vector<string>& strs);
protected:
private:
	//13 罗马数字转换
	int change13(char var);
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

bool leetcode::leet_isPalindrome9(int x)
{
	//当x小于0，或者末尾为0时肯定不为0，x=0除外
	if (x < 0 || (x % 10 == 0 && x != 0))
		return false;
	int num = 0;
	//只进行反转一半
	while (num < x)
	{
		num = num * 10 + x % 10;
		x /= 10;
	}
	//判断是偶数还是奇数，奇数：12321 — 12 123 
	return x == num || x == (num / 10);
}

int leetcode::leet_romanToInt13(string s)
{
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int num = change13(s[i]);
		if (s[i + 1] != '\0')
			num = num > change13(s[i+1]) ? num : -num;
		sum += num;
	}
	return sum;
}

std::string leetcode::leet_longestCommonPrefix14(vector<string>& strs)
{
	string result = "";
	char var;
	if (strs.size() == 0)
		return result;
	for (int i = 0; i < strs[0].size(); i++)
	{
		var = strs[0][i];
		for (int j = 1; j < strs.size(); j++)
		{
			if (i < strs[j].size() && var == strs[j][i])
				continue;
			else
				return result;
		}
		result += strs[0][i];
	}
	return result;
}

int leetcode::change13(char var)
{
	switch (var)
	{
	case 'I': return 1; break;
	case 'V': return 5; break;
	case 'X': return 10; break;
	case 'L': return 50; break;
	case 'C': return 100; break;
	case 'D': return 500; break;
	case 'M': return 1000; break;
	}
	return 0;
}
