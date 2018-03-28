#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std; 

int main (){
	int T, R;
	
	scanf("%d", &T);

	int last = 1;
	int total = 0;

	for (int i = 0; i < T; ++i){
		scanf("%d", &R);

		total += abs(last-R);

		last = R;
	}

	total += abs(last-1);

	printf("%d\n", total);


	return 0;
}