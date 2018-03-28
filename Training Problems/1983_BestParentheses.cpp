#include <iostream>
#include <stack>

using namespace std;

int main(){
	int N, d;
	long long int total = 0;
	
	stack <int> st;


	scanf("%d", &N);
	long long int current = 0;
	while(N--){
		scanf("%d", &d);

		if(d==0){
			st.push(d);
		}else{
			st.pop();

			if (current)
				current<<=1;
			else
				current++;

			current %= 12345678910;
		}

		if(st.empty()){
			total += current % 12345678910;
			current = 0;
		}
		
	}

	printf("%lld\n", total%12345678910);
	
	return 0;
}