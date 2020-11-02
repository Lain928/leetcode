#include <iostream>
using namespace std;

void Printmatrix(int data[][4])
{
	int left = 0;
	int right = 3;
	int top = 0;
	int bottom = 3;
	//注意转角处出的处理
	while (left <= right && top <= bottom)
	{
		for (int i = left; i <= right; i++)
		{
			cout << data[top][i] << " ";
		}
		for (int i = top + 1; i <= bottom; i++)
		{
			cout << data[i][right] << " ";
		}
		for (int i = right - 1; i >= left; i--)
		{
			cout << data[bottom][i] << " ";
		}
		for (int i = bottom - 1; i >= top + 1; i--)
		{
			cout << data[i][left] << " ";
		}
		left++;
		right--;
		top++;
		bottom--;
	}
}

int main()
{
	int data[4][4] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	Printmatrix(data);

	system("pause");
	return 0;
}