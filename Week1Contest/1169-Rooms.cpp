#include <stdio.h>
#include <math.h>

int rooms[100];
int G, N, gi;

int main(){
	
	scanf("%d %d", &N, &G);
	
	for (int i = 0; i < G; ++i){
		scanf("%d", &gi);
		//find empty
		int roomIdx = 0;
		for (int i = 0; i < N; ++i){
			if(rooms[i]==0){
				roomIdx = i;
				break;
			}
		}

		while(gi!=0){
			if(rooms[roomIdx]==0){
				if(gi>=2){
					gi-=2;
					rooms[roomIdx]+=2;
				}else{
					gi--;
					rooms[roomIdx]+=1;
				}
			}else if(rooms[roomIdx]==1){
				gi--;
				rooms[roomIdx]+=1;
			}

			roomIdx++;
			if(roomIdx>=N)
				roomIdx=0;
		}
	}

	for (int i = 0; i < N; ++i){
		printf("%d\n", rooms[i]);
	}

	return 0;
}