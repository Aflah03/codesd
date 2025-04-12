#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t rcsem;
sem_t csmutex;
int readers = 0;
void *Reader(void *arg);
void *Writer(void *arg);
int main() {
  int i, readerCount, writerCount;
  sem_init(&csmutex, 0, 1);
  sem_init(&rcsem, 0, 1);
  pthread_t readerThread[10], writerThread[10];
  printf("\nEnter number of readers");
  scanf("%d", &readerCount);
  printf("\nEnter number of writers");
  scanf("%d", &writerCount);
  for (i = 0; i < readerCount; i++) {
    pthread_create(&readerThread[i], NULL, Reader, (void *)i);
  }
  for (i = 0; i < writerCount; i++) {
    pthread_create(&writerThread[i], NULL, Writer, (void *)i);
  }
  for (i = 0; i < writerCount; i++) {
    pthread_join(writerThread[i], NULL);
  }
  for (i = 0; i < readerCount; i++) {
    pthread_join(readerThread[i], NULL);
  }
  sem_destroy(&rcsem);
  sem_destroy(&csmutex);
}
void *Writer(void *arg) {
  sleep(1);
  int temp = (int)arg;
  printf("\nWriter %d is trying to enter into database for modifying the data",
         temp);
  sem_wait(&csmutex);
  printf("\nWriter %d is writing into the database", temp);
  sem_post(&csmutex);
  printf("\nWriter %d is leaving the database", temp);
}
void *Reader(void *arg) {
  sleep(1);
  int temp = (int)arg;
  printf(
      "\nReader %d is trying to enter into the Database for reading the data",
      temp);
  sem_wait(&rcsem);
  readers++;
  if (readers == 1)
    sem_wait(&csmutex);
  sem_post(&rcsem);
  printf("\nReader %d is reading the database", temp);
  sem_wait(&rcsem);
  readers--;
  if (readers == 0)
    sem_post(&csmutex);
  sem_post(&rcsem);
  printf("\nReader %d is leaving the database", temp);
}
