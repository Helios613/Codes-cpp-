#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int flag, x, y, z, w;
char *s1, *s2, *s3, *s4;

void Dcheck_class(int n){
	if(n>=1 && n<127){
		printf("\nCLASS A");
		flag = 1;
	}
	else if(n>=128 && n<192){
		printf("\nCLASS B");
		flag = 2;
	}
	else if(n>=192 && n<224){
		printf("\nCLASS C");
		flag = 3;
	}
	else if(n>=224 && n<240){
		printf("\nCLASS D");
		flag = 4;
	}
	else if(n>=240 && n<256){
		printf("\nCLASS E");
		flag = 5;
	}
	else{
		printf("\nInvalid first octet");
	}
}

char *decimal_to_binary(int n)
{
  int c, d, t;
  char *p;

  t = 0;
  p = (char*)malloc(8+1);

  if (p == NULL)
    exit(EXIT_FAILURE);

  for (c = 7 ; c >= 0 ; c--)
  {
    d = n >> c;

    if (d & 1)
      *(p+t) = 1 + '0';
    else
      *(p+t) = 0 + '0';

    t++;
  }
  *(p+t) = '\0';

  return  p;
}

void Dcheck_NID(char *a, char *b, char *c, char *d){
	if(flag==1){
		printf("\nNetwork ID: %s",a); // for class A first 8 bits is network ID
	}
	
	else if(flag==2){
		printf("\nNetwork ID: %s%s",a,b); // for class B first 16 bits is network ID
	}
	
	else if(flag==3){
		printf("\nNetwork ID: %s%s%s",a,b,c); // for class C first 24 bits is network ID.
	}
	
	else if(flag==4){
		printf("\nClass D is not divided into Network ID");
	}
	else{
		printf("\nClass E is not divided into Network ID");
	}
}

void Dcheck_HID(char *a, char *b, char *c, char *d){
	if(flag==1){
		printf("\nHost ID: %s%s%s",b,c,d);
	}
	else if(flag==2){
		printf("\nHost ID: %s%s",c,d);
	}
	else if(flag==3){
		printf("\nHost ID: %s",d);
	}
	else if(flag==4){
		printf("\nClass D is not divided into Host ID");
	}
	else{
		printf("\nClass E is not divided into Host ID");
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
	
	s1 = decimal_to_binary(x);
	s2 = decimal_to_binary(y);
	s3 = decimal_to_binary(z);
	s4 = decimal_to_binary(w);
	
	Dcheck_class(x);
	
	Dcheck_NID(s1, s2, s3, s4);
	
	Dcheck_HID(s1, s2, s3, s4);
	return 0;
}
