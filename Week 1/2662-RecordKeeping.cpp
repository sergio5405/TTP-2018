#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

string name1, name2, name3;

int main(){
	
	map<set<string>, int> m;
	int N;
	cin >> N;

	while(N--){
		set<string> curr;

		cin >> name1 >> name2 >> name3;
		curr.insert(name1);
		curr.insert(name2);
		curr.insert(name3);
		if (m.find(curr) != m.end()){ //contains
			m[curr]++;
		}else{
			m[curr] = 1;
		}
	}

	int max = 0;

	for (map<set<string>, int>::iterator it=m.begin(); it!=m.end(); ++it){
		if (it->second>max)
			max = it->second;
	}

	cout << max << endl;
	
	return 0;
}