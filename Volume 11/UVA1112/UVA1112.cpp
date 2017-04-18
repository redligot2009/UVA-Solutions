// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int,ii>

using namespace std;

vector<ii> edges[101];
int dist[101];
int N;
void addEdge(int a, int b, int weight);
void dijkstra(int s, int startTime);


void addEdge(int a, int b, int weight)
{
	edges[b].push_back(ii(a,weight));
}

void dijkstra(int s, int startTime)
{
	//memset(&dist, INT_MAX, sizeof(dist));
	priority_queue<ii> pq;
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INT_MAX;
	}
	pq.push(ii(s, 0));
	dist[s] = 0;
	while (!pq.empty())
	{
		int from = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		//cout << front.first << ": " << front.second << endl;
		if (dist[from] == cost && dist[from] <= startTime)
		{
			for (int i = 0; i < edges[from].size(); i ++)
			{
				int to = edges[from][i].first;
				int w = edges[from][i].second;
				if (dist[from] + w < dist[to])
				{
					dist[to] = dist[from] + w;
					pq.push(ii(to, dist[to]));
					//cout << v.first << " " << dist[v.first] << endl;
				}
			}
		}
	}
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] <= startTime)
		{
			//cout << i << ": " << dist[i] << endl;
			count++;
		}
	}
	printf("%d\n", count);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//std::ios_base::sync_with_stdio(false);
	//cin >> T;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int E;
		int M;
		int timer;
		scanf("%d %d %d", &N, &E, &timer);
		scanf("%d", &M);
		while (M--)
		{
			int a, b, weight;
			scanf("%d%d%d", &a, &b, &weight);
			addEdge(a, b, weight);
			//cout << a << " " << b << " " << weight << endl;
		}
		dijkstra(E, timer);
		for (int i = 1; i <= N; i++)
		{
			edges[i].clear();
		}
		if (T)
		{
			printf("\n");
		}
		//printf("\n");
	}
	//fclose(stdin);
	//fclose(stdout);
    return 0;
}

