#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//�ؼ��������Զ���ȽϺ��� ���������ʽ�µıȽ�

//1��ȫ����
// 
// 	����������������ֵ�ȫ���У�Ȼ���ÿ��ȫ����ƴ���������ƴ���������ֵ����ֵ��
// 
//2�������µ��������
// 
// 	�����������m,nƴ�ӳ�mn��nm�����mn<nm����ômӦ������n��ǰ�棬���Ƕ����ʱmС��n�����mn=nm�����Ƕ���m����n��
// 
// 	���Կ��ǽ�����ת���ַ�����һ����ֹ����ƴ��ʱ������������ַ�����ƴ�ӺͱȽ�����ʵ�֡�
// 
// 	���ڰ�����m��nƴ�������õ�mn��nm�����ǵ�λ��һ������ͬ�ģ���˱Ƚ����ǵĴ�Сֻ�谴���ַ�����С�ıȽϹ��򼴿�

class Slition
{
public:
	string PrintMinNumber(vector<int> numbers)
	{
		string res;
		if(numbers.empty()) 
			return res;

		//�Զ�������ʽ �������л��ǽ�������
		sort(numbers.begin(),numbers.end(),compare);
		for(int i=0;i<numbers.size();++i)
		{
			res+=to_string(long long(numbers[i]));
		}
		return res;
	}
	// �ж�a < b��������������� ��֮��������
	//��������a b����ʲô��˼������ Ϊʲô����״̬��Ҳ����
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