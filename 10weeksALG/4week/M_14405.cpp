#include <bits/stdc++.h>
using namespace std; 

int main(void){
    string s, curr = ""; 
    cin >> s; 
    for(char c : s){
        curr += c; 
        if(curr == "pi" || curr == "ka" || curr == "chu"){
            curr = ""; 
        }
    }
    if(curr.size() == 0) cout << "YES" << '\n'; 
    else cout << "NO" << '\n';
    
    return 0; 
}