#include <stdio.h>
int main(){
  int arr[]={2,2,2,1,1,1,1,4,4,4,3,3,3,3,3};
  int count = sizeof(arr)/sizeof(int);
  for(int i=0;i<count;i++){
    for(int j=0;j<count-1;j++){
      if(arr[j]< arr[j+1]){
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }

    }
  }
  for(int i=0;i<count;i++){
    printf("%d ",arr[i]);
  }
}
