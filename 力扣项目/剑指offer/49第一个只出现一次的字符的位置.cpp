#include <iostream>
#include <map>
using namespace std;


/*
map是STL的一个关联容器，它提供一对一的hash。
第一个可以称为关键字(key)，每个关键字只能在map中出现一次；
第二个可以称为该关键字的值(value)；

插入元素方法：
// 定义一个map对象
map<int, string> mapStudent;

// 第一种 用insert函數插入pair
mapStudent.insert(pair<int, string>(000, "student_zero"));

// 第二种 用insert函数插入value_type数据
mapStudent.insert(map<int, string>::value_type(001, "student_one"));

// 第三种 用"array"方式插入
mapStudent[123] = "student_first";
mapStudent[456] = "student_second";
*/

class Slution
{
public:
	int GetOnlyChar(string str);
protected:
private:
};

int Slution::GetOnlyChar( string str )
{
	int len = str.size();
	if (len == 0)
		return -1;

	map<char, int> item;

	for (int i = 0; i < len; i++)
	{
		item[str[i]]++;
	}

	for (int i = 0; i < len; i++)
	{
		if (item[str[i]] == 1)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	system("pause");
	return 0;
}