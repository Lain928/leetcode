#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void Permutation(vector<string>& ans,int k,string str) 
{
	int size = str.size();
	if(k == size - 1)
	{
		ans.push_back(str);
		return;
	}
	for(int i = k; i < size; ++i)
	{
		if(i != k && str[i] == str[k])
			continue;
		swap(str[i], str[k]);

		Permutation(ans,k+1,str);
	}
}
vector<string> Permutation(string str)
{
	vector<string> ans;

	Permutation(ans,0,str);
	return ans;
}

int main()
{
	string str = "bac";
	vector<string> result = Permutation(str);
	sort(result.begin(), result.end());

	cout<<"counts:"<<result.size()<<endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	system("pause");
	return 0;
}