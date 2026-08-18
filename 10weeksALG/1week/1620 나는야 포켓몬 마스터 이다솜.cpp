#include <bits/stdc++.h>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; 
    map<string, int> mp; 
    vector<string> v(100004); 
    string s; 
    
    cin >> n >> m; 
    for(int i = 1; i <= n; i++){
        cin >> s; 
        mp[s] = i; 
        v[i] = s;  
    }
    
    while(m--){
        cin >> s; 
        if('0' <= s[0] && s[0] <= '9'){
            cout << v[stoi(s)] << '\n'; 
        }else{
            cout  << mp[s] << '\n'; 
        }
    }
    return 0; 
}
