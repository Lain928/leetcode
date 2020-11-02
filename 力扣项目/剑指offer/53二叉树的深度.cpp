#include <iostream>
using namespace std;

struct TreeNode 
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

class Slution
{
public:
	int TreeDeep(TreeNode* root);
protected:
private:
	int count;
};

int Slution::TreeDeep( TreeNode* root )
{
	if (root == NULL)
		return 0;
	else
	{
		int leftDepth = TreeDeep(root->left);
		int rightDepth = TreeDeep(root->right);
		return (leftDepth > rightDepth) ? (leftDepth + 1):(rightDepth + 1);
	}

}


int main()
{

	system("pause");
	return 0;
}