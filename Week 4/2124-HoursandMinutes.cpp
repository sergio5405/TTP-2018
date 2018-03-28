#include <iostream>
#include <algorithm>
#include <cmath>

typedef unsigned long long int lli;
using namespace std; 

int main (){
	int G;

	while(scanf("%d", &G)!=EOF){
		printf("%s\n", (G%6)?"N":"Y" );
	}

	return 0;
}