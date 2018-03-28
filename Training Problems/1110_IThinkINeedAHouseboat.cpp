#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#define PI 3.14

using namespace std;


int main(){
	int T;
	double x, y;
	scanf("%d", &T);

	for(int t = 1; t<=T; t++){
		scanf("%lf %lf", &x, &y);

		double dis = sqrt(x*x + y*y);

		int years = (int) (PI*dis*dis / 100) +1;

		printf("Property %d: This property will begin eroding in year %d.\n", t, years);
	}

	printf("END OF OUTPUT.\n");
	
	return 0;
}