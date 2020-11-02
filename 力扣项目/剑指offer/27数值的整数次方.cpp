#include <iostream>
using namespace std;

class Solution 
{
public: 
	//采用递归的方式进行操作
	double Power(double base, int exponent)
	{        
		if(exponent == 0) 
			return 1;      
		if(exponent == 1)      
			return base; 

		double temp;
		if(exponent > 1)      
		{             
			temp = base * Power(base,exponent - 1);   
		}       
		if(exponent < 0)      
		{
			temp = (1 / base) * Power(base,exponent + 1); 
		}       
		return temp;   
	}
	//方法2 实行奇偶数分开计算
	double Power2(double base, int exponent)
	{
		if(exponent == 0) 
			return 1;      
		if(exponent == 1)      
			return base; 
		double temp = 0;
		int exp = 0;
		exp = abs(exponent);
		temp = Power2(base, exp >> 1);
		temp = temp * temp;

		//判断是否为奇数
		if ((exp & 1) == 1)
			temp = temp * base;
		if (exponent < 0)
			return 1 / temp;
		return temp;
	}
};

int main()
{
	Solution slu;
	cout << slu.Power(2.0, 3) << endl;
	//cout << slu.Power2(2.0, 100) << endl;


	system("pause");

	return 0;
}