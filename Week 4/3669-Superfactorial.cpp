#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std; 

typedef unsigned long long int lli;

int main (){
	int N;

	scanf("%d", &N);

	lli sum = 0;
	lli last = 0;

	for (int i = 2; i <= N; ++i){
		int t = i;
		int now = last;
		while(!(t&1)){
			now++;
			t>>=1;
		}

		sum += now;
		last = now;
	}

	printf("%llu\n", sum);



	return 0;
}