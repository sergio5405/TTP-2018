#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std; 

typedef long long int lli;

int dp[13][10000001];
int candies[13];
int prices[13];

int N, P;


void printMatrix(){
	printf("\n");
	for (int i = 0; i <= N; ++i){
		for (int j = 0; j <= P; ++j){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}	
}

int main (){

	scanf("%d %d", &N, &P);

	dp[0][0] = 1;


	for (int i = 1; i <= N; ++i){
		scanf("%d", &candies[i]);
	}

	for (int i = 1; i <= N; ++i){
		scanf("%d", &prices[i]);
	}

	for (int i = 1; i <= N; ++i){
		int amountC = candies[i];
		int price = prices[i];

		for (int j = price; j <= min(P, price*amountC); j+=price){
			dp[i][j] = dp[i-1][j] + 1;
		}

		for (int j = 0; j <= P; ++j){
			dp[i][j] += dp[i-1][j];
				
			if(j>price)
				dp[i][j]+=dp[i-1][j-price];
		}

		// printMatrix();
		// printf("\n");
	}

	printf("%d\n", dp[N][P]);

	return 0;
}