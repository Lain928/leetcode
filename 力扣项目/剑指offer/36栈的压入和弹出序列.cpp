#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MyStack
{
public:
	bool IsPopOrder(vector<int> pushlist, vector<int> poplist);
protected:
private:
	stack<int> HelpStack;
};

bool MyStack::IsPopOrder( vector<int> pushlist, vector<int> poplist )
{
	int j = 0;
	if (pushlist.size() == 0)
	{
		return false;
	}
	for (int i = 0; i < pushlist.size(); i++)

	{
		HelpStack.push(pushlist[i]);
		while (j < poplist.size() && HelpStack.top() == poplist[i])
		{
			HelpStack.pop();
			j++;
		}
	}
	return HelpStack.empty();
}

int main()
{

	system("pause");
	return 0;
}