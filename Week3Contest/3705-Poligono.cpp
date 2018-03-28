#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std; 

typedef long long int lli;

lli dp[13][10000001];
int candies[13];
int prices[13];

int N;

int main (){

	scanf("%d %d", &N, &P);

	dp[0][0] = 1;


	for (int i = 1; i <= N; ++i){
		scanf("%d %d", &candies[i], &prices[i]);
	}

	for (int i = 1; i <= N; ++i){
		int amountC = candies[i];
		int price = prices[i];
		for (int j = 1; j <= amountC; ++j){
			dp[i][j*price] = dp[i-1][j*price]+1;
		}

		for (int j = 1; j <= amount; ++j){
			dp[i][j] = dp[i-1][j];
				
			if(j>=price)
				dp[i][j]+=dp[i-1][j-price];
		}
	}

	printf("%lld\n", dp[N][P]);

	return 0;
}