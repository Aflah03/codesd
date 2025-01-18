#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
        stack<string> words;
        string Word="";
        int r=0;
        while(s[r]!= '\0'){
            if(s[r]==' '){ 
                words.push(Word);
                Word="";
                r++;
                break;
            }
            string letter(1,s[r]);
            Word.append(letter); 
            r++;
        }
        string result="";
        while(!(words.empty())){
            result.append(words.top());
            words.pop();
            result.append(" ");
        }
        s.size()
        return result;

    }

    int  main(){
        cout << reverseWords("Aflah The man");
        return 0;
    }