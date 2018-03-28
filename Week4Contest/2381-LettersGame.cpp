#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std; 

int main (){
	int count[26];
	memset(count, 0, 26*sizeof(int));

	int points[26];
	memset(points, 0, 26*sizeof(int));

	int N;
	int k;

	char word[1000001];
	
	scanf("%d", &N);
	scanf("%s", word);
	scanf("%d", &k);

	int cum = 0;

	for (int i = 0; i < N; ++i){
		count[word[i]-'A']++;
	}

	for (int i = 0; i < 26; ++i){
		points[i] = count[i]*(N-count[i]-cum);
		cum+=count[i];
	}

	int oddPoints = 0;
	int evenPoints = 0;

	for (int i = 0; i < 26; ++i){
		if(i%2)
			oddPoints+=points[i];
		else
			evenPoints+=points[i];
	}

	if(evenPoints>oddPoints){
		if(k%2==0){
			printf("PEPE %d\n", evenPoints-oddPoints);
		}else{
			printf("JUAN %d\n", evenPoints-oddPoints);
		}
	}else if(evenPoints<oddPoints){
		if(k%2==0){
			printf("JUAN %d\n", oddPoints-evenPoints);
		}else{
			printf("PEPE %d\n", oddPoints-evenPoints);
		}
	}else{
		int i;
		for (i = 25; i >=0; ++i){
			if(points[i]>0){
				if(k%2==0){ // even - pepe
					if (i%2==0){
						printf("PEPE %d\n", evenPoints-oddPoints);
					}else{
						printf("JUAN %d\n", evenPoints-oddPoints);
					}
				}else{//even juan
					if (i%2==0){
						printf("JUAN %d\n", evenPoints-oddPoints);
					}else{
						printf("PEPE %d\n", evenPoints-oddPoints);
					}
				}
			}
		}
	}

	return 0;
}