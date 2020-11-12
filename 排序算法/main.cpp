#include <iostream>
#include <vector>
#include "mysort.h"

using namespace std;


int main()
{
	vector<int> res = {1,2,3,4,5,6,7,8,9};
	mysort ss;
	ss.quicksort(res,0,8);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	system("pause");
	return 0;
}