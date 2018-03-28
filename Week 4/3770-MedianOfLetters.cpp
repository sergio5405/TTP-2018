#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std; 

int main (){
	string s;
	
	cin >> s;

	sort(s.begin(), s.end());

	cout << s[s.length()/2] <<endl;

	return 0;
}