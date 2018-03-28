#include <stdio.h>
#include <algorithm>
#include <set>

int N;

int minVal = 1000000007;
int vecA[8];
int vecB[8];

using namespace std;

void backtrack(int currentA, int currentSum, set<int> used){
	if(currentA==N){
		if(currentSum<minVal)
			minVal = currentSum;
		return;
	}

	for (int i = 0; i < N; ++i){
		if(used.find(i)==used.end()){
			used.insert(i);
			backtrack(currentA+1, currentSum+vecA[currentA]*vecB[i], used);
			used.erase(i);
		}
	}
}

int main (){
	
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &vecA[i]);

	for (int i = 0; i < N; ++i)
		scanf("%d", &vecB[i]);

	set<int> used;

	backtrack(0,0, used);

	printf("%d\n", minVal);

	
	return 0;
}