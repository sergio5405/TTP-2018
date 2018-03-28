#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std; 

int main (){
	int N;

	scanf("%d", &N);

	int options = (int)log2(N) + 1;

	printf("%d\n", options);

	return 0;
}