#include <stdio.h>

long long int N;

int main(){
	
	scanf("%lld", &N);
	
	while(N!=-1){
		long long int m = 0;
		long long int f = 1;
		
		for (int i = 0; i < N; ++i){
			long long int tempC = 1+m;
			long long int tempD = m+f;
			
			f = tempC;
			m = tempD;
		}

		printf("%lld %lld\n", m, m+f);

		scanf("%lld", &N);
	}

	return 0;
}