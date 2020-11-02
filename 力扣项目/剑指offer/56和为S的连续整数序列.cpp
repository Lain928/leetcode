#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Slution
{
public:
	vector<vector<int> > findList(int num);
protected:
private:
	vector<vector<int> > data;
	vector<int> temp;
};

vector<vector<int>> Slution::findList( int num )
{
	if (num < 1)
		return data;
	int left = 1;
	int right = 2;
	int mid = (num + 1) >> 1;
	int CurSum = 3;
	temp.push_back(1);
	temp.push_back(2);

	while (left < mid)
	{
		if (CurSum == num)
			data.push_back(temp);

		while (CurSum > num && left < mid)
		{
			CurSum -= left;
			temp.erase(temp.begin());
			left++;
			if (CurSum == num)
				data.push_back(temp);
		}

		right++;
		CurSum += right;
		temp.push_back(right);
	}
	return data;
}


int main()
{
	system("pause");
	return 0;
}