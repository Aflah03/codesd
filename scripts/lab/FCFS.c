#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int PID;
	int AT;
	int BT;
	int priority;
	int WT;
	int TAT;
	int CT;
	int remaingBT; //Remaining burst time for SRTF and RR
}Process;

void calculateTimes(Process p[],int n){
	for(int i=0;i<n;i++){
		p[i].TAT = p[i].CT- p[i].AT;
		p[i].WT = p[i].TAT - p[i].BT;
	}
}

float calculate_AvgWaitingTime(Process p[],int n){
	float totalWt = 0;
	for(int i=0;i<n;i++){
		p[i].WT+=totalWt;
	}
	return totalWt/n;
}

void FCFS(Process p[],int n){


	// Sorting based on time of arrival for FCFS
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(p[j].AT > p[j+1].AT){
				Process temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}		
	}

	int currentTime = 0;
	for(int i=0;i<n;i++){
		if( currentTime <p[i].AT ){
			currentTime =  p[i].AT;
		}
		currentTime+= p[i].BT;
		p[i].CT = currentTime;
	}


}
int main(){

	Process p[10];
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	gets();
	for(int i=0;i<n;i++){

		printf("PROCESS %d:\nEnter 1- PID, 2- AT, 3- BT,4-prio\n", i+1);
		scanf("%d %d %d %d", &p[i].PID, &p[i].AT, &p[i].BT,&p[i].priority);
		gets();
	}



	Process psorted[10];


	for(int i=0;i<n;i++){
		printf("PID: %d , AT: %d, BT: %d, prio: %d\n",p[i].PID, p[i].AT,p[i].BT,p[i].priority); 
	}
}
