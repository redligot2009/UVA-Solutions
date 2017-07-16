#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int N, M;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin >> N >> M)
	{
		long long grid[N+1][M+1];
		long long dp[N+1][M+1];
		int parent[N+1][M+1];
		for(int i = 0; i < N; i ++)
		{
			for(int j = 0; j < M; j ++)
			{
				cin >> grid[i][j];
				parent[i][j] = -1;
			}
		}
		for(int i = 0; i < N; i ++)
		{
			dp[i][M-1] = grid[i][M-1];
		}
		for(int j = M-2; j >= 0; j --)
		{
			for(int i = 0; i < N; i ++)
			{
				int up = i > 0 ? i - 1 : N - 1;
				int down = (i + 1) % N;
				int mid = i;
				int a = min(up,min(mid,down));
				int c = max(up,max(mid,down));
				int b = up + mid + down - a - c; 
				long long aboveVal = dp[c][j+1];
				long long belowVal = dp[a][j+1];
				long long sameVal = dp[b][j+1];
				if(belowVal <= aboveVal
				&& belowVal <= sameVal)
				{
					parent[i][j] = a;
					dp[i][j] = grid[i][j] + belowVal;
				}
				else if(sameVal <= aboveVal
				&& sameVal <= belowVal)
				{
					parent[i][j] = b;
					dp[i][j] = grid[i][j] + sameVal;
				}
				else
				{
					parent[i][j] = c;
					dp[i][j] = grid[i][j] + aboveVal;
				}
			}
		}
		long long minval = LONG_MAX;
		int minrow;
		for(int i = 0; i < N; i ++)
		{
			if(dp[i][0] < minval)
			{
				minval = dp[i][0];
				minrow = i;
			}
		}
		int curr = minrow;
		int currj = 0;
		while(parent[curr][currj] != -1)
		{
			cout << curr + 1 << " ";
			curr = parent[curr][currj];
			currj++;
		}
		cout << curr + 1 << endl;
		cout << minval << endl;
	}
	return 0;
}