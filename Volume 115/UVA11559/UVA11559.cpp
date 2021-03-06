#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, H, W, p;
	long long B, minPrice;
	//UVA 11559 Red Ligot 3/22/2017, Rank #2736
	while(scanf("%d %lld %d %d", &N, &B, &H, &W) == 4)
	{
		minPrice = LONG_MAX;
		long long prices[18] = {0};
		long long amount[18] = {0};
		for(int i = 0; i < H; i ++)
		{
			int price;
			scanf("%d",&price);
			prices[i] = price;
			for(int j = 0; j < W; j ++)
			{
				int a;
				scanf("%d",&a);
				amount[i] += a * price;
			}
		}
		for(int i = 0; i < H; i ++)
		{
			int price = prices[i];
			long long currSum = amount[i];
			int tempN = N;
			long long tempB = B;
			long long finalSum = 0;
			while(tempN > 0)
			{
				if(tempB - price >= 0 && currSum - price >= 0)
				{
					currSum -= price;
					tempB -= price;
					finalSum += price;
					tempN --;
				}
				else
				{
				    break;
				}
			}
			if(tempN == 0)
			{
			    minPrice = min(finalSum,minPrice);
			}
		}
		if(minPrice != LONG_MAX)
		{
			printf("%d\n", minPrice);
		}
		else
		{
			printf("stay home\n");
		}
	}
	return 0;
}