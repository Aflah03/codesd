#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main(){
    pid_t childpid1,childpid2;
    printf("Parent ID: %d",(int)getpid());

    childpid1  = fork();

    if(childpid1 <0){
        fprintf(stderr,"Error in creating a child process");
        exit(0);
    }
    else if(childpid1 ==0)
    {
        sleep(200);
    }
    if(childpid1 > 0){
        childpid2 = fork();
        sleep(20);
    }
}
