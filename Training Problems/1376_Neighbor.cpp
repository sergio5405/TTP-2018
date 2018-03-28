#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


int main(){
	string word;
	
	getline(cin, word);
	if(!next_permutation(word.begin(), word.end()))
		cout << 0 << endl;
	else
		cout << word << endl;	
	
	return 0;
}