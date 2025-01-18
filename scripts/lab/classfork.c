#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int i;
	//pid_t is a struture type
	pid_t childpid, childpid1, childpid2, childpid3; 
	printf("Parent ID before forking: %d\n", (int)getpid());
	childpid = fork();

	if(childpid < 0){
		printf("Error\n");
	}
	if(childpid!= 0){
		childpid1 = fork();
		sleep(30);
	}
	/*//inside child process for return value 0*/
	/*else if(childpid ==0){*/
	/*	printf("INSIDE CHILD\n");*/
	/*	printf("INSIDE CHILD: My procces ID is %d \n",getpid());*/
	/* 	printf("INSIDE CHILD: My parent process ID is %d\n", getppid());*/
	/*}*/
	/*//for returns PID of child process inside the parent process*/
	/*else{*/
	/*	printf("INSIDE PARENT\n");*/
	/*	printf("INSIDE PARENT: my process id is %d \n", getpid());*/
	/*	printf("INSIDE PARENT: my child process id is %d\n",childpid);*/
	/*}*/
}
