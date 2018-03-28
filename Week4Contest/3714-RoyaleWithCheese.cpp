#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std; 

map<char, int> m;

void swap(char first, int secondId){
	if (m.find(first) == m.end()){ //contains
		return;
	}

	m[first] = secondId;
}

int main (){
	string s;

	while(cin >> s){
		m.clear();

		char ca[27];

		for (int i = 0; i < s.length(); ++i){
			if (m.find(s[i]) == m.end()){ //contains
				ca[m.size()+1] = s[i];
				m[s[i]] = m.size()+1;
			}
		}

		//swap
		swap(ca[2],5);
		swap(ca[5],2);

		swap(ca[6],9);
		swap(ca[9],6);

		swap(ca[12],15);
		swap(ca[15],12);

		swap(ca[16],19);
		swap(ca[19],16);

		swap(ca[20],50);
		swap(ca[21],51);
		swap(ca[22],55);
		swap(ca[23],53);
		swap(ca[24],54);
		swap(ca[25],52);
		swap(ca[26],59);

		for (int i = 0; i < s.length(); ++i){
			printf("%d", m[s[i]]);
		}

		printf("\n");
	}

	return 0;
}

