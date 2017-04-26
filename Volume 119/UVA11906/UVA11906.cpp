// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int,ii>

using namespace std;

vector<ii> edges[100][100];
int R, C;
int T;
int M, N;
int W;

int dirX[4] = { 1, -1, 1, -1 };
int dirY[4] = { 1, 1, -1, -1 };
bool marked[100][100] = { false };
bool water[100][100] = { false };

int odd = 0, even = 0;

void dfs(int x, int y)
{
	marked[x][y] = true;
	//printf("%d %d\n", x, y);
	for (int i = 0; i < 4; i++)
	{
		int posX = x + (dirX[i] * M);
		int posY = y + (dirY[i] * N);
		if (posX >= 0 && posX < R && posY >= 0 && posY < C)
		{
			if (!water[posX][posY] && find(edges[x][y].begin(), edges[x][y].end(), ii(posX, posY)) == edges[x][y].end())
			{
				edges[x][y].push_back(ii(posX, posY));
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int posX = x + (dirX[i] * N);
		int posY = y + (dirY[i] * M);
		if (posX >= 0 && posX < R && posY >= 0 && posY < C)
		{
			if (!water[posX][posY] && find(edges[x][y].begin(),edges[x][y].end(),ii(posX,posY)) == edges[x][y].end())
			{
				edges[x][y].push_back(ii(posX, posY));
			}
		}
	}
	if (edges[x][y].size() % 2 == 0)
	{
		even++;
	}
	else
	{
		odd++;
	}
	for (int i = 0; i < edges[x][y].size(); i++)
	{
		int posX = edges[x][y][i].first;
		int posY = edges[x][y][i].second;
		//printf("%d %d : marked = %d\n", posX, posY, marked[posX][posY]);
		if (!marked[posX][posY])
		{
			dfs(posX, posY);
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//std::ios_base::sync_with_stdio(false);
	scanf("%d", &T);
	for (int test = 1; test <= T; test ++)
	{
		even = 0, odd = 0;
		scanf("%d %d %d %d", &R, &C, &M, &N);
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				marked[i][j] = false;
				water[i][j] = false;
				edges[i][j].clear();
			}
		}
		scanf("%d", &W);
		while (W--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			water[x][y] = true;
		}
		dfs(0, 0);
		printf("Case %d: %d %d\n", test, even, odd);
	}
	//fclose(stdin);
	//fclose(stdout);
    return 0;
}