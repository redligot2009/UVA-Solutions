#include <bits/stdc++.h>

using namespace std;

struct edge
{
	int to;
	int length;
	int c;

	edge(int to, int length, int c)
	{
		this->to = to;
		this->length = length;
		this->c = c;
	}

	bool operator<(const edge &other) const
	{
		return length > other.length;
	}
};

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	map<string, int> string_to_key;
	vector<edge> edge_string[4003+1];
	long long dist[4003 + 1][27];
	int M;
	string from, to;
	while (cin >> M , M)
	{
		string_to_key.clear();
		int curr = 0;
		cin >> from >> to;
		for (int i = 0; i < M; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			if (string_to_key.find(s1) == string_to_key.end())
			{
				string_to_key[s1] = curr;
				edge_string[curr].clear();
				curr++;
			}
			if (string_to_key.find(s2) == string_to_key.end())
			{
				string_to_key[s2] = curr;
				edge_string[curr].clear();
				curr++;
			}
			string p;
			cin >> p;
			int s1key = string_to_key[s1];
			int s2key = string_to_key[s2];
			//cout << s1key << ": " << s1 << ", " << s2key << ": " << s2 << ", " << p << endl;
			edge_string[s1key].push_back(edge(s2key,p.length(),p[0]-'a'));
			edge_string[s2key].push_back(edge(s1key, p.length(), p[0] - 'a'));
		}
		if (string_to_key.find(from) == string_to_key.end() || string_to_key.find(to) == string_to_key.end())
		{
			cout << "impossivel" << endl;
			continue;
		}
		int from_key = string_to_key[from];
		int to_key = string_to_key[to];
		memset(dist, -1, sizeof(dist));
		//cout << from_key << ": " << from << "," << " to " << to_key << ": " << to << endl;
		priority_queue<edge> Q;
		Q.push(edge(from_key,0,26));
		dist[from_key][26] = 0;
		while (!Q.empty())
		{
			int u = Q.top().to;
			char c = Q.top().c;
			int l = Q.top().length;
			Q.pop();
			if (l != dist[u][c])
			{
				continue;
			}
			//cout << v << " " << s << endl;
			for (auto it = edge_string[u].begin(); it != edge_string[u].end(); it++)
			{
				int v = it->to;
				int c2 = it->c;
				int l2 = it->length;
				if (u == v)
				{
					continue;
				}
				if ((dist[v][c2] > l + l2 || 
					dist[v][c2] == -1) &&
					c2 != c)
				{
					dist[v][c2] = l + l2;
					Q.push(edge(v,dist[v][c2], c2));
				}
			}
		}
		long long best = -1;
		for (int i = 0; i < 27; i++)
		{
			if (dist[to_key][i] != -1)
			{
				if (best == -1 || dist[to_key][i] < best)
				{
					best = dist[to_key][i];
				}
			}
		}
		if (best == -1)
		{
			cout << "impossivel" << endl;
		}
		else
		{
			cout << best << endl;
		}
	}
    return 0;
}
