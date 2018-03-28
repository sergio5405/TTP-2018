#include <stdio.h>

int T, N, K;

int arr[50];

using namespace std;

int main(){

	scanf("%d", &T);
	
	while(T--){
		scanf("%d %d", &N, &K);
		K--;
		for (int i = 0; i < N; ++i){
			scanf("%d", &arr[i]);
		}
		int cont = 0;
		for (int i = 0; i < N; ++i){
			if (arr[i]>=arr[K]&&arr[i]>0){
				cont++;
			}
		}

		printf("%d\n", cont);
	}

	return 0;
}