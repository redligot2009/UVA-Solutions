#include <iostream>
using namespace std;
int A[100000+1];
int N, Q;

int sign(int x)
{
	if(x > 0)
	{
		return 1;
	}
	else if(x < 0)
	{
		return -1;
	}
	return 0;
}

struct tree {
	
	int i, j;
	int v;
	tree* left;
	tree* right;
	
	tree (int i, int j, int v)
	{
		this->i = i;
		this->j = j;
		this->v = v;
		left = right = NULL;
	}
	
	int get_product (int I, int J)
	{
		if(I <= i && j <= J)
		{
			return v;
		}
		else if(J < i|| j < I)
		{
			return 1;
		}
		else
		{
			return (left->get_product(I,J) * right->get_product(I,J));
		}
	}
	
	void update(int I, int V)
	{
		if(I >= i && I <= j)
		{
			if(i!=j)
			{
				left->update(I,V);
				right->update(I,V);
				v = left->v * right->v;
			}
			else
			{
				v = sign(V);
			}
		}
	}
	
};

tree* root;

tree* construct(int i, int j)
{
	if(i == j)
	{
		return new tree(i,j,sign(A[i]));
	}
	else
	{
		int mid = (i + j)/2;
		tree* left = construct(i, mid);
		tree* right = construct(mid+1,j);
		tree* curr = new tree(i,j,left->v * right->v);
		curr->left = left;
		curr->right = right;
		return curr;
	}
}

void init()
{
	root = construct(1, N);
}

int get_product(int I, int J)
{
	return root->get_product(I,J);
}

void update(int I, int V)
{
	root->update(I,V);
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> N >> Q)
	{
		for(int i = 1; i <= N; i ++)
		{
			cin >> A[i];
		}
		init();
		while(Q--)
		{
			char command;
			cin >> command;
			if(command == 'C')
			{
				int I, V;
				cin >> I >> V;
				update(I, V);
			}
			else if(command == 'P')
			{
				int I, J;
				cin >> I >> J;
				int prod = get_product(I,J);
				if(prod > 0)
				{
					cout << "+";
				}
				else if(prod == 0)
				{
					cout << "0";
				}
				else if(prod < 0)
				{
					cout << "-";
				}
			}
		}
		cout << endl;
	}
	return 0;
}