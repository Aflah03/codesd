#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t rcsem;
sem_t csmutex;
int readers = 0;
void  *Reader(void *arg);
void *Writer(void* arg);
int main(){
    int i,readerCount, writerCount;
    sem_init(&csmutex, 0, 1);
    sem_init(&rcsem,0,1);

    pthread_t readerThread[10], writeThread[10];
    printf("\nEnter the number of readers: ");
    scanf("%d",&readerCount);

    printf("Enter the number of writers: ");
    scanf("%d",&writerCount);

    for(i=0;i<readerCount;i++){
        pthread_create(&readerThread[i], NULL, Reader, (void *)i);
    }
    for(i=0;i<readerCount;i++){
        pthread_create(&writeThread[i], NULL, Reader, (void *)i);
    }
    
    for(i=0;i<readerCount;i++){
        pthread_join(readerThread[i], NULL);
    }
    sem_destroy(&rcsem);
    sem_destroy(&csmutex);
}
void *Writer(void * arg){
    sleep(1);
    int temp = (int)arg;
    printf("\n Writer %d is trying to enter into database for modifying the data",temp);
    sem_wait(&csmutex);
    printf("Writer %d is writing into the database",temp);
    sem_post(&csmutex);
    printf("Writer %d is leaving the database",temp);
}


void* Reader(void* arg){
    sleep(1);
        int temp= (int)arg;
        printf("\n Reader %d is trying to enter into database for reading the data",temp);
        sem_wait(&rcsem);
        readers++;
        if(readers==1){
            sem_wait(&csmutex);
        }
        sem_post(&rcsem);
        printf("Reader %d is reading the database",temp);
        sem_wait(&rcsem);
        if(readers== 0){
            sem_post(&csmutex);
        }
        sem_post(&rcsem);
        printf("Reader %d is leaving the database", temp);
} 