// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	int N;
	while (cin >> N && N)
	{
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			q.push(temp);
		}
		int total = 0, cost = 0;
		while (q.size() > 1)
		{
			total = q.top();
			q.pop();
			total += q.top();
			q.pop();
			cost += total;
			q.push(total);
		}
		cout << cost << endl;
	}
	//fclose(stdin);
	//fclose(stdout);
    return 0;
}

