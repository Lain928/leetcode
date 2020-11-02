#include <iostream>
#include <map>
#include <vector>
using namespace std;


/*
���Ƚ���һ�����Ļ������ʣ�2����ͬ����������0����������(^)�������ɺͽ����ɡ�

��������һ�ּ�һ��������һ��������ֻ��һ��Ԫ�س���Ψһ��һ�Σ���������Ԫ�ض�����2�Ρ�

��ô������0�������������ÿһ��Ԫ�أ��õ��ľ����Ǹ�Ψһ��Ԫ�ء���Ϊ���ǿ������ý����ɺͽ���ɽ���ͬ��Ԫ���ƶ���һ��

��ô�����ý���ɣ���ͬ��Ԫ����������򣬵õ�0�����õ��ܶ�0��Ψһ��Ԫ������������յĴ𰸾����Ǹ�Ψһ��Ԫ�ء�

���ԣ���������ܰ�ԭ�������е����飬�ֳ�2�������飬ʹ��ÿ���������ж�ֻ��һ��Ψһ��Ԫ���Լ��ܶ�ɶԵ�Ԫ�أ�

��ô���ǾͿ������ÿ����������Ψһ��Ԫ�أ����վͿ��Եõ�ԭ������2�����ִ���Ψһ��Ԫ�ء�

�����������ģ�

1. ��������������Ԫ�����������Ϊ��ͬ��Ԫ�����õ�0���������յĴ𰸾͵�����2��Ψһ��Ԫ��a^b��ֵ��

2. ��Ϊa,b��ͬ���������õ��Ĵ𰸿϶��ǲ�����0�ģ���ô���Ǿ��ҵ�a^b�Ķ����Ʊ�ʾ�е�һ��Ϊ1��λ�������ǵ�kλ��

��a,b�������ڵ�kλ���ǲ�ͬ�ģ�һ��Ϊ0��һ��Ϊ1

3. ���������ǽ���kλ��1�ķֳ�һ�飬��kλ��0�ķֳ�һ�飬���2��Ԫ����ͬ����ô���ǵ�kλ�϶���һ���ģ�

���Կ϶����ֵ�ͬһ���С���a,b�򱻷ֵ�2����ȥ�ˡ�

Ȼ�����ǾͿ�����ÿ�����������ÿһ��Ԫ�أ����վͿ��Եõ���2��Ψһ��Ԫ�ء�

*/


class Solution1
{
public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int* num2) 
	{
		int num = data.size();

		//���θ�����Ԫ����� ��ͬΪ0 ����Ϊ1
		int ret = 0;
		for(int i=0; i<num; i++)
			ret ^= data[i];

		//�ҵ���һ��kλ
		int pos = 1;
		while(((ret>>pos) & 1) != 1 )
			pos++;

		//������num1 and num2 �ֿ�
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
	//�ҳ������е�һ��ֻ����һ�ε�����
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
	
	
	//ָ���������β�ʹ�÷���
// 	int val = 10;
// 	func(&val);
// 	cout << val << endl;


	system("pause");
	return 0;
}