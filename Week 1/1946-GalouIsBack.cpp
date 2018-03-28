#include <stdio.h>
#include <map>
#include <set>
#include <cmath>

using namespace std;

char matrix[100][100];
int R, C;

void changeMatrix(){
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			if(matrix[i][j]=='+')
				matrix[i][j]='(';
			else if(matrix[i][j]=='-')
				matrix[i][j]=')';
			else if(matrix[i][j]=='*')
				matrix[i][j]='F';
		}
	}	
}

void printMatrix(){
	printf("\n");
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}	
}

void blockRegion(int i, int j){
	if(i<0||j<0||i>=R||j>=C)
		return;

	if(matrix[i][j]=='.')
		return;

	if(matrix[i][j]=='B')
		return;
	
	matrix[i][j]='B';

	blockRegion(i, j-1);
	blockRegion(i, j+1);
	blockRegion(i-1, j);
	blockRegion(i-1, j+1);
	blockRegion(i+1, j-1);
	blockRegion(i+1, j);
}

void swapRegion(int i, int j){
	if(i<0||j<0||i>=R||j>=C)
		return;


	if(matrix[i][j]=='+'||matrix[i][j]=='I')
		matrix[i][j]='(';
	else if(matrix[i][j]=='-')
		matrix[i][j]=')';
	else
		return;

	swapRegion(i, j-1);
	swapRegion(i, j+1);
	swapRegion(i-1, j);
	swapRegion(i-1, j+1);
	swapRegion(i+1, j-1);
	swapRegion(i+1, j);
}

void checkRegion(int i, int j, int current){
	if(i<0||j<0||i>=R||j>=C)
		return;

	if(matrix[i][j]=='+'&&current!=1){
		blockRegion(i, j);
		return;
	}

	if(matrix[i][j]=='-'&&current!=-1){
		blockRegion(i, j);
		return;
	}

	if(matrix[i][j]=='+'||matrix[i][j]=='-'||matrix[i][j]=='.'||matrix[i][j]=='B'){
		return;
	}

	if (current==1){
		matrix[i][j] = '+';
	}

	if (current==-1){
		matrix[i][j] = '-';
	}

	checkRegion(i, j-1,		current*(-1));
	checkRegion(i, j+1,		current*(-1));
	checkRegion(i-1, j,		current*(-1));
	checkRegion(i-1, j+1,	current*(-1));
	checkRegion(i+1, j-1,	current*(-1));
	checkRegion(i+1, j,		current*(-1));
}

void swapI(){
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			if(matrix[i][j]=='I')
				matrix[i][j] = '(';
}

int main(){
	
	scanf("%d %d", &R, &C);

	while(R!=0&&C!=0){
		for (int i = 0; i < R; ++i){
			for (int j = 0; j < C; ++j){
				scanf(" %c", &matrix[i][j]);
			}
		}

		// swapI();
		
		for (int i = 0; i < R; ++i){
			for (int j = 0; j < C; ++j){
				if(matrix[i][j]=='I'){
					checkRegion(i, j, 1);					
					swapRegion(i, j);
				}
			}
		}

		changeMatrix();
		printMatrix();


		scanf("%d %d", &R, &C);
	}



	return 0;
}