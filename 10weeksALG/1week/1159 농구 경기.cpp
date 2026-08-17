#include <bits/stdc++.h>
#include "header.h"
using namespace std; 


int solve(){
    map<char, int> mp; 
    int n;
    string s;
    bool isPinted = false; 
    cin >> n;
    
    while(n--){
        cin >> s; 
        mp[s[0]]++; 
    }
    
    for(auto m: mp){
        if(m.second >= 5) {
            cout << m.first;
            isPinted = true;
        }
    }
    if(!isPinted) cout << "PREDAJA" << '\n';
    
    return 0; 
}
