#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void twoSum(vector<int>& nums,int target){
    int n = nums.size();
    int l = 0, r= n-1;
    int flag =0;
    sort(nums.begin(), nums.end());
    while(r > l){
        if(nums[r] + nums[l] == target){
            cout << nums[l] <<" "<< nums[r];
            flag=1;
            break;
            
        }else if( nums[l] + nums[r] > target){
            r--;
        
        }else{
            l++;
        }
    }
    if(flag==0)
    cout <<" No result found ";

}
int main(){
    vector<int> myvect = {3,2,4};
    int target;

    cout << "Enter target";
    cin >> target;
    twoSum(myvect,target);

}