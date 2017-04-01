#include <iostream>
using namespace std;

char arr[1000][1000], toComp[1000][1000], temp[1000][1000];
int N, n;
void rotate()
{
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			temp[j][n-1-i] = toComp[i][j];
		}
	}
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			toComp[i][j] = temp[i][j];
		}
	}
}

bool check(int x, int y)
{
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			if(arr[x + i][y + j] != toComp[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int match()
{
	int r = 0;
	for(int i = 0; i + n <= N; i ++)
	{
		for(int j = 0; j + n <= N; j ++)
		{
			if(check(i,j))
			{
				r ++;
			}
		}
	}
	return r;
}

int main() {
	// your code goes here
	while(cin >> N >> n)
	{
		if(N == 0 && n == 0)
		{
			break;
		}
		for(int i = 0; i < N; i ++)
		{
			cin >> arr[i];
		}
		for(int i = 0; i < n; i ++)
		{
			cin >> toComp[i];
		}
		for(int i = 0; i < 4; i ++)
		{
			if(i > 0)
			{
				rotate();
			}
			cout << match();
			if(i < 3)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}