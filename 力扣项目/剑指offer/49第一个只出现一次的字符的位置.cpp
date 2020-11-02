#include <iostream>
#include <map>
using namespace std;


/*
map��STL��һ���������������ṩһ��һ��hash��
��һ�����Գ�Ϊ�ؼ���(key)��ÿ���ؼ���ֻ����map�г���һ�Σ�
�ڶ������Գ�Ϊ�ùؼ��ֵ�ֵ(value)��

����Ԫ�ط�����
// ����һ��map����
map<int, string> mapStudent;

// ��һ�� ��insert��������pair
mapStudent.insert(pair<int, string>(000, "student_zero"));

// �ڶ��� ��insert��������value_type����
mapStudent.insert(map<int, string>::value_type(001, "student_one"));

// ������ ��"array"��ʽ����
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