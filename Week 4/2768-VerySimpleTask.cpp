#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std; 

typedef unsigned long long int lli;


lli getNPower(int N){
	if(N==1)
		return 2;
	if(N==0)
		return 1;

	lli res = (lli) getNPower(N/2)%1000000007;
	res *= res;
	res %= 1000000007;

	if (N%2)
		res*=2;

	res %= 1000000007;

	return res;
}

int main (){
	int N;

	scanf("%d", &N);
	while(N){
		lli p = getNPower(N+1);
		p--;

		printf("%llu\n", p);

		scanf("%d", &N);
	}


	return 0;
}