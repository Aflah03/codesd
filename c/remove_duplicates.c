#include <stdio.h>
int main(){
  int arr[] = {1,1,1,2,2,2,3,3,32,23,12,3,4,12,4,4,5,12,5,5,6,6};
  int count = sizeof(arr)/sizeof(int);

  for(int i=0;i<count;i++){
    for(int j=0;j<count-i-1;j++){
      if(arr[j]< arr[j+1]){
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }

    }
  }
  for(int i=0;i<count;i++){
    for(int j=0;j<count-1;j++){
      if(arr[j]==arr[j+1]){
        for(int k=j;k<=count-1;k++){
            arr[k] =arr[k+1];
        }
        count--;
      }
    }
  }

  for(int i=0;i<count;i++){
    printf("%d ",arr[i]);
  }
}
