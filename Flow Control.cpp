#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int reciever(int temp1){
	int i;
	for(i=1;i<100;i++)
	rand();
	i = rand()%temp1;
	return i;
}

int nack(int temp1){
	int i;
	for(i=1;i<100;i++)
	rand();
	i = rand()%temp1;
	return i;
}

int simulate(int winsize){
	int temp1,i;
	for(i=1;i<50;i++)
	temp1 = rand();
	if(temp1==0)
	temp1 = simulate(winsize);
	i = temp1%winsize;
	if(i==0)
	return winsize;
	else
	return temp1%winsize;
}



void SAW(){
	int i,j,frames,x,x1=10,x2;
	i = 1;
	j = 1;
	printf("\nEnter the number of frames:");
	scanf("%d",&frames);
	printf("\nNumber of frames is %d",frames);
	while(frames>0){
	printf("\nSending frames %d",i);
	srand(x1++);
	x = rand()%10;
	if(x%2==0){
	for(x2=1;x2<2;x2++){
	printf("\nWaiting for %d seconds\n",x2);
	sleep(x2);
	}
	printf("\nSending frame %d",i);
	srand(x1++);
	x = rand()%10;
	}
	printf("\nACK for frame %d",j);
	frames = frames - 1;
	i++;
	j++;
	}
	printf("\nEnd of stop and wait protocol");	
}

void SAR(){
	int temp1=0,temp2=0,temp3=0,temp4=0,temp5=0,i,winsize,frames,frames1,n;
	char c;
	int reciever(int);
	int simulate(int);
	int nack(int);
	printf("\nEnter the window size:");
	scanf("%d",&winsize);
	n = winsize;
	printf("\nEnter the number of frames:");
	scanf("%d",&frames);
	printf("\nNumber of frames is %d",frames);
	frames1 = frames;
	while(frames1>=0){
		temp1 = simulate(winsize);
		winsize = winsize - temp1;
		temp4 = temp4 + temp1;
		if(temp4>frames){
			temp4 = frames;
		}
		for(i=frames-frames1;i<=temp4;i++){
			printf("\nSending frame %d",i);
		}
		temp2 = reciever(temp1);
		temp3 = temp3 + temp2;
		if(temp3>frames){
			temp3 = frames;
		}
		temp2 = nack(temp1);
		temp5 = temp5 + temp2;
		if(temp5!=0){
			printf("\nNo acknowledgement for the frame %d",temp5);
			for(i=1;i<temp5;i++);
			printf("\nRetransmitting frame %d",temp5);
		}
		frames1 = frames1 - temp1;
		if(winsize<=0)
		winsize=n;
	}
	printf("\nEnd of selective repeat protocol");	
}

void GBN(){
	int temp1=0,temp2=0,temp3=0,temp4=0,i,winsize,frames,frames1;
	char c;
	int reciever1(int);
	int simulate1(int);
	printf("\nEnter the number of frames:");
	scanf("%d",&frames);
	printf("\nEnter the window size:");
	scanf("%d",&winsize);
	printf("\nNumber of frames is %d",frames);
	frames1 = frames;
	while(frames1>=0){
		temp1 = simulate(winsize);
		winsize = winsize-temp1;
		temp4 = temp4 + temp1;
		if(temp4>frames){
			temp4 = frames;
		}
		for(i=temp3+1;i<=temp4;i++){
			printf("\nSending frame %d",i);
		}
		temp2 = reciever(temp1);
		temp3 = temp3 + temp2;
		if(temp3>frames){
			temp3 = frames;
		}
		printf("\nAcknowledgement for the frames up to %d",temp3);
		frames1 = frames1 - temp2;
		temp4 = temp3;
		if(winsize<=0){
			winsize = 8;
		}
	}
	printf("\nEnd of Go back N protocol");
}

int main(){
	int ch;
	while(ch<=3){
		printf("\n\n1.Stop and Wait");
		printf("\n2.Selective repeat");
		printf("\n3.Go back N");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		if(ch==1){
			SAW();
		}
		else if(ch==2){
			SAR();
		}
		else if(ch==3){
			GBN();
		}
		else{
			printf("\nInvalid Input");
		}
	}
}
