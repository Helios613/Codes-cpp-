#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int x, int y) {
  static int carry = 0;
  if (x == 1 && y == 1 && carry == 0) {
    carry = 1;
    return 0;
  } else if (x == 1 && y == 1 && carry == 1) {
    carry = 1;
    return 1;
  } else if (x == 1 && y == 0 && carry == 0) {
    carry = 0;
    return 1;
  } else if (x == 1 && y == 0 && carry == 1) {
    carry = 1;
    return 0;
  } else if (x == 0 && y == 1 && carry == 0) {
    carry = 0;
    return 1;
  } else if (x == 0 && y == 1 && carry == 1) {
    carry = 1;
    return 0;
  } else if (x == 0 && y == 0 && carry == 0) {
    carry = 0;
    return 0;
  } else {
    carry = 0;
    return 1;
  }
}
int com(int a) {
  if (a == 0)
    return 1;
  else
    return 0;
}

int getParity(int n){
	int parity = 0;
	while(n){
		parity = !parity;
		n = n & (n-1);
	}
	return parity;
}
long convert(int n){
	long bin;
	int rem, i = 1, step = 1;
	while(n!=0){
		rem = n % 2;
		n = n / 2;
		bin = bin + rem*i;
		i = i * 10;
	}
	return bin;
}
long concat(long a, int b) { 
    char s1[20]; 
    char s2[20]; 
    sprintf(s1, "%d", a); 
    sprintf(s2, "%d", b); 
    strcat(s1, s2); 
   	long c = atoi(s1); 
    return c; 
} 

void LRC(){
	int n,m,ct;
	//SENDER'S MESSAGE
	printf("Sender's Message\n");
	printf("Enter the number of messages to be sent:");   
	scanf("%d",&n); 
	printf("\nEnter the size of binary string(in bits):");
	scanf("%d",&m);
	int a[n+1][m+1];
	printf("\nEnter the messages to be sent\n");        
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<n;i++){
		ct = 0;
		for(int j=0;j<m;j++){
			if(a[i][j]==1){
				ct++;
			}
			if(ct%2==0){
				a[i][m] = 0;
			}
			if(ct%2!=0){
				a[i][m] = 1;
			}
		}
	}	
	for(int j=0;j<m+1;j++){
		ct = 0;
		for(int i=0;i<n;i++){
			if(a[i][j]==1){
				ct++;
			}
			if(ct%2==0){
				a[n][j] = 0;
			}
			if(ct%2!=0){
				a[n][j] = 1;
			}	
		}
	}	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			printf("%d",a[i][j]);
		}
		printf("\n");
	}	
	printf("\nMessage Sent Successfully.\n");
	int b[n+1][m+1];
	//RECIEVER'S MESSAGE
	printf("Reciever's Message\n");
	printf("Enter the recieved message\n");            
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			scanf("%d",&b[i][j]);
		}
		printf("\n");
	}
	int flag;
	for(int i=0;i<n+1;i++){
		ct = 0;
		flag = 0;
		for(int j=0;j<m+1;j++){
			if(b[i][j]==1){
				ct++;
			}
		}
		if(ct%2!=0){
			flag = 1;
			break;
		}
	}
	if(flag!=1){
		for(int j=0;j<m+1;j++){
			ct=0;
			for(int i=0;i<n+1;i++){
				if(b[i][j]==1){
					ct++;
				}
			}
			if(ct%2!=0){
				flag = 1;
				break;
			}
		}
	}
	if(flag==1){
		printf("\nRecieved Message is Incorrect");
	}
	else{
		printf("\nRecieved Message is Correct");
	}
}

void VRC(){
	int n, parity, ct=0;
	long num, bin_num;
	char snum[20], rmsg[20];
	
	// SENDER'S MESSAGE
	printf("Enter the sender's message:");
	scanf("%d",&n);
	num = convert(n);
	parity = getParity(n);
	bin_num = concat(num, parity);
	itoa(bin_num, snum, 10);
	printf("\nSender's Message:");
	puts(snum);
	
	// RECIEVER'S MESSAGE
	printf("\nEnter Recieved message:");
	scanf("%s",&rmsg);                          // BINARY FORM
	int len = strlen(rmsg);
	for(int i=0;i<len;i++){
		if(rmsg[i]=='1'){
			ct++;
		}
	}
	if(ct%2==0){
		printf("\nThe message recieved is correct.");
	}
	else{
		printf("\nThe message recieved is incorrect.");
	}	
}

void Checksum(){
  int i, j, dl, dil;
  int d1[25], d2[25], newd[55], comp[50], checksum[50];
  printf("\nEnter the data length :"); //First 8bits
  scanf("%d", & dl);
  printf("\nEnter the data1 : \n"); //Second 8bits
  for (i = 0; i < dl; i++)
    scanf("%d", & d1[i]);
  printf("\nEnter the d2 : \n");
  for (i = 0; i < dl; i++)
    scanf("%d", & d2[i]);
  for (i = dl - 1; i >= 0; i--) {
    newd[i] = add(d1[i], d2[i]);
  }
  printf("\n\nData 1 : ");
  for (i = 0; i < dl; i++)
    printf("%d", d1[i]);
  printf("\nData 2 : ");
  for (i = 0; i < dl; i++)
    printf("%d", d2[i]);
  printf("\n\nThe new data is : ");
  for (i = 0; i < dl; i++) {
    printf("%d", newd[i]);
  }
  printf("\nChecksum : ");
  for (i = 0; i < dl; i++) {
    checksum[i] = com(newd[i]);
    printf("%d", checksum[i]);
  }
  printf("\n\nReceiver Side : \n");
  printf("\nData : ");
  for (i = 0; i < dl; i++)
    printf("%d", d1[i]);
  printf(" ");
  for (i = 0; i < dl; i++)
    printf("%d", d2[i]);
  printf(" ");
  for (i = 0; i < dl; i++)
    printf("%d", checksum[i]);
  printf("\nAddition : ");
  for (i = dl - 1; i >= 0; i--) {
    newd[i] = add(newd[i], checksum[i]);
  }
  for (i = 0; i < dl; i++) {
    printf("%d", newd[i]);
  }
  printf("\nCompliment : ");
  for (i = 0; i < dl; i++) {
    comp[i] = com(newd[i]);
    printf("%d", comp[i]);
  }
}

