// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int N;
	int order[1000];
	while (cin >> N && N)
	{
		while (true)
		{
			bool breakLoop = false;
			for (int i = 0; i < N; i++)
			{
				cin >> order[i];
				if (order[i] == 0)
				{
					breakLoop = true;
					break;
				}
			}
			if (breakLoop)
			{
				break;
			}
			stack<int> stationA, stationB;
			int i = 1;
			int curr = 0;
			while (curr < N)
			{
				if (!stationB.empty() && stationB.top() == order[curr])
				{
					stationA.push(stationB.top());
					stationB.pop();
				}
				else if (stationB.empty() || stationB.top() != order[curr])
				{
					while (i <= N)
					{
						stationB.push(i);
						i++;
						if (order[curr] == stationB.top())
						{
							stationA.push(stationB.top());
							stationB.pop();
							break;
						}
					}
				}
				else
				{
					stationA.push(i);
					i++;
				}
				curr++;
			}
			if (stationB.empty())
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		cout << endl;
	}
    return 0;
}

