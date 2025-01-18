#include<stdio.h>
#include<stdlib.h>
typedef struct  Node{
    int coeff,exp;
    struct Node* next;
}Node;

Node* createNode(int coeff,int exp){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
Node* insertAtEnd(Node* head,int coeff,int exp){

    Node* newNode = createNode(coeff,exp);
    if(head==NULL){
        head = newNode;        
    }
    else{
        Node* temp = head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

Node* Add(Node* p1,Node* p2,Node* result){
    Node* ptr1  = p1;
    Node* ptr2 = p2;

    while(ptr1!= NULL && ptr2 != NULL){
        if(ptr1->exp == ptr2->exp){
            result= insertAtEnd(result,ptr1->coeff+ptr2->coeff,ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }else if(ptr1->exp > ptr2->exp){
            result= insertAtEnd(result,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next;
        }else{
            result= insertAtEnd(result,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL){
            result= insertAtEnd(result,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next;

    }
    while(ptr2 != NULL){
            result= insertAtEnd(result,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next;
    }
    return result;
}
void PrintLlist(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%dx^%d ",temp->coeff,temp->exp);
        temp = temp->next;
    }
}
int main(){
    printf("Enter the number of nodes to insert");
    Node* result = NULL;
    Node* p1 = NULL;   
    Node* p2 =NULL; 

    printf("Enter no of terms in  the first polynomial: ");
    int n1;
    scanf("%d",&n1);
    getchar();

    printf("Enter the coeff and power");
    for(int i=0;i<n1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        getchar();
        p1=insertAtEnd(p1,x,y);
    }
    

    printf("Enter no of terms in  the second polynomial: ");
    int n2;
    scanf("%d",&n2);
    getchar();
    printf("Enter the coeff and power");
    for(int i=0;i<n2;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        getchar();
        p2=insertAtEnd(p2,x,y);
    }


    printf("the first polynomial is : ");
    PrintLlist(p1);


    printf("the second polynomial is : ");
    PrintLlist(p2);


    
    printf("The result is : ");
    result = Add(p1,p2,result);
    // result = Add(p1,p2,result);
    PrintLlist(result);
    
}