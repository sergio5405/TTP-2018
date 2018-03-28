#include <iostream>
#include <algorithm>
#include <cmath>

typedef unsigned long long int lli;
using namespace std; 

int main (){
	lli D, V;

	scanf("%llu %llu", &D, &V);

	if (D== (V*(V-3))/2)
		printf("%s\n", "yes");
	else
		printf("%s\n", "no");

	return 0;
}