void CRC(){
	int n[20], div[20], temp, f[20], quotient[20], len1, len2, divd[20],crc[20],flag=0;	
	printf("Sender's Message\n");
	printf("\nEnter the bits in the message:");
	scanf("%d",&len1);
	printf("\nEnter the message\n");
	for(int i=0;i<len1;i++){
		scanf("%d",&divd[i]);
	}
	for(int i=0;i<len1;i++){
		n[i] = divd[i];
	}
	printf("\nEnter the bits in divisor:");
	scanf("%d",&len2);
	printf("\nEnter the divisor\n");
	for(int i=0;i<len2;i++){
		scanf("%d",&div[i]);
	}	
	for(int i=len1;i<len1+len2;i++){
		n[i] = 0;
	}	
	for(int i=0;i<len1;i++){
		temp = i;
		if(n[i]==1){
			for(int j=0;j<len2;j++){
				if(n[temp]==div[j]){
					n[temp] = 0;
					f[j] = 0;
				}
				else{
					n[temp] = 1;
					f[j] = 1;
				}
				temp = temp + 1;
			}
			quotient[i] = 1;
		}
		else{
			quotient[i]=0;
		}
	}
	printf("\nRemainder is \n");
	for(int j=0;j<len2;j++){
		printf("%d",f[j]);
		divd[len1+j] = f[j];
	}
	printf("\n");
	printf("\nCRC\n");
	for(int i=0;i<len1+len2;i++){
		printf("%d",divd[i]);
	}	
	int length = len1 + len2;	
	printf("\nReciever's Message\n");
	printf("\nEnter the CRC\n");
	for(int i=0;i<length;i++){
		scanf("%d",&crc[i]);
	}
	for(int i=0;i<length;i++){
		temp = i;
		if(crc[i]==1){
			for(int j=0;j<len2;j++){
				if(crc[temp]==div[j]){
					crc[temp] = 0;
					f[j] = 0;
				}
				else{
					crc[temp] = 1;
					f[j] = 1;
				}
				temp = temp + 1;
			}
			quotient[i] = 1;
		}
		else{
			quotient[i]=0;
		}
	}	
	for(int i=0;i<len2;i++){
		if(f[i]!=0){
			flag = 1;
			break;
		}
	}	
	if(flag==1){
		printf("\nIncorrect Message");
	}
	else{
		printf("\nCorrect Message");
	}
}

void HamCode(){
	int data[10];
    int dataatrec[10],c,c1,c2,c3,i;
    printf("Enter 4 bits of data one by one\n");
    scanf("%d",&data[0]);
    scanf("%d",&data[1]);
    scanf("%d",&data[2]);
    scanf("%d",&data[4]);
 
    //Calculation of even parity
    data[6]=data[0]^data[2]^data[4];
	data[5]=data[0]^data[1]^data[4];
	data[3]=data[0]^data[1]^data[2];
 
	printf("\nEncoded data is\n");
	for(i=0;i<7;i++)
        printf("%d",data[i]);
 
    printf("\n\nEnter received data bits one by one\n");
    for(i=0;i<7;i++)
        scanf("%d",&dataatrec[i]);
 
    c1=dataatrec[6]^dataatrec[4]^dataatrec[2]^dataatrec[0];
	c2=dataatrec[5]^dataatrec[4]^dataatrec[1]^dataatrec[0];
	c3=dataatrec[3]^dataatrec[2]^dataatrec[1]^dataatrec[0];
	c=c3*4+c2*2+c1 ;
 
    if(c==0) {
		printf("\nNo error while transmission of data\n");
    }
	else {
		printf("\nError on position %d",c);
    	
		printf("\nData sent : ");
        for(i=0;i<7;i++)
        	printf("%d",data[i]);
        
		printf("\nData received : ");
        for(i=0;i<7;i++)
        	printf("%d",dataatrec[i]);
		
		printf("\nCorrect message is\n");
 
		//if errorneous bit is 0 we complement it else vice versa
		if(dataatrec[7-c]==0)
			dataatrec[7-c]=1;
        else
			dataatrec[7-c]=0;
		
		for (i=0;i<7;i++) {
			printf("%d",dataatrec[i]);
		}
	}
}

int main(){
	int ch;
	while(ch<=5){
		printf("\n\n1.VRC");
		printf("\n2.LRC");
		printf("\n3.Checksum");
		printf("\n4.CRC");
		printf("\n5.Hamming Code");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		if(ch==1){
			VRC();
		}
		else if(ch==2){
			LRC();
		}
		else if(ch==3){
			Checksum();
		}
		else if(ch==4){
			CRC();
		}
		else if(ch==5){
			HamCode();
		}
		else{
			printf("\nInvalid Input");
		}
	}
}

