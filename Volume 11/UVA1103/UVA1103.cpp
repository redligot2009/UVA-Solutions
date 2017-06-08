// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>

using namespace std;

int N, M;

int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,1,0,-1 };
int rowl = 0;

string grid[5005];
int visited[5005][5005];
//hex -> binary
string getBin(string hex)
{
	string res = "";
	for (int i = 0; i < hex.length(); i++)
	{
		switch (hex[i])
		{
			case '0': res.append("0000"); break;
			case '1': res.append("0001"); break;
			case '2': res.append("0010"); break;
			case '3': res.append("0011"); break;
			case '4': res.append("0100"); break;
			case '5': res.append("0101"); break;
			case '6': res.append("0110"); break;
			case '7': res.append("0111"); break;
			case '8': res.append("1000"); break;
			case '9': res.append("1001"); break;
			case 'a': res.append("1010"); break;
			case 'b': res.append("1011"); break;
			case 'c': res.append("1100"); break;
			case 'd': res.append("1101"); break;
			case 'e': res.append("1110"); break;
			case 'f': res.append("1111"); break;
		}
	}
	return res;
}

void dfsblack(int x, int y, char c)
{
	//mark as black
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int newx = x + dirx[i];
		int newy = y + diry[i];
		if (newx >= 0 && newx < N && newy >= 0 && newy < rowl)
		{
			if (grid[newx][newy] == '0' && visited[newx][newy] == 0)
			{
				dfsblack(newx, newy, c);
			}
		}
	}
}
void dfswhite(int x, int y, char c)
{
	//mark as white
	visited[x][y] = 2;
	for (int i = 0; i < 4; i++)
	{
		int newx = x + dirx[i];
		int newy = y + diry[i];
		if (newx >= 0 && newx < N && newy >= 0 && newy < rowl)
		{
			if (grid[newx][newy] == '1' && visited[newx][newy] == 0)
			{
				dfswhite(newx, newy, c);
			}
		}
	}
}


int dfs2(int x, int y, int holes = 0)
{
	//mark as unvisitable
	visited[x][y] = 3;
	for (int i = 0; i < 4; i++)
	{
		int newx = x + dirx[i];
		int newy = y + diry[i];
		if (newx >= 0 && newx < N && newy >= 0 && newy < rowl)
		{
			if (visited[newx][newy] == 0)//if hole
			{
				holes++;
				dfsblack(newx, newy, '0');
			}
			else if (visited[newx][newy] == 2)//if white
			{
				holes += dfs2(newx, newy, 0);
			}
		}
	}
	//return the holes
	return holes;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int test = 0;
	while (cin >> N >> M && N != 0 && M != 0)
	{
		cout << "Case " << ++test << ": ";
		string hex_s;
		memset(&visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++)
		{
			cin >> hex_s;
			grid[i] = getBin(hex_s);
		}
		rowl = grid[0].length();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < rowl; j++)
			{
				rowl = grid[i].length();
				if (i == 0 || j == 0 || i == N - 1 || j == rowl-1)
				{
					if (grid[i][j] == '0' && !visited[i][j])
					{
						dfsblack(i, j, '0');
					}
				}
			}
		}
		string ans;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < rowl; j++)
			{
				if (grid[i][j] == '1' && !visited[i][j])
				{
					dfswhite(i, j, '1');
					int holes = dfs2(i, j, 0);
					if (holes == 1)
					{
						ans += 'A';
					}
					else if (holes == 3)
					{
						ans += 'J';
					}
					else if (holes == 5)
					{
						ans += 'D';
					}
					else if (holes == 4)
					{
						ans += 'S';
					}
					else if (holes == 0)
					{
						ans += 'W';
					}
					else if (holes == 2)
					{
						ans += 'K';
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		cout << ans << endl;
	}
	return 0;
}
