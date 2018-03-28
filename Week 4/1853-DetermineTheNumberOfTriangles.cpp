#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>

using namespace std; 

typedef unsigned long long int lli;

int nCr(int n){
	if (n<3)
		return 0;

	int C[4];
	memset(C, 0, 4*sizeof(int));
	C[0] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = min(i, 3); j > 0; j--)
			C[j] = C[j] + C[j-1];

	return C[3];
}

int main (){
	int N, T;

	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		N++;
		int total = nCr(N*N);
		total -= (N*nCr(N))*2; //horizontales y vert

		for (int i = 3; i <= N; ++i){
			if (i!=N)
				total-= 4*nCr(i);
			else
				total-= 2*nCr(i);
		}

		for (int i = 1; 2*(i+1) <= N; ++i){
			for (int j = i+1; 2*j <= N; ++j){
				total -= 4*(N-2*j)*(N-2*i);
			}
		}


		printf("%d\n", total);
	}

	return 0;
}