#include <stdio.h>
#include <stdlib.h>
int n = 3;
typedef struct xx {
  int token;
  int nooftokens;
} customer;
typedef struct q {
  int rear;
  int front;
  int size;
  customer c[3];
} queue;
queue q;
void enqueue(queue *q, customer a) {
  if (q->rear == n)
    return;
  if (q->front == -1) {
    q->rear = 0;
    q->front = 0;
    q->c[q->rear] = a;
    q->rear = (q->rear + 1) % n;
    q->size++;
  } else {
    q->c[q->rear] = a;
    q->rear = (q->rear + 1) % n;
    q->size++;
    return;
  }
}
customer dequeue(queue *q) {
  if (q->size == 0) {
    printf("there is no one left to serve");
    customer c;
    c.nooftokens = -1;
    c.token = -1;
    return c;
  } else {
    customer c = q->c[q->front];
    q->front = (q->front + 1) % n;
    q->size--;
    return c;
  }
}
void cuurentserving(queue *q) { printf("%d", q->c[q->front].token); }
int main() {
  q.rear = -1;
  q.front = -1;
  q.size = 0;
  int choice;
  int i = 0;
  customer m[3];
  int v;
  while (1) {
    printf("enter the choice\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("enter the number of the token for the customer\n");
      scanf("%d", &v);
      ++i;
      m[i].token = i;
      m[i].nooftokens = v;
      enqueue(&q, m[i]);
      break;
    case 2: {
      customer u = dequeue(&q);
      printf("the customer with num%dhas been served\n", u.token);
      if (u.nooftokens > 1) {
        u.nooftokens--;
        enqueue(&q, u);
      }
      break;
    }
    case 3:
      printf("the size of the queue is %d", q.size);
      break;
    case 4:
      for (int i = 0; i < n; i++) {
        printf("token no:%d and number of token is%d\n", q.c[i].token,
               q.c[i].nooftokens);
      }
      break;
    case 5:
      return 0;
    }
  }

  return 6;
}
