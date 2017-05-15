// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define llp pair<long long, long long>
#define iii pair<int,ii>

using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	int k;
	while (cin >> k)
	{
		vector<llp> vals;
		for (int i = k + 1; i <= k * 2; i++)
		{
			if ((i*k)%(i-k)==0)
			{
				vals.push_back(llp((i*k)/(i-k), i));
			}
		}
		cout << vals.size() << endl;
		for (int i = 0; i < vals.size(); i++)
		{
			cout << "1/" << k << " = " << "1/" << vals[i].first << " + " << "1/" << vals[i].second << endl;
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
