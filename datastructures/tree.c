#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
}Node ;

Node* getNode(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->right=NULL;
  newNode->left=NULL;
  newNode->data = data;
  return newNode;

}
Node* insert(Node* root,int data){
  if(root==NULL){
    return getNode(data);
  }
  else if(data > root->data){
    root->right = insert(root->right,  data);
  }
  else{
    root->left = insert(root->left,  data);
  }
  return root;
}
void inorder(Node* root){
  // if(root != NULL){
  //   inorder(root->left);
  //   printf("%d ",root->data);
  //   inorder(root->right);
  // }
  if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  
}

void preorder(Node* root){
  if(root != NULL){ 
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  } 

}
void postorder(Node* root){
  if(root != NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  }

}
int main(){
  Node* root = getNode(10); 

  // printf("%d", root->data);
root=  insert(root,7); 
  root= insert(root,5); 
  root = insert(root,8); 
  root= insert(root,14); 
  root = insert(root,13); 
  root = insert(root,16); 

  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
  postorder(root);
}
