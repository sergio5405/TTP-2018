#include <iostream>
#include <algorithm>
#include <string>

using namespace std; 

int main (){
	string s;

	int one = 0, two = 0, three = 0;
	
	cin >> s;
	
	for (int i = 0; i < s.length(); ++i){
		if (s[i]=='+')
			continue;

		if (s[i]=='1')
			one++;
		else if (s[i]=='2')
			two++;
		else
			three++;
	}

	int total = one + two + three;

	string result = "";

	for (int i = 0; i < one; ++i){
		result += "1+";
	}

	for (int i = 0; i < two; ++i){
		result += "2+";
	}

	for (int i = 0; i < three; ++i){
		result += "3+";
	}

	cout << result.substr(0, result.length()-1) << endl;

	return 0;
}