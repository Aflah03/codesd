#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024
#define SHM_KEY 1234

int main(){
    int shmid;
    char *data;

    // Create the shared memory segment
    //

    if( (shmid = shmget(SHM_KEY, SHM_SIZE, 0644 | IPC_CREAT)) ==-1)
    {
        perror("shmget error");
        exit(1);
    }


    ///atach to the shared memory segment
     
    data = (char*) shmat(shmid, (void*)0,0);
    if(data== (char*)(-1)){
        perror("shmat");
        exit(1);
    }

        printf("Enter data to write to shared memory: ");
    while(1)
    {
        printf("Message: ");
        fgets(data,SHM_SIZE, stdin);

        data[strcspn(data,"\n")] = '\0';

        if(strcmp(data, "exit") ==0){
            break;
        }
    }

    if(shmdt(data)==-1){
        perror("shmdt");
        exit(1);
    }
    return 0;
}
