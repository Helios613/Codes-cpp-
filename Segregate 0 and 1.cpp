#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[] = {0, 1, 0, 1, 1, 1};
	int n = sizeof(a)/sizeof(a[0]);
	
	int left = 0, right = n - 1;
	
	while(left < right){
		while(a[left] == 0 && left<right){
			left++;
		}
		
		while(a[right] == 1 && left<right){
			right--;
		}
		
		if(left<right){
			a[left] = 0;
			a[right] = 1;
			left++;
			right--;
		}
	}
	
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}
