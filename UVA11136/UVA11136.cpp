#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    std::ios_base::sync_with_stdio(false);
    while(cin >> n)
    {
        multiset<int> bills;
        long sum = 0;
        if(n == 0)
        {
            break;
        }
        while(n--)
        {
            int k;
            cin >> k;
            while(k --)
            {
                int temp;
                cin >> temp;
                bills.insert(temp);
            }
            multiset<int>::iterator it = bills.begin();
            multiset<int>::iterator it2 = bills.end();
            it2 --;
            sum += *it2-*it;
            bills.erase(it);
            bills.erase(it2);
        }
        cout << sum << endl;
    }
	return 0;
}
