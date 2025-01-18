#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct {
  int A[N];
  int top;
} Stack;
void PUSHnormal(Stack *S, int c) {
  S->top++;
  S->A[S->top] = c;
}
int POPnormal(Stack *S) {
  if (S->top == -1)
    return -1;
  return S->A[S->top--];
}

void ENQUEUE(Stack *S1, int num) { PUSHnormal(S1, num); }
int DEQUEUE(Stack *S1, Stack *S2) {
  while (S1->top != -1) {
    int x = POPnormal(S1);
    PUSHnormal(S2, x);
  }
  int dequeued = POPnormal(S2);
    while(S2->top != -1){
        int x= POPnormal(S2);
        PUSHnormal(S1,x);
    }
   return dequeued;
}
int main() {
  Stack *S1 = (Stack *)malloc(sizeof(Stack));
  Stack *S2 = (Stack *)malloc(sizeof(Stack));
  S1->top =-1;
  S2->top = -1;


  int x = DEQUEUE(S1,S2);
  x = DEQUEUE(S1,S2);
  ENQUEUE(S1,11);
  ENQUEUE(S1,1);
  ENQUEUE(S1,2);
  ENQUEUE(S1,3);
  x = DEQUEUE(S1,S2);
  x = DEQUEUE(S1,S2);
  x = DEQUEUE(S1,S2);
 
  printf("you just dequeued %d",x);
  
}
