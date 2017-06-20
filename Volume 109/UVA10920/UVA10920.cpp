#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	long long P, SZ;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> SZ >> P && SZ && P)
	{
		if(P == 1)
		{
			cout << "Line = " << SZ/2 + 1 << ", column = " << SZ/2 + 1 << "." << endl;
			continue;
		}
		long long curr = 1;
		long long ring = 0;
		while(curr * curr < P)
		{
			curr += 2;
			ring ++;
		}
		if(P == SZ * SZ)
		{
		//	cout << 0 << endl;
			//cout << curr << " " << P << endl;
			cout << "Line = " << SZ << ", column = " << SZ << "." << endl;
			//continue;
		}
		else
		{
			//cout << "yo" << endl;
			//cout << curr * curr << " " << P << endl;
			long long p1 = (curr - 2)*(curr-2)+1;
			long long p2 = p1 + (ring * 2);
			long long p3 = p2 + (ring * 2);
			long long p4 = p3 + (ring * 2);
			//cout << "P " <<  P << ", SZ " << SZ << endl;
			//cout << p1 << " " << p2 <<  " " << p3 << " " << p4 << endl;
			//cout << ring << endl;
			if(P >= p1 && P < p2)
			{
				long long x = ((SZ/2) + 1) + ring - (P-p1)-1;
				long long y = ((SZ/2) + 1) + ring;
				//cout << 1 << endl;
				cout << "Line = " << y << ", column = " << x << "." << endl;
			}
			else if(P >= p2 && P < p3)
			{
				long long x = ((SZ/2) + 1) - ring;
				long long y = ((SZ/2) + 1) + ring - (P-p2)-1;
				//cout << 2 << endl;
				cout << "Line = " << y << ", column = " << x << "." << endl;
			}
			else if(P >= p3 && P < p4)
			{
				long long x = ((SZ/2) + 1) - ring + (P-p3)+1;
				long long y = ((SZ/2) + 1) - ring;
				//cout << 3 << endl;
				cout << "Line = " << y << ", column = " << x << "." << endl;
			}
			else if(P >= p4)
			{
				long long x = ((SZ/2) + 1) + ring;
				long long y = ((SZ/2) + 1) - ring + (P-p4)+1;
				//cout << 4 << endl;
				cout << "Line = " << y << ", column = " << x << "." << endl;
			}
		}
	}
	
	return 0;
}