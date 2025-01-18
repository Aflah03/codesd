/*
To check if a string is a palindrome using a stack or queue, you can follow these methods:
Using a Stack (LIFO - Last In, First Out)

    Push all characters of the string onto the stack: Since a stack operates in a LIFO manner, the characters will be reversed when we pop them.
    Compare with the original string: Pop characters from the stack and check if they match the original string in order.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
typedef struct{
    char* A[N];
    int top;
}Stack;

int PUSH(Stack* S,char* word){
    if(S->top==N-1) return -1;
    else {
        S->top++;
        S->A[S->top] = strdup(word);
    }
    return 1;
}

char* POP(Stack* S){
    if(S->top==-1) return NULL;
    else{
        char * temp = strdup(S->A[S->top]);
        S->top--;
        return temp;
    }
}
void PrintStack(Stack* S){
    int temp = S->top;
    while(temp != -1){
        printf("%s\n",S->A[temp]);
        temp--;
    }
}
int main(){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->top =-1;
    // printf("enter the nubmer of words");
    // int n;
    // scanf("%d",&n);
    // getchar();

    // char arr[100];
    // for(int i=0;i<n;i++){
    //     fgets(arr,100,stdin);
    //     arr[strcspn(arr,"\n")] = '\0';
    //     PUSH(S,arr);
    // }
    // printf("The stack is: \n");
    // PrintStack(S);
    // char *arr1;
    //  arr1= strdup(POP(S));

    // printf("the popped value is : %s",arr1);
    char* word;
    word=strdup("malayalam");
    char* temp = word;
    while(*temp!='\0'){
        PUSH(S,temp);
        temp++;
    }
    // PUSH(S,"M");
    // PUSH(S,"A");
    // PUSH(S,"L");
    // PUSH(S,"A");
    // PUSH(S,"Y");
    // PUSH(S,"A");
    // PUSH(S,"L");
    // PUSH(S,"A");
    // PUSH(S,"M");

    PrintStack(S);

}