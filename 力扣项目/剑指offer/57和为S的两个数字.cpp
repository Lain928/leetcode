#include <iostream>
#include <vector>
using namespace std;

/*
一个递增的数组中找寻两个数字之和为S 有多个则输出两个乘积乘积最小的
特征分析：
递增的数组，和都为S时，则乘积最小的为两者相差最大的两个数字
*/

class Slution
{
public:
	vector<int> findNums(vector<int> data, int num);
protected:
private:
	vector<int> MinData;
};

vector<int> Slution::findNums( vector<int> data, int num )
{
	if (data.size() < 2)
		return MinData;

	int length = data.size();
	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		int CurSum = data[left] + data[right];
		if (CurSum == num)
		{
			MinData.push_back(data[left]);
			MinData.push_back(data[right]);
			break;
		}
		else if (CurSum < num)
			left++;
		else
			right--;
	}
	return MinData;
}

int main()
{
	system("pause");
	return 0;
}