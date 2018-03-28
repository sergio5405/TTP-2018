#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std; 

int main (){
	string s;
	int T;

	cin >> T;
	while(T--){
		cin >> s;
		if(s.length()>10){
			printf("%c%lu%c\n", s[0], s.length()-2, s[s.length()-1]);
		}else{
			cout<<s<<endl;
		}
	}


	return 0;
}