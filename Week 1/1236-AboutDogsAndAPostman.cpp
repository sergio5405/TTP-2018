#include <iostream>
#include <string>

using namespace std;

int A, B, C, D, p, m, g;
int her[3];

int main(){
	cin >> A >> B >> C >> D >> her[0] >> her[1] >> her[2];

	for (int i = 0; i <= 2; ++i){
		int dogs = 0;
		int tot1 = A + B;
		int newP = her[i]%tot1;

		if(newP<=A&&newP!=0)
			dogs++;

		int tot2 = C + D;
		newP = her[i]%tot2;

		if(newP<=C&&newP!=0)
			dogs++;

		if(dogs==0)
			cout << "none";
		else if(dogs == 1)
			cout << "one";
		else
			cout << "both";
		cout << endl;
	}
	
	return 0;
}