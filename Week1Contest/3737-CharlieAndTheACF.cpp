#include <stdio.h>
#include <algorithm>
#include <vector>

typedef long long int lli;

lli N, M, sum = 0, Bi;

lli A[100001];
lli sumA[100001];
lli B[100001];

using namespace std;

int main(){
	
	scanf("%lld %lld", &N, &M);

	for (int i = 0; i < N; ++i){
		scanf("%lld", &A[i]);
	}

	sort(A, A+N);
	sumA[0] = A[0];

	for (int i = 1; i < N; ++i){
		sumA[i]=sumA[i-1]+A[i];
	}


	for (int i = 0; i < M; ++i){
		scanf("%lld", &Bi);


    	lli * lowe = lower_bound(A, A+N, Bi);
    	lli idx = (int)(lowe-A);
    	// idx--;

    	

    	lli leftItems = idx;
    	lli rightItems = N-idx;

    	

    	if(idx>0)
    		sum+=(Bi*leftItems-sumA[idx-1])+((sumA[N-1]-sumA[idx-1])-Bi*rightItems);
    	else
    		sum+=((sumA[N-1])-Bi*rightItems);

	}

	
	printf("%lld\n", sum);

	return 0;
}