#include<bits/stdc++.h>
using namespace std;

int main(){
	int freq[26] = {0};
	string A = "bbbbbaaa";
	for(int i=0; i<A.length(); i++){
		freq[A[i] - 'a']++;
	}
	
	int maxCount = INT_MIN;
	char ch;
	
	for(int i=0; i<26; i++){
		if(maxCount < freq[i]){
			ch = 'a' + i;
			maxCount = freq[i];
		}
	}
	
	if(maxCount > (A.size() + 1)/2){
		cout<<"No Solution";
	}
	else{
		string ans(A.size(), ' ');
		int index = 0;
		while(maxCount > 0){
			ans[index] = ch;
			index = index + 2;
			maxCount--;
		}
		
		freq[ch - 'a'] = 0;
		
		for(int i=0; i<26; i++){
			while(freq[i]>0){
				if(index >= A.size()){
					index = 1;
				}
				ch = 'a' + i;
				ans[index] = ch;
				index = index + 2;
				freq[i]--;
			}
		}
		cout<<ans;
	}
	
	
}
