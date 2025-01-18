#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct {
    char A[N];
    int top;
} Stack;

void PUSH(Stack* S, char ch) {
    if (S->top == N - 1) {
        printf("Stack overflow\n");
        return;
    }
    S->A[++(S->top)] = ch;
}

char POP(Stack* S) {
    if (S->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return S->A[(S->top)--];
}

int isPalindrome(char* str) {
    int len = strlen(str);
    Stack S;
    S.top = -1;

    // Push all characters of the string onto the stack
    for (int i = 0; i < len; i++) {
        PUSH(&S, str[i]);
    }

    // Pop characters from the stack and compare with the original string
    for (int i = 0; i < len; i++) {
        if (str[i] != POP(&S)) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

int main() {
    char str[N];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}