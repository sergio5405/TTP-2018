#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std; 

int main (){
	int T;
	scanf("%d", &T);

	char word[14];

	while(T--){
		scanf("%s", word);
		int sum = 0;
		for (int i = 0; i < 13; ++i){
			sum+=word[i]-'0';
		}

		int mul = 10;
		for (int i = 0; i < 3; ++i){
			sum+=(word[12-i]-'0')*mul;
			mul*=10;
		}

		if(sum>=10000){
			sum%=10000;
		}else if(sum<1000){
			sum+=1000;
		}

		printf("%04d\n", sum);
	}

	return 0;
}