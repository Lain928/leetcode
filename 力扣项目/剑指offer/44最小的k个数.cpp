#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Slution
{
public:
	vector<int> FindnMinNum(vector<int> data, int k);
protected:
private:
	vector<int> result;
};

vector<int> Slution::FindnMinNum( vector<int> data ,int k)
{
	if (data.empty() || k > data.size())
		return result;

	sort(data.begin(), data.end());
	for (int i = 0; i < k; i++)
	{
		result.push_back(data[i]);
	}
	return result;

}

int main()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(4);
	data.push_back(6);
	data.push_back(3);
	data.push_back(7);
	data.push_back(2);
	data.push_back(5);

	Slution slu;
	vector<int> a = slu.FindnMinNum(data, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << a[i] << " ";
	}

	system("pause");
	return 0;
}