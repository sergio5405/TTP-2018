#include <stdio.h>
#include <algorithm>

using namespace std;

int T, N, L, M;

long long int dp[1000][1001];

int main(){
	
	scanf("%d", &T);

	while(T--){
		scanf("%d %d %d", &N, &L, &M);

		M = min(N-1, M);

		for (int i = 0; i <= N; ++i){
			dp[0][i]=i;
		}

		for (int i = 0; i < L; ++i){
			dp[i][0]=0;
		}

		for (int i = 1; i < L; ++i){
			for (int j = 1; j <= N; ++j){
				dp[i][j] = dp[i][j-1];

				long long int maxVal = ((j+M<N)?dp[i-1][j+M]:dp[i-1][N]) % 1000000007;
				long long int minVal = ((j-M-1>0)?dp[i-1][j-M-1]:dp[i-1][0]) % 1000000007;
				
				dp[i][j] += (maxVal - minVal);
				dp[i][j]%=1000000007;
			}
		}

		// printMatrix();

		printf("%lld\n", dp[L-1][N]);
	}

	return 0;
}