#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Slution
{
public:
	void SortOddtoEven(vector<int> & array);
protected:
private:
};

void Slution::SortOddtoEven( vector<int> & array )
{
	if (array.empty())
		return;

	deque<int> que;
	int num = array.size();
	for (int i = 0; i < num; i++)
	{
		//��ͷ��ʼ�ж�Ϊż��ʱ�������е�β�����β���                        
		if (array[i] % 2 == 0)
			que.push_back(array[i]);
		//��β��ʼ�ж�Ϊ����ʱ������ͷ����ʼ����
		if (array[num - 1 - i] % 2 == 1)
			que.push_front(array[num - 1 - i]);
	}

	array.assign(que.begin(),que.end());
}


int main()
{
	Slution slu;
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(4);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(9);
	arr.push_back(10);
	arr.push_back(11);

	slu.SortOddtoEven(arr);
 	int n = arr.size();

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}