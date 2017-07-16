#include <bits/stdc++.h>
using namespace std;

vector<int> sieve;
bool isPrime[1000000+1];
int idx[1000000+1];

void genSieve()
{
	memset(&isPrime,true,sizeof(isPrime));
	for(int i = 2; i <= 1000000; i ++)
	{
		if(isPrime[i])
		{
			sieve.push_back(i);
			idx[i] = sieve.size()-1;
			for(int j = i*2; j <= 1000000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int nextPrime(int N)
{
	while(!isPrime[N])
	{
		N ++;
	}
	return N;
}
int prevPrime(int N)
{
	while(!isPrime[N])
	{
		N--;
	}
	return N;
}

int main() {
	// your code goes here
	genSieve();
	int n;
	/*for(int i = 0; i < sieve.size(); i ++)
	{
		cout << sieve[i] << " ";
	}
	cout << endl;*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n && n != 0)
	{
		int j = idx[nextPrime(n)];
		if(j == 0)
		{
			j = idx[prevPrime(n)];
		}
		int i = 0;
		while(j-i >= 0)
		{
			//cout << sieve[i] << " + " << sieve[j] << endl;
			if(sieve[i] + sieve[j] == n)
			{
				cout << n << " = " << sieve[i] << " + " << sieve[j] << endl;
				break;
			}
			else if(sieve[i] + sieve[j] < n)
			{
				i ++;
			}
			else
			{
				j --;
			}
		}
	}
	return 0;
}