#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int> >& a, int x, int y, int n){
	for(int i=0; i<x; i++){
		if(a[i][y] == 1){
			return false;
		}
	}
	
	int row = x;
	int col = y;
	
	while(row>=0 && col>=0){
		if(a[row][col] == 1){
			return false;
		}
		row--;
		col--;
	}
	
	row = x;
	col = y;
	
	while(row>=0 && col<n){
		if(a[row][col] == 1){
			return false;
		}
		row--;
		col++;
	}
	return true;
}

bool nQueens(vector<vector<int> >&a, int x, int n){
	if(x>=n){
		return true;
	}
	
	for(int col = 0; col<n; col++){
		if(isSafe(a, x, col, n)){
			a[x][col] = 1;
			
			if(nQueens(a, x+1, n)){
				return true;
			}
			
			a[x][col] = 0;
		}
		
	}
	return false;
}

int main(){
	int n = 4;
	vector<vector<int> > a(n, vector<int>(n, 0));
	
	nQueens(a, 0, n);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
