#include <stdio.h>
#include <string>
#include <regex>

using namespace std;

int dp[300];

int countTrees(int n) {
	if(n<=1)
		return dp[1];

	if(dp[n]!=0)
		return dp[n];


	int sum = 0; 
	int left, right;

	for (int i=1; i<=n; i++) { 
		left = countTrees(i - 1); 
		right = countTrees(n - i);

		sum += left*right; 
	}

	dp[n] = sum;
	return dp[n];

} 

int main (){
	int N;
	dp[1]=1;
	dp[0]=1;
	scanf("%d", &N);
	while(N!=0){
		printf("%d\n", countTrees(N));
		scanf("%d", &N);
	}


	return 0;
}