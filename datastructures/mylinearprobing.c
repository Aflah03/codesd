#include<stdio.h>
#define size 7

int hash(int data){
    return data%size;
}
int insert(int HASH_TABLE[],int value){
    int index = hash(value);
    int probeCount =0;
    while(HASH_TABLE[index]!=-1 && HASH_TABLE[index]!=value ){
        probeCount++;
        index = (index+1)%size;
    

        if(probeCount >= size){
        printf("Hash table is full and cannot insert anymore values");
        return -1;
        }
    }
    HASH_TABLE[index] = value;
    printf("Inserted %d at index %d with a probecount %d\n",value,index,probeCount);
    return index;

}

int Search(int HASH_TABLE[],int key){
    int index = hash(key);
    int probeCount = 0;

    while(HASH_TABLE[index] != -1){
        if(HASH_TABLE[index]==key){
            return index;
        }
        index = (index+1)%size;
        probeCount++;

        if(probeCount >=size) break;
    }
    return -1;
    
}
void PRINT_TABLE(int HASH_TABLE[]){
    for(int i=0;i<size;i++){
        if(HASH_TABLE[i]!= -1){
            printf("Index: %d : %d\n",i,HASH_TABLE[i]);
        }
        else{
            printf("Index %d: Empty\n",i);
        }
    }
}

int main(){
int HASH_TABLE[size]={-1};
for(int i=0;i<size;i++){
    HASH_TABLE[i] = -1;
}
insert(HASH_TABLE,25);
insert(HASH_TABLE,39);
insert(HASH_TABLE,18);
insert(HASH_TABLE,58);
insert(HASH_TABLE,68);
insert(HASH_TABLE,38);
insert(HASH_TABLE,9);
PRINT_TABLE(HASH_TABLE);

int x = Search(HASH_TABLE,9);
printf("The value of x is %d",x);
    
}