#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main (){
	string s;
	regex e ("BUG");

	getline (cin,s);
	while(cin){
		cout << regex_replace (s,e,"") << endl;
		getline (cin,s);
	}


	return 0;
}