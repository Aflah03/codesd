#include<stdio.h>
void reversee(int a[],int start,int end){
    if(start<end){
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
    }
    reversee(a,start+1,end-1);
}
int main(){
    int arr[] ={5,4,3,2,1};
    int n= sizeof(arr)/sizeof(int);
    reversee(arr,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
what is going on mN RH]