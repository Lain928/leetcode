#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
string s="";

string a="abcdefg";

1.将字符串a的元素赋值逐一赋值给另一字符串s

s+=a[i];

2.将字符串a完全赋值给新字符串s

s.assign(a);

3.将字符串a的一部分赋值给新的字符串s

start是截取字符串的首位置，len是截取字符串的长度

s.substr(start,len);

s.assign(a,start,len);

4.对字符串s赋相同的n个初值

s.assing(n,'x')，如给s赋10个字符a写法如下：

s.assign(10,'a');
*/

class Slution
{
public:
	string LeftRotateString(string str, int num);
protected:
private:
	string TempStr;
};

std::string Slution::LeftRotateString( string str, int num )
{	
// 	if (num <= 0)
// 		return str;
// 
// 	for (int i = 0; i < num; i++)
// 		TempStr += str[i];
// 	int a = 0;
// 	for (int i = num; i < str.size(); i++)
// 		str[a++] = str[i];
// 
// 	int j = 0;
// 	for (int i = str.size() - num; i < str.size(); i++)
// 		str[i] = TempStr[j++];
// 
// 	return str;


	string str1;
	str1 = str.substr(0,num);
	str.erase(0,num); //删除包括0之后的num个字符
	return str+str1;
}

int main()
{
// 	string str = "abcdefghig";
// 	Slution slu;
// 	cout << slu.LeftRotateString(str,2) << endl;


	string s1("Real Steel");
	s1.erase(0, 3);  //删除子串(1, 3)，此后 s1 = "R Steel"
	cout << s1 << endl;
	system("pause");
	return 0;
}