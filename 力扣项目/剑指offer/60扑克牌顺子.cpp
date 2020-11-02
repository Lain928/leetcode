#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/*
扑克牌顺子 大小王为0， a为1 j为11 q为12 k为13
*/
class Slution
{
public:
	bool IsContinuous(vector<int> numbers);
protected:
private:
};
/*
1.判断数字出现次数
2.范围
*/
bool Slution::IsContinuous( vector<int> numbers )
{
	if (numbers.size() != 5)
		return false;
	int max = -1;
	int min = 14;
	int flag =0;
	for (int i = 0; i < numbers.size(); i++)
	{
		int CurNum = numbers[i];
		if (CurNum < 0 || CurNum > 13)
			return false;

		if (CurNum == 0)
			continue;
		//如果数字出现不止一次
		if ((flag >> CurNum) & 1 == 1)
			return false;

		//按位保存数字出现数字，比如0110表示 0出现0次 1出现1次 2出现1次 3出现0次
		//或运算符
		flag |= 1 << CurNum;//右移curnum位

		//更新最小值
		if (CurNum < min)
			min = CurNum;
		//更新最大值
		if (CurNum > max)
			max = CurNum;
		//超过一定范围则不是顺子
		if (max - min >= 5)
			return false;
	}
	return true;

}

int main()
{

	system("pause");
	return 0;
}