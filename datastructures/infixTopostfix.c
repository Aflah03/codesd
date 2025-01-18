#include <bits/types/stack_t.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef struct Stack {
  char arr[N];
  int top;
} Stack;

int PUSH(Stack *S, char item) {
  if (S->top == N - 1) {
    return -1;
  } else {
    S->top++;
    S->arr[S->top] = item;
    return 1;
  }
}

char POP(Stack *S) {
  if (S->top == -1) {
    return -1;
  } else {
    char temp = S->arr[S->top];
    S->top--;
    return temp;
  }
}

int weight(char ch) {
  if (ch == '+' || ch == '-')
    return 1;
  if (ch == '*' || ch == '/')
    return 2;
  if (ch == '^')
    return 3;
  return 0;
}
bool isRightAssociative(char ch) {
  if (ch == '^')
    return true;
  return false;
}

bool Isoperand(char C){
    if(C >='0' && C<='9') return true;
    if(C >='a' && C<='z') return true;
    if(C >='A' && C<='Z') return true;
    return false;
}

bool Isoperator(char C){
    if( C== '+' || C == '-' ||  C == '*' || C=='/' ||C== '^')
        return true;
    return false;
}

int precedence(char c1, char c2) {
  int op1 = weight(c1);
  int op2 = weight(c2);
  if (op1 == op2) {

    if (isRightAssociative(c1))
      return false;
    return true;
  }
  return op1 > op2 ? true : false;
}

int main() {

  Stack *S = (Stack *)malloc(sizeof(Stack));
  S->top = -1;

  char expression[100] = "(5+2)*(7+4)";
  // printf("enter the expression");

  // fgets(expression,100,stdin);
  // expression[strcspn(expression,"\n")]= '\0';
  printf("The postfix expression is : ");
  for (int i = 0; i < strlen(expression); i++) {

    if (expression[i] == ' ' || expression[i] == ',')
      continue;
    else if (expression[i] == '(') {
      PUSH(S, expression[i]);
    }
    else if(expression[i]==')'){
      char x = POP(S);
      while(x!= '(' && S->top!=-1){
        printf("%c ",x);
        x = POP(S);
      }
    }
    else if(Isoperand(expression[i])){
        printf("%c ",expression[i]);
    }
    else {
    

      while(S->top!=-1 && precedence(S->arr[S->top] ,expression[i])){

      char x = POP(S);
      printf("%c ",x);
      }
    PUSH(S,expression[i]);
    }
    
  }
  while(S->top!=-1){
    char x  = POP(S);
    printf("%c ",x);
  }



  //NOW CONVERTING TO PREFIX EXPRESSION
  /*
  Steps to Convert Infix to Prefix
Approach:

    Reverse the Infix Expression: Start by reversing the infix expression. Swap each opening parenthesis ( with a closing parenthesis ) and vice versa.

    Convert Infix (reversed) to Postfix: Use a stack to convert this modified expression (which is reversed) into a postfix expression.

    Reverse the Postfix Result: Finally, reverse the postfix expression obtained in the previous step. This reversed postfix expression is the required prefix expression.
  
  */


 char reversed[100];
 for(int i=0;i<strlen(expression);i++){
  if(expression[strlen(expression)-1-i] == '('){
reversed[strlen(expression)-1-i] = ')';

  }   else if(expression[strlen(expression)-1-i] == ')'){
reversed[strlen(expression)-1-i] = '(';

  }   else reversed[i] = expression[strlen(expression)-1-i];
 }

 printf("\nthe reverse expression is: ");
 for(int i=0;i<strlen(reversed);i++){
  printf("%c ",reversed[i]);
 }
}
