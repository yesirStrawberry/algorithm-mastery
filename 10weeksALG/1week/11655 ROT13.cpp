#include "header.h"
#include <bits/stdc++.h>
using namespace std; 

int solve(){
    string s, ret; 
    char p; 
    
    getline(cin, s);  
    
    for(char c : s){
        p = c; 
        if('a' <= c && c <= 'z'){
            p = 'a' + (c - 'a' + 13) % 26; 
        }
        else if('A' <= c && c <= 'Z'){
            p = 'A' + (c - 'A' + 13) % 26; 
        }
        ret += p; 
    }
    
    cout << ret; 
    
    return 0; 
}
