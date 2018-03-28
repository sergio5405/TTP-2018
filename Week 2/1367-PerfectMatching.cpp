#include <stdio.h>
#include <algorithm>
#include <cmath>

int T, N;

char matrix[300][300];
double A[300][300];

void gauss(){
	for (int i=0; i<N; i++) {
		// Search for maximum in this column
		double maxEl = abs(A[i][i]);
		int maxRow = i;
		for (int k=i+1; k<N; k++) {
			if (abs(A[k][i]) > maxEl) {
				maxEl = abs(A[k][i]);
				maxRow = k;
			}
		}

		// Swap maximum row with current row (column by column)
		for (int k=i; k<N+1;k++) {
			double tmp = A[maxRow][k];
			A[maxRow][k] = A[i][k];
			A[i][k] = tmp;
		}

		// Make all rows below this one 0 in current column
		for (int k=i+1; k<N; k++) {
			double c = -A[k][i]/A[i][i];
			for (int j=i; j<N+1; j++) {
				if (i==j) {
					A[k][j] = 0;
				} else {
					A[k][j] += c * A[i][j];
				}

				A[k][j]=(int)A[k][j]%2;
			}
		}
	}
}


int main(){

	scanf("%d", &T);
	
	while(T--){
		scanf("%d", &N);

		for (int i = 0; i < N; ++i){
			scanf("%s", matrix[i]);
		}

		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				A[i][j]=matrix[i][j]-'0';
			}
		}

		gauss();
		int det = 1;
		for (int i = 0; i < N; ++i){
			det*=(int)A[i][i];
		}

		if (det){
			printf("%s\n", "Odd");
		}else{
			printf("%s\n", "Even");
		}

	}

	return 0;
}