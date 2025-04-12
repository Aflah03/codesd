#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SHM_SIZE 1024
#define SHM_KEY 1234

int main(){
    int shmid;
    char * data;

    if((shmid = shmget(SHM_KEY, SHM_SIZE, 0644))==-1){
        perror("shmget");
        exit(1);

    }

    data = (char*)shmat(shmid,(void*) 0,0);
    if(data ==(char*)(-1)){
        perror("Shmat");
        exit(1);
    }

    while(1){

        if(strlen(data)>0){
            printf("Data read from shared memory: %s\n", data);


            if(strcmp(data, "exit") ==0){
                break;
            }
            memset(data, 0, SHM_SIZE);
        }

    }
    if(shmdt(data) ==-1){
        perror("shmdt");
        exit(1);
    }

    if(shmctl(shmid, IPC_RMID, NULL)==-1){
        perror("shmctl");
        exit(1);
    }
    return 0;
}
