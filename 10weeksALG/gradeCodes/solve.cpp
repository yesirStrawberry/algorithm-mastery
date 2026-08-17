#include <bits/stdc++.h>
#include "header.h"
using namespace std; 

int solve(){
    string st1, st2; 
    
    cin >> st1; 
    st2 = st1; 
    reverse(st2.begin(), st2.end()); 
    
    for(int i = 0; i < st1.size() / 2; i++){
        if(st1[i] != st2[i]){
            cout << 0 << '\n'; 
            return 0; 
        }
    }
    cout << 1 << '\n'; 
    
    return 0; 
}