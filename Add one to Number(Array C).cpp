#include<stdio.h>
#include<stdlib.h>

int main(){	
	
	int n = 7, carry = 0, temp = 0;
	int a[n+1];
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i=n-1; i>=0; i--){
		if(carry==1){
			a[i] = a[i] + carry;
			if(a[i]>9){
				a[i] = 0;
				carry = 1;
			}
			else{
				carry = 0;
				break;
			}
		}
		else if(a[i]==9){
			a[i] = 0;
			carry = 1;
		} 
		else{
			a[i] = a[i] + 1;
			break;
		}
		
	}
	
	/*
	if(carry == 1){
		for(int i=0; i<n-1; i++){
			temp = a[i+1];
			a[i+1] = a[i];
			a[i] = temp;
		}
		a[0] = 1;
		n = n + 1;
		
	}
	*/
	
	if(carry==1){
		for(int i=n; i>0; i--){
			a[i] = a[i-1];
		}
		a[0] = 1;
		n = n + 1;
	}
	
	
	printf("\n");
	for(int i=0 ;i<n; i++){
		printf("%d ", a[i]);
	}
	
}
