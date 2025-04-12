#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){

    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '{' || s[i]== '(' || s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.empty() ==1 || st.top() !='(') return false;
            st.pop(); 
        }        
        else if(s[i] == '}'){
            if(st.empty() ==1 || st.top() !='{') return false;
            st.pop(); 
        }        
        else if(s[i] == ']'){
            if(st.empty() ==1 || st.top() !='[') return false;
            return true; 
        }
        else continue;
    }
    if(st.empty()==1) return true;
    return false;
}
int main(){
    // string expression = "{[()]}";
    string expression;
    cout << "Enter a string";
    cin >> expression;
    cout << expression.size();
    if(isValid(expression)) 
     cout << "Is a palindorme"; 
    else
        cout << "Not a palindrome";
}