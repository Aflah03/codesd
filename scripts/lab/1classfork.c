#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	pid_t PID = fork();

	int x = 100;
	if(PID < 0){
		// eroor in forking
		 fprintf(stderr, "Error in forking\n");
		exit(1);
	}
	else if(PID==0){
		//Inside child process, fork return 0;
		x= 108;
		printf("INSIDE CHILD: x is : %d\n", x);
		/*printf("INSIDE CHILD: My process Id is : %d\n", getpid());*/
		/*printf("INSIDE CHILD: My Parent process Id is : %d\n", getppid());*/

	}
	else{

		printf("INSIDE PARENT: x is %d \n",x);
		/*printf("INSIDE PARENT: My process Id is %d \n",getpid());*/
		/*printf("INSIDE PARENT: My child process Id is %d\n", (int)PID);*/

	}

	return 0;
	
}
