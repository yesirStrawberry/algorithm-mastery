#include <bits/stdc++.h>
using namespace std; 

int n, ret; 
vector<pair<int, int>> v; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    v.reserve(n);
    int a, b;  
    for(int i = 0; i < n; i++){
        cin >> a >> b; 
        v.push_back({a, b}); 
    }
    sort(v.begin(), v.end()); 
    
    int to = v[0].second;
    ret += to - v[0].first;  
    for(int i = 0; i < n; i++){
        if(to >= v[i].second) continue;
        if(to < v[i].first) ret += v[i].second - v[i].first; 
        else ret += v[i].second - to; 
        to = v[i].second; 
    }
    cout << ret << '\n'; 

    return 0; 
}