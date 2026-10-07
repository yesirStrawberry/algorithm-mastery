#include <bits/stdc++.h>
using namespace std; 

int n, a, b, curr, idx; 
vector<pair<int, int>> v; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> a >> b; 
        v.push_back({a, b}); 
    }
    sort(v.begin(), v.end()); 
    for(int i = 0; i < n; i++){
        if(curr >= v[i].first) curr += v[i].second; 
        else curr = v[i].first + v[i].second; 
    }
    cout << curr << '\n'; 

    return 0; 
}