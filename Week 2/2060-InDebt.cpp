#include <stdio.h>

int N, Pi;

using namespace std;

int main(){

	scanf("%d", &N);
	
	while(N!=-1){
		int total = 0;
		int ans = 0;
		while(N--){
			scanf("%d", &Pi);
			total += Pi;

			if(total%100==0){
				total=0;
				ans++;
			}
		}

		printf("%d\n", ans);

		scanf("%d", &N);
	}

	return 0;
}