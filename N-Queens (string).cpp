#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &out, int x, int y, int n){
	for(int i=0; i<x; i++){
		if(out[i][y] == 'Q'){
			return false;
		}
	}
	int row = x;
	int col = y;
	while(row>=0 && y>=0){
		if(out[row][col] == 'Q'){
			return false;
		}
		row--;
		col--;
	}
	
	row = x;
	col = y;
	
	while(row>=0 && col<n){
		if(out[row][col] == 'Q'){
			return false;
		}
		row--;
		col++;
	}
	return true;
}

bool nQueens(vector<vector<string> >& board, vector<string> &temp, int x, int n){
	if(x>=n){
		board.push_back(temp);
		return true;
	}
	for(int i=0; i<n; i++){
		if(isSafe(temp, x, i, n)){
			temp[x][i] = 'Q';
			nQueens(board, temp, x+1, n);
			temp[x][i] = '.';
		}
	}
	return false;
}

int main(){
	int A = 4;
	vector<vector<string> > board;
	string s(A, '.');
	
	vector<string> temp(A, s);
	
	nQueens(board, temp, 0, A);
	
	for(int i=0; i<A; i++){
		for(int j=0; j<A; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
