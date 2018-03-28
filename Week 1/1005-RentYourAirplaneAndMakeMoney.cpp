#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

struct Order{
	int start;
	int end;
	int price;
};

bool orderCompare(Order a, Order b){
	return a.end < b.end; 
}

Order arr[10001];
int parents[10001];
int tail[10001];
int lis[10001];


int main(){
	int T, N, start, duration, price;
	
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);

		memset(lis, 0, N+1);

		if(N==0){
			printf("0\n");
			continue;
		}

		for (int i = 0; i < N; ++i){
			scanf("%d %d %d", &start, &duration, &price);
			Order cur = {start, start+duration, price};
			arr[i] = cur;
		}

		sort(arr, arr+N, orderCompare);
		
		for (int i = 0; i < N; ++i)
			tail[i] = arr[i].end;

		for(int i = N-1; i>=0; i--){
			int low = 0;
			int high = N;

			while (low<high){
				int mid = low + (high-low)/2;

				if (arr[i].start >= tail[mid])
					low = mid + 1;
				else
					high = mid;
			}

			parents[i] = low;
		}

		for (int i = 1; i <= N; ++i)
			lis[i] = max(lis[i-1], arr[i-1].price+lis[parents[i-1]]);

		printf("%d\n", lis[N]);
	}
	
	return 0;
}