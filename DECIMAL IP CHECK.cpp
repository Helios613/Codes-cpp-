#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int flag, x, y, z, w;

void check_IP(int a, int b, int c, int d){
	if(a>=0 && a<=255){
		if(b>=0 && b<=255){
			if(c>=0 && c<=255){
				if(d>=0 && d<=255){
					flag = 1;
				}
			}
		}
	}
	else{
		flag = 0;
	}
}

int main(){
	// DECIMAL
	
	printf("Enter the first octet:");
	scanf("%d",&x);
	
	printf("\nEnter the second octet:");
	scanf("%d",&y);
	
	printf("\nEnter the third octet:");
	scanf("%d",&z);
	
	printf("\nEnter the fourth octet:");
	scanf("%d",&w);
	
	check_IP(x, y, z, w);
	
	if(flag==1){
		printf("\nValid IP Address");
	}
	else{
		printf("\nInvalid IP Address");
	}

	return 0;
}
