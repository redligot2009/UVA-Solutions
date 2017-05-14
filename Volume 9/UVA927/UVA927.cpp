#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
 
int main() {
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--)
	{
		vector<pair<ii,string>> database;
		int D;
		cin >> D;
		while(D--)
		{
			string s;
			int l, h;
			cin >> s >> l >> h;
			database.push_back(pair<ii,string>(ii(l,h), s));
		}
		int Q;
		cin >> Q;
		while(Q--)
		{
			int P;
			cin >> P;
			bool found = false;
			string ans;
			int count = 0;
			for(int i = 0; i < database.size(); i ++)
			{
				if(P >= database[i].first.first && P <= database[i].first.second)
				{
					ans = database[i].second;
					count ++;
				}
				if(count > 1)
				{
					break;
				}
			}
			if(count == 0||count > 1)
			{
				cout << "UNDETERMINED" << endl;
			}
			else
			{
				cout << ans << endl;
			}
		}
		if(T > 0)
		{
			cout << endl;
		}
	}
	return 0;
}