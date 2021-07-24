#include<iostream>
#include<vector>

using namespace std;

int maxSum(vector<int> &A){
	int n = A.size();
	int curr_sum = 0, max_sum = -1000;
	for(int i=0; i<n; i++){
		curr_sum = curr_sum + A[i];
		max_sum = max(curr_sum, max_sum);
		if(curr_sum<0){
			curr_sum = 0;
		}
	}
	
	return max_sum;
}


int main(){
	int n, x;
	vector<int> a;
	
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>x;
		a.push_back(x);
	}
	
	cout<<maxSum(a)<<endl;
}
