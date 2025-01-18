#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

typedef struct Node{
  char data;
  struct Node* left;
  struct Node* right;
}Node;

typedef struct OperatorStack{
  char* A[N];
  int top;
}OperatorStack;

typedef struct NodeStack{
  Node* A[N];
  int top;
}NodeStack;


int PUSH_TO_STACK(OperatorStack* S, char* item) {
    if (S->top == N - 1) {
        return -1; // stack is full
    } else {
        S->top++;
        S->A[S->top] = strdup(item);
        return 1;
    }
}

char* POP_FROM_STACK(OperatorStack* S) {
    if (S->top == -1)
        return NULL;
    else {
        char* item = strdup(S->A[S->top]);
        S->top--;
        return item;
    }
}

int PUSH_NODE_STACK(NodeStack* S, Node* item) {
    if (S->top == N - 1) {
        return -1; // stack is full
    } else {
        S->top++;
        S->A[S->top] = item;
        return 1;
    }
}

Node* POP_NODE_STACK(NodeStack* S) {
    if (S->top == -1)
        return NULL;
    else {
        Node* item = S->A[S->top];
        S->top--;
        return item;
    }
}

