#include <stdio.h>
#include <stdlib.h>
#define N 20

typedef struct {
    int A[N];
    int front, rear;
} Queue;

int ENQUEUEnormal(Queue* q, int num) {
    if ((q->rear + 1) % N == q->front) {
        return -1;  // queue is full
    } else if (q->front == -1) {
        q->front++;
        q->rear++;
        q->A[q->rear] = num;
    } else {
        q->rear = (q->rear + 1) % N;
        q->A[q->rear] = num;
    }
    return 1;
}

int DEQUEUEnormal(Queue* q) {
    if (q->front == -1) return -1; // queue is empty
    else if (q->front == q->rear) {
        int item = q->A[q->front];
        q->front = -1;
        q->rear = -1;
        return item;
    } else {
        int item = q->A[q->front];
        q->front = (q->front + 1) % N;
        return item;
    }
}

void PUSH(Queue** Q1, Queue** Q2, int data) {
    ENQUEUEnormal(*Q2, data);
    while ((*Q1)->front != -1) {
        int x = DEQUEUEnormal(*Q1);
        ENQUEUEnormal(*Q2, x);
    }
    // Swap pointers
    Queue* temp = *Q1;
    *Q1 = *Q2;
    *Q2 = temp;
}

int POP(Queue* Q1) {
    return DEQUEUEnormal(Q1);
}

void PrintSTACK(Queue* Q1) {
    int temp = Q1->front;
    while (temp != (Q1->rear + 1) % N) {
        printf("%d ", Q1->A[temp]);
        temp = (temp + 1) % N;
    }
    printf("\n");
}

int main() {
    Queue* Q1 = (Queue*)malloc(sizeof(Queue));
    Q1->front = -1;
    Q1->rear = -1;
    Queue* Q2 = (Queue*)malloc(sizeof(Queue));
    Q2->front = -1;
    Q2->rear = -1;

    PUSH(&Q1, &Q2, 5);
    PUSH(&Q1, &Q2, 10);
    PUSH(&Q1, &Q2, 15);

    PrintSTACK(Q1);

    printf("Popped: %d\n", POP(Q1));
    PrintSTACK(Q1);

    free(Q1);
    free(Q2);
    return 0;
}
