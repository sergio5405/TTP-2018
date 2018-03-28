#include <iostream>
#include <string>

using namespace std;

string s;
int g;

int main(){
	cin >> g;
	
	while(g!=0){
		cin >> s;
		
		for (int i = 1; i <= g; ++i){
			int lenG = s.length()/g;
			for (int j = 1; j <= lenG; ++j){
				cout << s[lenG*i-j];
			}
		}


		cout << endl;

		cin >> g;
	}
	
	return 0;
}