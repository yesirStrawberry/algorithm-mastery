#include <bits/stdc++.h>
using namespace std;

void solve() {
    map<char, int> mp; 
    for(char c = 'a'; 'a' <= c && c <= 'z'; c++){
        mp[c] = 0; 
    }
    
    string str; 
    cin >> str; 
    
    for(auto it = str.begin(); it != str.end(); it++){
        mp[*it]++; 
    }
    
    for(auto m: mp){
        cout << m.second << " "; 
    }
    
    return;  
}
