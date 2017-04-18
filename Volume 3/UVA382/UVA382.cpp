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
	cout << "PERFECTION OUTPUT" << endl;
	while (cin >> N && N)
	{
		int positiveSum = 0;
		if (N > 1)
		{
			for (int i = 1; i < N; i++)
			{
				if (N%i == 0)
				{
					positiveSum += i;
				}
			}
		}
		if (positiveSum == N)
		{
			cout << setw(5) << N << "  " << "PERFECT" << endl;
		}
		else if (positiveSum < N)
		{
			cout << setw(5) << N << "  " << "DEFICIENT" << endl;
		}
		else
		{
			cout << setw(5) << N << "  " << "ABUNDANT" << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
	//fclose(stdin);
	//fclose(stdout);
    return 0;
}

