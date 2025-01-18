#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int data;
  struct Node* right;
  struct Node* left;
}Node;
Node* createNode(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->right = NULL;
  newNode->left = NULL;
  return newNode;
}
void INORDER(Node* root){
  if(root!= NULL){
    INORDER(root->left);
    printf("%d ",root->data);
    INORDER(root->right);
  }
}
Node* Search(Node* root,int data){

  if(root == NULL) return NULL;
  
  else if(data == root->data) return root;

  else if(data> root->data)return Search(root->right,data);
  else return Search(root->left, data); 

  
  
  return NULL;
}

Node*  insert(Node* root,int data){
  if(root==NULL){
    return createNode(data);
  }
  if(data > root->data) root->right = insert(root->right, data);
  else root->left = insert(root->left, data);
  return root;
}
int main(){
  Node* root = createNode(1);
  Node* N2 = createNode(2);
  Node* N3 = createNode(3);
  Node* N4 = createNode(4);
  Node* N5 = createNode(5);
  Node* N6 = createNode(6);
  Node* N7 = createNode(7);
  Node* N8 = createNode(8);

  root->left = N2;
  root->right = N3;

  N2->left = N4;
  N2->right = N5;

  N3->left = N6;
  N3->right = N8;

  INORDER(root);

  printf("\n Enter a value to search : ");
  int x;
  scanf("%d",&x);
  getchar();


  printf("Searching for %d",x);
  Node* temp = Search(root, x);
  printf("the value of temp is %p\n",temp);
  if(temp == NULL) printf("Not found");
  else printf("found");
}
