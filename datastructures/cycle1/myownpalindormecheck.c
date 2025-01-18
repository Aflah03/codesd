#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 20
typedef struct {
    char A[N];
    int top;
}Stack;
Stack* S = NULL;
void PUSH(char c){
    S->top++;
    S->A[S->top] = c;
}
char POP(){
    if(S->top==-1) return -1;
    return S->A[S->top--];
}
bool isPalindrome(char word[]){
    int l =0;
    while(word[l] != '\0'){
        PUSH(word[l]);
        l++;
    }
    for(int i=0;i<strlen(word);i++){
        char x = POP(S);
        if(x != word[i]){
            printf("Not a  palindrome");
            return 0;
        }
    }
    printf("Is a palindorme ");
}
int main(){

  S = (Stack*)malloc(sizeof(Stack));
    S->top=-1;
    char word[100];
    printf("Enter the string: ");
    fgets(word,100,stdin);
    word[strcspn(word,"\n")]= '\0';
    isPalindrome(word);
}