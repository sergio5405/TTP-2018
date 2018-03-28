#include <stdio.h>
#include <algorithm>

using namespace std; 

int main (){
	int C, N;
	
	scanf("%d", &C);
	while(C--){
		scanf("%d", &N);
		bool turn = 1;
		int cur= (N-1)/3;
		int next;
		N-=cur;
		while (N>0){
			next = min(cur*2, (N-1)/3);
			N -= next;

			cur = next;
			turn = !turn;
		}

		if(turn)
			printf("%s\n", "Harry wins");
		else
			printf("%s\n", "Ron wins");
	}


	return 0;
}