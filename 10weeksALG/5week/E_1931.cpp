#include <bits/stdc++.h>
using namespace std; 

int n, ret, to; 
vector<pair<int, int>> v; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n;
    v.reserve(n); 
    int from, to;  
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({to, from}); 
    }
    sort(v.begin(), v.end()); 

    to = v[0].first; ret++; 
    for(int i = 1; i < n; i++){
        if(to <= v[i].second){
            to = v[i].first; 
            ret++; 
        }
    }
    cout << ret << '\n'; 

    return 0; 
}