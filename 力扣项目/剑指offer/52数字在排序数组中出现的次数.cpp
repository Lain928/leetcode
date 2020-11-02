// #include <iostream>
// using namespace std;
// 
// int main()
// {
// 
// 	system("pause");
// 	return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
	// ����Ԫ��k�����������г��ֵĴ���
	int GetNumberOfK(vector<int> data ,int k)
	{
		// ��������
		if(data.size() == 0)
			return 0;

		// �����������в���k��һ�γ��ֵ�λ��
		int first = GetFirstK(data,k,0,data.size()-1);

		// �����������в���k���һ�γ��ֵ�λ��
		int last = GetLastK(data,k,0,data.size()-1);

		// �������
		if(first != -1 && last != -1)
			return last - first + 1;

		// δ�ҵ�Ԫ��
		return 0;
	}

	// ���ֲ��ҷ������ҵ�һ��k��λ��
	int GetFirstK(vector<int> data,int k,int l,int r)
	{
		// �ݹ����
		if(l > r)
			return -1;

		int mid = (l + r) >> 1;

		if(k < data[mid])
		{
			r = mid - 1;
		}
		else if (k > data[mid])
		{
			l = mid + 1;
		}
		else
		{
			//��ǰ�ж�data[mid] == k ������ж���һ�������Ƿ�Ϊk
			if((mid>0 && data[mid-1] != k) || mid == 0)
				return mid;
			else
				r = mid - 1;
		}
		return GetFirstK(data,k,l,r);
	}

	// ���ֲ��ҷ����������һ��k��λ��
	int GetLastK(vector<int> data,int k,int l,int r)
	{
		if(l>r)
			return -1;

		int mid = (l+r)>>1;

		if(k<data[mid])
			r = mid-1;
		else if(k>data[mid])
			l = mid+1;
		else
		{
			if((mid < data.size() - 1 && data[mid+1]!=k) || mid == data.size()-1)
				return mid;
			else
				l = mid + 1; //��
		}
		return GetLastK(data,k,l,r);
	}
};
int  main()
{

	vector<int> arr2;
	arr2.push_back(1);
	arr2.push_back(2);
	arr2.push_back(2);
	arr2.push_back(2);
	arr2.push_back(2);
	arr2.push_back(2);
	arr2.push_back(3);
	arr2.push_back(4);
	arr2.push_back(5);

	Solution solution;
	cout << solution.GetNumberOfK(arr2, 2) << endl;

	system("pause");
	return 0;
}