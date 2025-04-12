#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    Node* next;
}Node;
Node* getNode(int data){
    Node* newNode = new Node;
    newNode->data =data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node* root,int data){
    Node* temp = root;
    while(temp->next != NULL){
        temp = temp->next;
        
    }
    temp ->next = getNode(data);
}

void printList(Node* root){
    Node* temp = root;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node* RemoveKthNodeFromEnd(Node* root,int k){
    //calculating the Nth node from font
    int N =0;
    Node* temp = root;
    while(temp != NULL){
        N++;
        temp = temp->next;
    } 
    int Nth= N-k+1;//kth node from end is N-k+1 th form the begining192.168.1.1
    Node* p = NULL;
    Node* q = root;
    int count =1;
    while(q != NULL && count< Nth ){
        p = q;
        q = q->next;
        count++;
    }
    if(p==NULL){
        return root->next;
    }
    else{
    p->next = q->next;
    }
    delete q;
    return root;
}
int main(){
   Node* root = getNode(1);
   insertAtEnd(root,2);      
   insertAtEnd(root,3);      
   insertAtEnd(root,4);      
   insertAtEnd(root,5);      
    
    root = RemoveKthNodeFromEnd(root,4);
printList(root);
}