#include <iostream>
#include <stack>
using namespace std;

class StackMin
{
public:
	void push(int data);
	void pop();
	int top();
	int Min();
protected:
private:
	stack<int> sta1;
	stack<int> sta2;
};

//清楚栈的性质 栈先进后出
void StackMin::push(int data)
{
	sta1.push(data);
	if (sta2.empty())
	{
		sta2.push(data);
	}
	if (sta2.top() > data)
	{
		sta2.push(data);
	}
}

void StackMin::pop()
{
	if (sta2.top() == sta1.top())
	{
		sta2.pop();
	}
	sta1.pop();
}

int StackMin::top()
{
	return sta1.top();
}

int StackMin::Min()
{
	return sta2.top();
}

int main()
{

	system("pause");
	return 0;
}