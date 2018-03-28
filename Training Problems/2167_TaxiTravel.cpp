#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>

#define PI 3.14

using namespace std;

int main(){
	int T, N, d;
	int count[5];
	scanf("%d", &T);

	while(T--){
		scanf("%d", &N);
		memset(count, 0, 5*sizeof(int));
		while(N--){
			scanf("%d", &d);
			count[d]++;
		}

		int total = count[4];
		int min1_3 = min(count[1], count[3]);
		total += min1_3;
		count[1] -= min1_3;
		count[3] -= min1_3;

		total += count[3];
		total+=count[2]/2;
		count[2] %= 2;
		if (count[2]) {
			count[1] -= 2;
			total++;
		}
		if (count[1] > 0)
			total += (count[1] + 3)/ 4;

		printf("%d\n", total);
	}
	
	return 0;
}