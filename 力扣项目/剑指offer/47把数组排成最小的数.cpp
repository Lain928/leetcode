#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//关键点在于自定义比较函数 进行如何形式下的比较

//1、全排列
// 
// 	求出数组中所有数字的全排列，然后把每个全排列拼起来，求出拼出来的数字的最大值。
// 
//2、定义新的排序规则
// 
// 	如果两个数字m,n拼接成mn和nm，如果mn<nm，那么m应该排在n的前面，我们定义此时m小于n，如果mn=nm，我们定义m等于n。
// 
// 	可以考虑将数字转成字符串，一来防止数字拼接时的溢出，二来字符串的拼接和比较容易实现。
// 
// 	由于把数字m和n拼接起来得到mn和nm，它们的位数一定是相同的，因此比较它们的大小只需按照字符串大小的比较规则即可

class Slition
{
public:
	string PrintMinNumber(vector<int> numbers)
	{
		string res;
		if(numbers.empty()) 
			return res;

		//自定义排序方式 升序排列还是降序排列
		sort(numbers.begin(),numbers.end(),compare);
		for(int i=0;i<numbers.size();++i)
		{
			res+=to_string(long long(numbers[i]));
		}
		return res;
	}
	// 判断a < b则按照升序进行排列 反之降序排序
	//输入进入的a b代表什么意思？？？ 为什么数组状态下也适用
	static bool compare(int a,int b)
	{
		string str1=to_string(long long(a));
		string str2=to_string(long long(b));
		return (str1+str2)<(str2+str1);
	}
};

int main()
{
	vector<int> data;
	data.push_back(3);
	data.push_back(32);
	data.push_back(321);

	Slition slu;
	cout << slu.PrintMinNumber(data) << endl;

	system("pause");
	return 0;
}