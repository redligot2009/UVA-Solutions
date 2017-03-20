#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
    int _graph[2000][2000];
    Graph();
    void addEdge(int a, int s);
    void clear();
};

Graph::Graph()
{
    memset(&_graph, 0, sizeof(_graph));
}

void Graph::addEdge(int a, int s)
{
    _graph[a][s] = 1;
}

void Graph::clear()
{
    memset(&_graph,0,sizeof(_graph));
}

int main() {
	// your code goes here
	Graph myGraph, myGraph2;
    int dirX[4] = {1, 0, -1, 0};
    int dirY[4] = {0, 1, 0, -1};
	int p;
	while(cin >> p)
	{
	    myGraph.clear();
	    myGraph2.clear();
	    if(p == 0)
	    {
	        break;
	    }
	    int a, s;
	    queue<pair<int,int> > q;
	    int dist[2000][2000] = {0};
	    for(int i = 0; i < p; i ++)
	    {
	        cin >> a >> s;
	        myGraph.addEdge(a, s);
	        q.push(pair<int,int>(a,s));
	    }
	    cin >> p;
	    for(int i = 0; i < p; i ++)
	    {
	        cin >> a >> s;
	        myGraph2.addEdge(a, s);
	    }
	    int minDist = 100000;
	    bool found = false;
	    while(!q.empty())
	    {
	        pair<int,int> u = q.front();
	        int distance = dist[u.first][u.second];
	        q.pop();
	        for(int i = 0; i < 4; i ++)
	        {
	            int nx = u.first + dirX[i];
	            int ny = u.second + dirY[i];
	            if(nx >= 2000 || nx < 0 || ny < 0 || ny >= 2000 || myGraph._graph[nx][ny] == 1)
	            {
	                continue;
	            }
	            if(myGraph2._graph[nx][ny] == 1)
	            {
	                found = true;
	                break;
	            }
	            myGraph._graph[nx][ny] = 1;
	            dist[nx][ny] = distance + 1;
	            q.push(pair<int,int>(nx, ny));
	        }
	        if(found)
	        {
	            cout << distance + 1 << endl;
	            break;
	        }
	    }
	}
	return 0;
}
