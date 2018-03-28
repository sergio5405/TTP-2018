#include <stdio.h>
#include <algorithm>

int D, H, M;

using namespace std;

int main(){
	
	int now = 24*60*11 + 60*11 + 11;

	scanf("%d %d %d", &D, &H, &M);

	int end = 24*60*D + 60*H + M;
	
	printf("%d\n", (int) max(end-now, -1));

	return 0;
}