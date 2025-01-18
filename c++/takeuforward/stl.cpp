#include<bits/stdc++.h>
using namespace std;


int main(){
    // pair<int ,int> p = {3,1};
    // cout << p.first << " "<< p.second;

    // pair<int, pair<int,int>>p1 = {1,{3,4}};

    // cout << p1.first << " " << p1.second.first << " "<< p1.second.second;

      int a[]={12,35,1,10,34,1};
  int n = sizeof(a)/sizeof(int);
  for(int i=0;i<n;i++){
    cout << a[i] << " ";
  }
    int Slargest = -1;
    int largest = a[0];
    for(int i=0;i<n;i++){
            cout << "value of i is : " << i<< " a[i]= "<< a[i]<< endl<< " largest: "<< largest<< " Slargest: "<< Slargest<< endl; 

            if(a[i] > largest){
            Slargest = largest;
            largest = a[i];
            cout << "updated largest to " << largest<< endl;
            } 
            if(a[i] < largest && a[i] > Slargest) {
                Slargest = a[i];
            cout << "updated Second largest to " << Slargest<< endl;
            }
            cout << "----------------------------"<<endl;
    }

    cout<<endl<< "Second largest is : " << Slargest<< endl;
    cout << "largest is : "<< largest << endl;
}