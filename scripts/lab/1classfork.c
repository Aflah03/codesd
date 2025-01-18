#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	pid_t PID = fork();

	if(PID < 0){
		// eroor in forking
		 fprintf(stderr, "Error in forking\n");
		exit(1);
	}
	else if(PID==0){
		//Inside child process, fork return 0;
		printf("INSIDE CHILD: My process Id is : %d\n", getpid());
		sleep(20);
		printf("INSIDE CHILD: My Parent process Id is : %d\n", getppid());

	}
	else{

		printf("INSIDE PARENT: My process Id is %d \n",getpid());
		printf("INSIDE PARENT: My child process Id is %d\n", (int)PID);

	}

	return 0;
	
}
