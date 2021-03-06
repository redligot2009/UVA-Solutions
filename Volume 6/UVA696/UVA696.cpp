#include <iostream>
#include <cmath>
using namespace std;
//Red Ligot 3/27/2017 ranked #323
int solve(int m, int n)
{
    int sum = 0;
    if(n > m)
    {
        swap(m,n);
    }
    if(m > 2 && n > 2)
    {
        int halfCol = ceil((float)n/2);
        if(n % 2)
        {
            for(int i = 1; i <= m; i ++)
            {
                if(i % 2)
                {
                    sum += halfCol;
                }
                else
                {
                    sum += halfCol - 1;
                }
            }
        }
        else
        {
            sum += halfCol * m;
        }
    }
    else if(m <= 2 || n == 1 || m == 1)
    {
        sum = m * n;
    }
    else if(n == 2)
    {
        if(m % 4 && m % 2 == 0)
        {
            sum += m + 2;
        }
        else if(m % 4 && m % 2)
        {
            sum += m + 1;
        }
        else if(m % 4 == 0)
        {
            sum += m;
        }
    }
    return sum;
}
int main() {
	int m, n;
	while(cin >> m >> n)
	{
	    if(m == 0 && n == 0)
	    {
	        break;
	    }
	    if(m != 0 || n != 0)
	    {
	        int sum = solve(m,n);
    	    cout << sum << " knights may be placed on a " << m << " row " << n << " column board." << endl;
	    }
	    else
	    {
	        cout << 0 << " knights may be placed on a " << m << " row " << n << " column board." << endl;
	    }
	}
	return 0;
}
