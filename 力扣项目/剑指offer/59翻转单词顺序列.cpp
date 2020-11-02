#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/*
�Լ����İ취�ǽ����ʴ洢��stack�У�ռ���ڴ�Ƚϴ�

����һ�������ǣ� �Ƚ�ÿ�����ʽ��з�ת������ٽ�����str���з�ת
*/
class Slution
{
public:
	string ReverseSentence(string str);
	string ReverseSentence1(string str);
	string ReverseSentence2(string str);
protected:
private:
	void Reverce(string &str, int begin, int end);
	stack<string> str1;
	string str2;
};

std::string Slution::ReverseSentence( string str )
{
	if (str.size() == 0)
		return str2;

	int j = 0;
	int k = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			str1.push(str.substr(j, k));
			str1.push(" ");
			j = i + 1;
			k = 0;
		}
		else if (i == str.size() - 1)
		{
			str1.push(str.substr(j, k + 1));
		}
		else
			k++;
	}

	while (!str1.empty())
	{
		str2 += str1.top();
		str1.pop();
	}
	cout << "��ת֮���str���ȣ�" << str2.size() << endl;
	return str2;	
}

std::string Slution::ReverseSentence1( string str )
{
	int length = str.size();
	if (length == 0)
		return "";

	string res = str;

	//���ַ���������ӿո���Ϊ��󵥴ʵķָ���
	res += " ";
	int mark = 0;
	for (int i = 0; i < length + 1; i++)
	{
		if (res[i] == ' ')
		{
			Reverce(res, mark, i - 1);
			mark = i + 1;
		}
	}

	//ȥ����ӵĿո�
	res = res.substr(0, length);
	Reverce(res, 0, length - 1);
	return res;
}

void Slution::Reverce( string &str, int begin, int end )
{
	while (begin < end)
		swap(str[begin++], str[end--]);
}

std::string Slution::ReverseSentence2( string str )
{
	int len = str.size();
	if (len == 0)
		return "";
	string res = str;
	int j = 0;
	int k = 0;

	res += " ";
	for (int i = 0; i < len + 1; i++)
	{
		if (res[i] == ' ')
		{
			str1.push(str.substr(j, k));
			str1.push(" ");
			j = i + 1;
			k = 0;
		}
		else
			k++;
	}
	//�������һ���ո�
	str1.pop();

	while (!str1.empty())
	{
		str2 += str1.top();
		str1.pop();
	}
	cout << "��ת֮���str���ȣ�" << str2.size() << endl;
	return str2;
}

int main()
{
	Slution slu;
	string str = "student. a am i";
	cout << "str���ȣ�" << str.size() << endl;
	cout << slu.ReverseSentence2(str);

	system("pause");
	return 0;
}