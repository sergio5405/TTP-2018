#include <iostream>
#include <string>

using namespace std;

string s1, s2;

int main(){
	cin >> s1 >> s2;
	
	while(cin){
		int j = 0;

		for (int i = 0; i < s2.length() && j<s1.length(); i++){
			if (s2[i]==s1[j]){
				j++;
			}
		}

		if (j==s1.length())
			cout << "Yes";
		else
			cout << "No";
		cout << endl;

		cin >> s1 >> s2;
	}
	
	return 0;
}