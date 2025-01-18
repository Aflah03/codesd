#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, exp;
    struct Node* next;
} Node;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtEnd(Node* head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (head == NULL) {
        head = newNode;        
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node* Add(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            result = insertAtEnd(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = insertAtEnd(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            result = insertAtEnd(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertAtEnd(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertAtEnd(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

void PrintLlist(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    Node* result = NULL;
    Node* p1 = NULL;   
    Node* p2 = NULL; 

    printf("Enter the number of terms in the first polynomial: ");
    int n1;
    scanf("%d", &n1);

    printf("Enter the coeff and power for each term:\n");
    for (int i = 0; i < n1; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        p1 = insertAtEnd(p1, coeff, exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    int n2;
    scanf("%d", &n2);

    printf("Enter the coeff and power for each term:\n");
    for (int i = 0; i < n2; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        p2 = insertAtEnd(p2, coeff, exp);
    }

    printf("\nThe first polynomial is: ");
    PrintLlist(p1);

    printf("The second polynomial is: ");
    PrintLlist(p2);

    result = Add(p1, p2);
    printf("The resulting polynomial after addition is: ");
    PrintLlist(result);

    return 0;
}

