// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define llp pair<long long, long long>
#define iii pair<int,ii>

using namespace std;

int N, M;
vector<int> arr;
vector<int> bestPath;
int bestSum = 0;

void sumUp(vector<int> path, int sum = 0, int pos = 0)
{
	path.push_back(arr[pos]);
	sum += arr[pos];
	if (sum > bestSum || (sum == bestSum && path.size() > bestPath.size()))
	{
		bestSum = sum;
		bestPath = path;
	}
	for (int i = pos + 1; i < arr.size(); i++)
	{
		if (sum + arr[i] <= N)
		{
			sumUp(path, sum, i);
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	while (cin >> N >> M)
	{
		while (M--)
		{
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		for (int i = 0; i < arr.size(); i++)
		{
			vector<int> path;
			sumUp(path, 0, i);
		}
		for (int i = 0; i < bestPath.size(); i++)
		{
			cout << bestPath[i] << " ";
		}
		cout << "sum:" << bestSum << endl;
		bestSum = 0;
		bestPath.clear();
		arr.clear();
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
