#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data;
  struct Node *right;
  struct Node *left;
} Node;
typedef struct{
  Node* A[40];
  int front,rear;
}Queue;

void mirror(Node* root);
Node* DEQUEUE(Queue* Q);
void ENQUEUE(Queue* Q,Node* node);
void PRINT_QUEUE(Queue* Q);

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->right = NULL;
  newNode->left = NULL;
  return newNode;
}
void INORDER(Node *root) {
  if (root != NULL) {
    INORDER(root->left);
    printf("%d ", root->data);
    INORDER(root->right);
  }
}
Node *Search(Node *root, int data) {
  Node *temp = root;
  if (temp != NULL) {
    if (data == temp->data)
      return temp;
    else if (data > temp->data) {
      return Search(temp->right, data);
    } else
      return Search(root->left, data);
  }

  return NULL;
}

Node *insert(Node *root, int data) {
  if (root == NULL) {
    return createNode(data);
  }
  if (data > root->data)
    root->right = insert(root->right, data);
  else
    root->left = insert(root->left, data);
  return root;
}
Node *BST_MAX(Node *root) {
  if (root == NULL)
    return NULL;
  Node *temp = root;
  while (temp->right != NULL)
    temp = temp->right;
  return temp;
}

Node *parent(Node *root, int key) {
  Node *par = NULL;
  Node *p = root;
  while (p != NULL) {
    if (p->data == key) {
      return par;
    } else if (key > p->data) {
      par = p;
      p = p->right;
    } else {
      par = p;
      p = p->left;
    }
  }
  return par;
}

int arr[10];
int i = 0;
void inorder_revers(int arr[], Node *root) {
  if (root != NULL) {
    inorder_revers(arr, root->left);
    arr[i++] = root->data;
    inorder_revers(arr, root->right);
  }
}
int countFullNode(Node *root) {
  if (root == NULL)
    return 0;
  int count = 0;
  if (root->left != NULL && root->right != NULL)
    count = 1;
  return count + countFullNode(root->left) + countFullNode(root->right);
}

int countNode(Node* root){
  if(root== NULL) return 0;
  return 1+ countNode(root->left)+ countNode(root->right);
}

int countHalfNodes(Node* root){
  if(root == NULL) return 0;
  int count = 0;
  if((root->right==NULL && root->left!= NULL) || (root->left==NULL && root->right!= NULL)) count = 1;

  return count + countHalfNodes(root->left) + countHalfNodes(root->right);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(Node* root){
  if(root== NULL) return 0;

  return 1+ max(height(root->left), height(root->right));
}

/*Level Order treaversal code*/
void LevelOrder(Node* root,Queue* Q){
  if(root==NULL)return ;
  ENQUEUE(Q,root);
  while(Q->front != -1){
    Node* current = Q->A[Q->front];
    printf("%d ",current->data);
    if(current->right != NULL) ENQUEUE(Q,current->right);
    if(current->left != NULL) ENQUEUE(Q,current->left);
    DEQUEUE(Q);

  }


}

int main() {

  Node *root = createNode(10);
  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 6);
  root = insert(root, 12);
  root = insert(root, 11);
  root = insert(root, 20);
  root = insert(root, 2);
  printf("the inorder traversal is : ");

  INORDER(root);
  printf("\n");

  // printf("\n Enter a value to search : ");
  // int x;
  // scanf("%d", &x);
  // getchar();
  //
  // printf("Searching for %d", x);
  // Node *temp = Search(root, x);
  // if (temp == NULL)
  //   printf("Not found");
  // else
  //   printf("found");
  printf("the max in the tree is %d\n", BST_MAX(root)->data);

  inorder_revers(arr, root);
  printf("The parent of 20 is %d\n", parent(root, 20)->data);
  // this line could give segemtation falutl when parent off root is rquested as
  // we get null as the answer and we call null->data

  for (int i = 6; i >= 0; i--) {
    printf("%d ", arr[i]);
  }

  printf("\n The number of full nodes is : %d", countFullNode(root));

  printf("\n The total number of nodes in the tree is : %d",countNode(root));

  printf("\n The half nodes in tree are %d\n",countHalfNodes(root));


  printf("The height of the tree is %d", height(root));


  Node* temp1 = createNode(25);
  Node* temp2 = createNode(55);
  Node* temp3 = createNode(200);
  Queue* Q = (Queue*)malloc(sizeof(Queue));
  Q->front = -1;
  Q->rear = -1;
  ENQUEUE(Q,temp1);
  ENQUEUE(Q, temp2);
  Node* dequeued = DEQUEUE(Q);
  printf("you just dequeued %d",dequeued->data);
  ENQUEUE(Q,temp3);
  printf("The queeu right now is :\n");
  PRINT_QUEUE(Q);

  Q->front =-1;
  Q->rear =-1;

  printf("\n the level order traversal is : ");
  LevelOrder(root, Q);

  printf("\nThe mirrored tree is : ");
  mirror(root);
  INORDER(root);

}




void PRINT_QUEUE(Queue* Q){
  int temp = Q->front;
  while(temp != Q->rear+1){
    printf("%d ",Q->A[temp]->data);
    temp++;
  }
}


Node* DEQUEUE(Queue* Q){
  if(Q->front ==-1) return NULL;
  else if(Q->front ==Q->rear){
    Node* temp = Q->A[Q->front];
    Q->front =-1;
    Q->rear = -1;
    return temp;
  }
  else {
    Node* temp = Q->A[Q->front];
    Q->front++;
    return temp;
  }
}

void ENQUEUE(Queue* Q,Node* node){
  if(Q->front==-1){
    Q->front = 0;
    Q->rear =0;
    Q->A[Q->rear] = node;
  }
  else {
    Q->A[++(Q->rear)] = node;
  }
}

void mirror(Node* root){
  if(root == NULL) return;

  Node* temp = root->right;
  root->right = root->left;
  root->left = temp;

  mirror(root->left);
  mirror(root->right);
}
