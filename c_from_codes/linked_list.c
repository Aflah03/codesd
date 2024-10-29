#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *next;
} Node;
Node *Start_SLL() {
  Node *head = (Node *)malloc(sizeof(Node));
  head->next = NULL;
  head->data = 0;
  return head;
}

Node *GetNode(int value) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = value;
  p->next = NULL;
  return p;
}

void Print_SLL(Node *head) {
  Node *temp = head->next;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

void Insert_Begining_SLL(Node *head, int value) {
  Node *newNode = GetNode(value);
  if (head->next == NULL)
    head->next = newNode;
  else {
    newNode->next = head->next;
    head->next = newNode;
  }
}

void SLL_INSERT_AT_END(Node *head, int value) {
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  Node *newNode = GetNode(value);
  temp->next = newNode;
}
void SLL_PRINT_IN_REVERSE(Node* p){
 
  
  if(p ==NULL)
      return;

  SLL_PRINT_IN_REVERSE(p->next);
  printf("%d ",p->data);
}
int main() {
  Node *head = Start_SLL();

  SLL_INSERT_AT_END(head,10);
  SLL_INSERT_AT_END(head,12);
  SLL_INSERT_AT_END(head,13);
  SLL_INSERT_AT_END(head,14);
  SLL_INSERT_AT_END(head,15);
  Print_SLL(head);
  printf("\n");
  SLL_PRINT_IN_REVERSE(head->next);
  // printf("Enter the number of values to insert ");
  // char buff[100];
  // fgets(buff, 100, stdin);
  // int n;
  // if (sscanf(buff, "%d", &n) != 1) {
  //   printf("Error ininput\n");
  //   return 1;
  // }
  // printf("ENter elements: ");
  // for (int i = 0; i < n; i++) {
  //   fgets(buff, 100, stdin);
  //   int n;
  //   int value;
  //   if (sscanf(buff, "%d", &value) != 1) {
  //     printf("Error ininput\n");
  //     return 1;
  //   }
    // SLL_INSERT_AT_END(head, value);
  
  // printf("The SLL is: ");
  // Print_SLL(head);
  
}
