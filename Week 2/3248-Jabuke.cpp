#include <stdio.h>
#include <algorithm>

int N, M, beg, end, J, Ji, totPlaces = 0;


int main(){

	scanf("%d %d", &N, &M);
	
	beg = 1;
	end = beg + M - 1;

	scanf("%d", &J);

	while(J--){
		scanf("%d", &Ji);

		if (beg<=Ji&&Ji<=end){
			continue;
		}else if(beg>Ji){
			int places = beg-Ji;
			totPlaces += places;
			beg -= places;
			end -= places;
		}else{
			int places = Ji-end;
			totPlaces += places;
			beg += places;
			end += places;
		}
	}

	printf("%d\n", totPlaces);

	return 0;
}