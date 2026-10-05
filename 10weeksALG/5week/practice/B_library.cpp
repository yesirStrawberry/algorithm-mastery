#include <bits/stdc++.h>
using namespace std; 

int n, ret = 1; 
vector<pair<int, int>> v; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; int s, e; 
    for(int i = 0; i < n; i++){
        cin >> s >> e; 
        v.push_back({e, s}); 
    }
    sort(v.begin(), v.end()); 
    int to = v[0].first; 
    for(int i = 0; i < n; i++){
        if(to < v[i].second){
            to = v[i].second; 
            ret++; 
        }
    }
    cout << ret << '\n'; 

    return 0; 
}