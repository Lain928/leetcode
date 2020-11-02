#include <iostream>
#include <map>
#include <vector>
using namespace std;


/*
首先交待一下异或的基本性质：2个相同的数异或等于0，且异或操作(^)满足结合律和交换律。

再来考虑一种简单一点的情况：一个数组中只有一个元素出现唯一的一次，而有其他元素都出现2次。

那么我们用0依次异或数组中每一个元素，得到的就是那个唯一的元素。因为我们可以利用交换律和结合律将相同的元素移动到一起，

那么在利用结合律，相同的元素两两先异或，得到0，最后得到很多0和唯一的元素异或，所以最终的答案就是那个唯一的元素。

所以，如果我们能把原来问题中的数组，分成2个子数组，使得每个子数组中都只有一个唯一的元素以及很多成对的元素，

那么我们就可以求出每个子数组中唯一的元素，最终就可以得到原数组中2个出现次数唯一的元素。

方法是这样的：

1. 首先数组中所有元素依次异或，因为相同的元素异或得到0，所以最终的答案就等于那2个唯一的元素a^b的值。

2. 因为a,b不同，所以异或得到的答案肯定是不等于0的，那么我们就找到a^b的二进制表示中第一个为1的位，假如是第k位。

而a,b两个数在第k位上是不同的，一个为0，一个为1

3. 接下来我们将第k位是1的分成一组，第k位是0的分成一组，如果2个元素相同，那么他们第k位肯定是一样的，

所以肯定被分到同一组中。而a,b则被分到2组中去了。

然后我们就可以在每个分组中异或每一个元素，最终就可以得到那2个唯一的元素。

*/


class Solution1
{
public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int* num2) 
	{
		int num = data.size();

		//依次跟所有元素异或 相同为0 相异为1
		int ret = 0;
		for(int i=0; i<num; i++)
			ret ^= data[i];

		//找到第一个k位
		int pos = 1;
		while(((ret>>pos) & 1) != 1 )
			pos++;

		//将包含num1 and num2 分开
		for(int i=0; i<num; i++)
		{
			if(((data[i]>>pos) & 1) != 1 )
				*num1 ^= data[i];
			else 
				*num2 ^= data[i];
		}
	}
};

class Slution
{
public:
	//找出数组中第一个只出现一次的数字
	int FindnNumsApperOnce(int data[], int size);
protected:
private:
};

int Slution::FindnNumsApperOnce( int data[] ,int size)
{
	if (data == NULL || size == 0)
	{
		return -1;
	}
	map<int, int> item;
	for (int i = 0; i < size; i++)
	{
		item[data[i]]++;
	}

	for (int i = 0; i < size; i++)
	{
		if (item[data[i]] == 1)
		{
			return data[i];
		}
	}
	return -1;

}

void func(int* num)
{
	*num = 20;
}

int main()
{
	Solution1 slu;

// 	int data[] = {2,4,6,2,5,3,6,5};
// 	int size = sizeof(data) / sizeof(data[0]);
// 
// 	cout << slu.FindnNumsApperOnce(data,size) << endl;

	int num1 = 0;
	int num2 = 0;
	vector<int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(2);
	data.push_back(4);
	data.push_back(1);
	data.push_back(6);

	slu.FindNumsAppearOnce(data, &num1, &num2);
	cout << num1 << "	"  << num2 << endl;
	
	
	//指针做函数形参使用方法
// 	int val = 10;
// 	func(&val);
// 	cout << val << endl;


	system("pause");
	return 0;
}