#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>


using namespace std;


char table[100][100];

int main(){
	int T;
	string word;

	cin >> T;
	getline(cin, word);

	for (int t = 0; t < T; t++){
		getline(cin, word);

		int sqlen = sqrt(word.length());
		int strIt = 0;
		for (int j = 0; j<sqlen; j++){
			for (int i = sqlen-1; i>=0; i--){
				table[i][j] = word[strIt++];
			}
		}

		for (int i = 0; i<sqlen; i++){
			for (int j = 0; j<sqlen; j++){
				cout << table[i][j];
			}
		}

		cout << endl;

	}
	
	return 0;
}