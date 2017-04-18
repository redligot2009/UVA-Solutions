// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define iii pair<int,pi>

using namespace std;

int grid[1000][1000] = { 0 };
int dist[1000][1000] = { 0 };
int T, M, N;
int dirX[4] = {-1, 0, 1, 0 };
int dirY[4] = {0, 1, 0, -1};
priority_queue<pair<int, pi>, vector<pair<int, pi> >, greater<pair<int, pi> > > pq;

bool isValid(int x, int y)
{
	return (x >= 0 && x < N) && (y >= 0 && y < M);
}

int main()
{
//	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//std::ios_base::sync_with_stdio(false);
	//cin >> T;
	scanf("%d", &T);
	while (T--)
	{
		//cin >> N >> M;
		scanf("%d", &N);
		scanf("%d", &M);
		memset(&grid, 0, sizeof(grid));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &grid[i][j]);
				dist[i][j] = 1e9;
			}
		}
		pq.push(pair<int, pi>(grid[0][0], pi(0, 0)));
		dist[0][0] = grid[0][0];
		while (!pq.empty())
		{
			iii front = pq.top(); 
	        pq.pop();
	        int d = front.first; 
	        pi u = front.second;
			if (d == dist[u.first][u.second])
			{
				for (int i = 0; i < 4; i++)
				{
					int newX = u.first + dirX[i];
					int newY = u.second + dirY[i];
					if (isValid(newX, newY))
					{
						int v = grid[newX][newY];
						if (dist[newX][newY] > dist[u.first][u.second] + v)
						{
							dist[newX][newY] = dist[u.first][u.second] + v;
							pi newV = pi(newX,newY);
							pq.push(pair<int, pi>(dist[newX][newY], newV));
						}
					}
				}
			}
		}
		printf("%d\n", dist[N - 1][M - 1]);
	}
	//fclose(stdin);
	//fclose(stdout);
    return 0;
}

