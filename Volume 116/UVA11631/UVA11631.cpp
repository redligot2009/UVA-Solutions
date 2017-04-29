// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int,ii>

using namespace std;

int m, n, edgesum;

vector<ii> edges[200001];

void prim()
{
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	int src = 0;
	vector<int> key(m, INT_MAX);
	vector<bool> inMST(m, false);
	pq.push(ii(0, src));
	key[src] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		inMST[u] = true;
		for (int i = 0; i < edges[u].size(); i++)
		{
			int v = edges[u][i].first;
			int weight = edges[u][i].second;
			if (!inMST[v] && key[v] > weight)
			{
				key[v] = weight;
				pq.push(ii(key[v], v));
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < key.size(); i++)
	{
		sum += key[i];
	}
	printf("%d\n", edgesum - sum);
	for (int i = 0; i < m; i++)
	{
		edges[i].clear();
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	while (scanf("%d %d", &m, &n) && m && n)
	{
		edgesum = 0;
		for (int i = 0; i < n; i++)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			edges[x].push_back(ii(y, z));
			edges[y].push_back(ii(x, z));
			edgesum += z;
		}
		prim();
	}
	//fclose(stdin);
	//fclose(stdout);
    return 0;
}