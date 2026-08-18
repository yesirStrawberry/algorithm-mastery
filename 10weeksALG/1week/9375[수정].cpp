#include <bits/stdc++.h>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    
    while(t--){
        int n; 
        
        cin >> n; 
        map<string, int> mp; 
        string trash, s; 
        
        while(n--){
            cin >> trash >> s; 
            mp[s]++; 
        }
        
        vector<int> values; 
        for(auto& [key, value] : mp){
            values.push_back(value); 
        }
        
        int ret = 1; 
        for(int val : values) ret *= val + 1;
        ret--; 
        
        cout << ret << '\n'; 
    }
    
    return 0; 
}
