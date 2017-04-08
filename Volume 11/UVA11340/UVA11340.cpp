#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main() {
	int N, M, K;
	cin >> N;
	string lines[150000];
	map<char,int> costMap;
	cout << fixed << setprecision(2);
	while(N--)
	{
		cin >> K;
		for(int i = 0; i < K; i++)
		{
			char c;
			int price;
			cin >> c >> price;
			costMap[c] = price;
		}
		cin >> M;
		cin.ignore();
		for(int i = 0; i < M; i ++)
		{
			getline(cin,lines[i]);
			//cout << lines[i] << endl;
		}
		double sum = 0;
		for(int i = 0; i < M; i ++)
		{
			string line = lines[i];
			for(int j = 0; j < line.length(); j ++)
			{
				if(costMap[line[j]] > 0)
				{
					sum += costMap[line[j]];
				}
			}
		}
		sum *= 0.01;
		cout << sum << "$" << endl;
		costMap.clear();
	}
	return 0;
}