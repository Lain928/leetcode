#include <iostream>
#include <vector>
using namespace std;
//解法1
//注意解题 题目中表示的为数字超过一半的？所以数组排好序之后 中间数字必定为此数值
//所以该题转换为了排序问题（比较排序算法的时间复杂度和空间复杂度）


//解法2
//数字个数大于一半 则肯定有两个相同的该数字相邻
//遍历时 只要确定哪个次数不为0
class Slution
{
public:
	int FindNum(vector<int> data);

protected:
private:
};

int Slution::FindNum( vector<int> data )
{
	if (data.empty())
		return 0;
	//找出重复次数最高的数字
	//遍历每个元素，记录次数；若与前一个相同加一 不同减一
	int result = data[0];
	int times = 1;

	for (int i = 1; i < data.size(); i++)
	{
		if (times == 0)
		{
			result = data[i];
			times = 1;
		}
		else if (data[i] == result)
		{
			times++;
		}
		else
			times--;
	}
	//判断result是否符合要求，出现次数大于一半
	times = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == result)
		{
			times++;
		}
	}
	return (times > (data.size() >> 1) ? result : 0);
}

int main()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(4);
	data.push_back(6);
	data.push_back(3);
	data.push_back(1);
	data.push_back(1);
	data.push_back(1);



	Slution slu;
	cout << slu.FindNum(data) << endl;

	system("pause");
	return 0;
}