#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>

int F, S;

using namespace std;


int main (){
	
	scanf("%d %d", &F, &S);
	int caseNum = 1;
	while(F!=-1&&S!=-1){
		set<int> sons;
		bool tree = true;
		while(F!=0&&S!=0){
			if(sons.find(S)==sons.end()){
				sons.insert(S);
			}else{
				tree = false;
			}

			scanf("%d %d", &F, &S);
		}

		cout <<"Case " << caseNum << ((tree)?" is ":" is not ") << "a tree.\n";

		caseNum++;
		scanf("%d %d", &F, &S);
	}
	
	return 0;
}