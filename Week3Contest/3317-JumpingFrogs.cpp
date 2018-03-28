#include <stdio.h>
#include <algorithm>
#include <string>

#define MAX 1000000007

typedef unsigned long long int lli;

using namespace std; 

int T, N;

lli fib[1000001];

int main (){
	fib[0] = 1;
	fib[1] = 1;

	for (int i = 2; i <= 1000000; ++i){
		fib[i] = ((fib[i-1]%MAX) + (fib[i-2]%MAX))%MAX;
	}

	scanf("%d", &T);

	while(T--){
		scanf("%d", &N);

		printf("%llu\n", fib[N]);
	}

	return 0;
}