#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std; 

int T;

int main (){
	scanf("%d", &T);

	while(T--){
		int sum = 0, sumi;
		for (int i = 0; i < 10; ++i){
			scanf("%d", &sumi);
			sum+=sumi;
		}

		printf("%.03f\n", sum*0.85);
	}

	return 0;
}