#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int data;
  struct Node* next;
}Node;
//Initialize as global



Node* createNode(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insert(Node* root, int data){
  Node* temp = root;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = createNode(data);

}

void PrintList(Node* root){
  Node* temp = root->next;
  while(temp!= NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
}

int main(){

  Node* list1 = createNode(0);
  Node* list2 = createNode(0);

  printf("Enter the  number of nodes in list 1:");
  int n1,n2;
  scanf("%d",&n1);
  getchar();

  printf("Enter the numbers:");
  for(int i=0;i<n1;i++){
    int x;
    scanf("%d",&x);
    getchar();
    insert(list1, x);
    // printf("---------you entered %d---------\n",x);
  }
  printf("Enter the  number of nodes in list 2:");
  scanf("%d",&n2);
  getchar();
  printf("Enter the numbers:");
  for(int i=0;i<n2;i++){
    int x;
    scanf("%d",&x);
    getchar();
    insert(list2, x);
    // printf("---------you entered %d---------\n",x);
  }

  // merge smaller list to bakck of bigger list
  if(n1!=0  &&  n2 != 0){
    if(n2< n1){
    Node* temp = list1;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next= list2->next;
      printf("The mereged list is : ");
      PrintList(list1);
   }
    else{

    Node* temp = list2->next;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next= list1->next;
      printf("The mereged list is : ");
      PrintList(list2);
    }
  }
  // printf("List 1 \n");
  // PrintList(list1);
  //
  // printf("List 2 \n");
  // PrintList(list2);
}
