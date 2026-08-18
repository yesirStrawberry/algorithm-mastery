#include <bits/stdc++.h>
using namespace std; 

int ret = 0; 

void combi(
    const vector<int>& values, 
    const int n, 
    const int k, 
    int start, 
    vector<int> b
){
    if(b.size() == k){
        int val = 1; 
        for(int i : b) val *= values[i]; 
        ret += val; 
        return; 
    }
    
    for(int i = start + 1; i < n; i++){
        b.push_back(i); 
        combi(values, n, k, i, b); 
        b.pop_back(); 
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    
    while(t--){
        int n; 
        ret = 0; 
        
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
        
        for(int i = 1; i <= values.size(); i++){
            vector<int> b; 
            combi(values, values.size(), i, -1, b); 
        }
        
        cout << ret << '\n'; 
    }
    
    return 0; 
}
