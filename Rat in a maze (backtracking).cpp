#include<bits/stdc++.h>
using namespace std;


int check(int **a, int i, int j, int n){
	if( i<n && j<n && a[i][j] == 0){
		return 1;
	}
	return 0;
}

bool solve(int **a, int i, int j, int n, int **sol){
	if(i == n-1 && j == n-1){
		sol[i][j] = 1;
		return true;
	}
	if(check(a, i, j, n)){
		sol[i][j] = 1;
		if(solve(a, i+1, j, n, sol)){
			return true;
		}
		if(solve(a, i, j+1, n, sol)){
			return true;
		}
		sol[i][j] = 0;
		false;
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	int **a = new int*[n];
	for(int i=0; i<n; i++){
		a[i] = new int[n];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	
	int **sol = new int*[n];
	for(int i=0; i<n; i++){
		sol[i] = new int[n];
		for(int j=0; j<n; j++){
			sol[i][j] = 0;
		}
	}
	
	if(solve(a, 0, 0, n, sol)){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}	
	}
	

	
}
