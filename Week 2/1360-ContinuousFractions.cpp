#include <stdio.h>

typedef unsigned long long int lli;

lli P, Q, Pinit, Qinit;

lli arr[1000];

int main(){

	scanf("%llu %llu", &P, &Q);
	
	while(P!=0&&Q!=0){
		printf("%llu/%llu=[", P, Q);
		int cont = 0;
		while(P!=1){
			if(P%Q == 0){
				arr[cont++] = (P/Q) -1;
				P=1;
				Q = 1;
			}else{
				arr[cont++] = P/Q;
				P = P%Q;
			}

			lli temp = P;
			P = Q;
			Q = temp;
		}

		for (int i = 0; i < cont; ++i){
			printf("%llu,", arr[i]);
		}
		printf("1]\n");
		scanf("%llu %llu", &P, &Q);
	}

	return 0;
}