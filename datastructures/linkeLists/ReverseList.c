#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct List* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

}
Node* insertToEnd(Node* head,int data){
    Node* temp = createNode(data);
    if(head==NULL)  head=temp;
    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = createNode(data);

    }
    return head;
}

Node* printSLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
Node* ReveresList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr!= NULL){
       next = curr->next;
       curr->next = prev;
       prev = curr;
       curr = next; 
    }
    head= prev;
    return head;

} 
int main(){
    Node* head = NULL;
    head=insertToEnd(head,10);
    head=insertToEnd(head,21);
    head=insertToEnd(head,11);
    head=insertToEnd(head,15);
    head=insertToEnd(head,17);
    printf("\n");
    Node* head1 = ReveresList(head);
    printSLL(head1);
}