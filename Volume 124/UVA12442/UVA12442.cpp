// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>

using namespace std;

int edges[50001] = { 0 };
bool marked[50001] = { false };
int sums[500001] = { 0 };

int countNodes(int start = 1)
{
	marked[start] = true;
	int total = 0;
	if (edges[start] != -1 && !marked[edges[start]])
	{
		total += 1 + countNodes(edges[start]);
	}
	marked[start] = false; 
	return sums[start] = total;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(false);
	int T, N;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			edges[i] = -1;
			marked[i] = false;
			sums[i] = -1;
		}
		for (int i = 1; i <= N; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			edges[u] = v;
		}
		int maxCount = -1;
		int maxIndex = -1;
		for (int i = 1; i <= N; i++)
		{
			if (sums[i] == -1)
			{
				countNodes(i);
			}
			if (maxCount < sums[i])
			{
				maxIndex = i;
				maxCount = sums[i];
			}
		}
		printf("Case %d: %d\n", test, maxIndex);
	}
	//fclose(stdin);
	//fclose(stdout);
    return 0;
}

