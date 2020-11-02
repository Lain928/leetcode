#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/*
自己做的办法是将单词存储到stack中，占用内存比较大

另外一种做法是： 先将每个单词进行反转，最后再将整个str进行反转
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
	cout << "翻转之后的str长度：" << str2.size() << endl;
	return str2;	
}

std::string Slution::ReverseSentence1( string str )
{
	int length = str.size();
	if (length == 0)
		return "";

	string res = str;

	//在字符串后面添加空格作为最后单词的分隔符
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

	//去掉添加的空格
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
	//弹出最后一个空格
	str1.pop();

	while (!str1.empty())
	{
		str2 += str1.top();
		str1.pop();
	}
	cout << "翻转之后的str长度：" << str2.size() << endl;
	return str2;
}

int main()
{
	Slution slu;
	string str = "student. a am i";
	cout << "str长度：" << str.size() << endl;
	cout << slu.ReverseSentence2(str);

	system("pause");
	return 0;
}