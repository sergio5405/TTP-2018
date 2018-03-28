#include <stdio.h>

using namespace std;

int N;


int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}


int main(){
	
	scanf("%d", &N);
	int cont = 1;
	for(int i = 2; i<N; i++){
		if(gcd(N, i)==1)
			cont++;
		
	}

	printf("%d\n",cont);

	return 0;
}