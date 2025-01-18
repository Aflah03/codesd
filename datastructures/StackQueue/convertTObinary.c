#include<stdio.h>
#include<stdlib.h>

#define N 20

typedef struct {
    int A[N];
    int top;
}Stack;
Stack* S = NULL;
void PUSH(int c){
    S->top++;
    S->A[S->top] = c;
}
int POP(){
    if(S->top==-1) return -1;
    return S->A[S->top--];
}

int convertTOBinary(int num){

    while(num>0){
        PUSH(num%2);
        num/=2;

    }
    while(S->top!= -1){
        int x = POP();
        printf("%d " ,x);
    }
}
int main(){
    S = (Stack*)malloc(sizeof(Stack));
    S->top = -1;

    int num = 7;
    convertTOBinary(num);
}