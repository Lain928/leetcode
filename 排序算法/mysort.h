#pragma once
#include <iostream>
#include <vector>
using namespace std;

class mysort
{
public:
	//øÏ≈≈À„∑®
	void quicksort(vector<int>& nums, int left, int right);
protected:
private:
};

void mysort::quicksort(vector<int>& nums, int left, int right)
{
	if (left > right)
		return;
	int base = nums[left];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j && nums[j] > base)
			j--;
		nums[i] = nums[j];

		while (i < j && nums[i] < base)
			i++;
		nums[j] = nums[i];
	}
	nums[i] = base;
	quicksort(nums, left, i - 1);
	quicksort(nums, i + 1, right);
}

