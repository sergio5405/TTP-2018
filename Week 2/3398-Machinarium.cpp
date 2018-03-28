#include <stdio.h>
#include <algorithm>
#include <cmath>

int N;

char board[8][8];

bool checkRecursion(int i, int j, int dx, int dy){
	while(i<N&&j<N&&i>=0&&j>=0&&board[i][j]=='x'){
		board[i][j]='o';
		i+=dx;
		j+=dy;
	}

	i-=dx;
	j-=dy;

	if(!(dx==1&&dy==0)) //not going right
		checkRecursion(i, j, 1, 0); // go right

	if(!(dx==0&&dy==1)) //not going down
		checkRecursion(i, j, 0, 1); // go down

	if(!(dx==-1&&dy==0)) //not going left
		checkRecursion(i, j, -1, 0); // go left

	if(!(dx==0&&dy==-1)) //not going up
		checkRecursion(i, j, 0, -1); // go up

	board[i][j]='x';
	checkRecursion(i+dx, j+dy, dx, dy)
}

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; ++i){
		scanf("%s", board[i]);
	}

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (board[i][j] == 'x'){
				checkRecursion(i, j, dx, dy);
			}
		}
	}

	return 0;
}