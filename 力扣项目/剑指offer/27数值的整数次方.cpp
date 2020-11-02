#include <iostream>
using namespace std;

class Solution 
{
public: 
	//���õݹ�ķ�ʽ���в���
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
	//����2 ʵ����ż���ֿ�����
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

		//�ж��Ƿ�Ϊ����
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