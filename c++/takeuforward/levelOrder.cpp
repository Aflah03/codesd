#include<bits/stdc++.h>
using namespace std;
int main(){
    
   
    vector<vector<int>> ans;
    vector<int> level;

    level.push_back(5);
    level.push_back(6);
    level.push_back(7);

    ans.push_back(level);

    level.push_back(11);
    level.push_back(12);
    level.push_back(13);

    ans.push_back(level);

    for(auto nums: ans){

    cout << ans[0];
    
    }
}