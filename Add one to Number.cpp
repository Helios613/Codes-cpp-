#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void plusOne(vector<int> &a){
	int carry=0, n, temp=0;
	
	n = a.size();
	
	vector<int> b;
	
	for(int i=n-1; i>=0; i--){
		if(carry==1){
			temp = a[i] + carry;
			if(temp>9){
				b.push_back(0);
				carry = 1;
			}
			else{
				b.push_back(temp);
				carry = 0;
			}
		}
		else if(a[i] == 9){
			b.push_back(0);
			carry = 1;
		}
		else if(i==n-1){
			temp = a[i] + 1;
			b.push_back(temp);
		}
		else{
			b.push_back(a[i]);
		}
	}
	
	if(carry==1){
		b.push_back(1);
	}
	
	reverse(b.begin(), b.end());
	cout<<endl;
	for(int i=0; i<b.size(); i++){
		cout<<b[i]<<" ";
	}
}


int main(){
	vector<int> a;
	
	vector<int> b;
	
	int n, x;
	
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>x;
		a.push_back(x);
	}	
	
	plusOne(a);
	
}
