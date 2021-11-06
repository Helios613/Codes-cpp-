#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {3, 2, 0, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0; i<n; i++){
		arr[i] += (arr[arr[i]]%n) * n;
	}
	
	for(int i=0; i<n; i++){
		arr[i] = arr[i] / n;
	}
	
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}
