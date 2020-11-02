#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/*
�˿���˳�� ��С��Ϊ0�� aΪ1 jΪ11 qΪ12 kΪ13
*/
class Slution
{
public:
	bool IsContinuous(vector<int> numbers);
protected:
private:
};
/*
1.�ж����ֳ��ִ���
2.��Χ
*/
bool Slution::IsContinuous( vector<int> numbers )
{
	if (numbers.size() != 5)
		return false;
	int max = -1;
	int min = 14;
	int flag =0;
	for (int i = 0; i < numbers.size(); i++)
	{
		int CurNum = numbers[i];
		if (CurNum < 0 || CurNum > 13)
			return false;

		if (CurNum == 0)
			continue;
		//������ֳ��ֲ�ֹһ��
		if ((flag >> CurNum) & 1 == 1)
			return false;

		//��λ�������ֳ������֣�����0110��ʾ 0����0�� 1����1�� 2����1�� 3����0��
		//�������
		flag |= 1 << CurNum;//����curnumλ

		//������Сֵ
		if (CurNum < min)
			min = CurNum;
		//�������ֵ
		if (CurNum > max)
			max = CurNum;
		//����һ����Χ����˳��
		if (max - min >= 5)
			return false;
	}
	return true;

}

int main()
{

	system("pause");
	return 0;
}