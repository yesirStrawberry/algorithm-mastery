#include <bits/stdc++.h>
using namespace std; 

int n, dead, num, ret; 
vector<pair<int, int>> v; 
priority_queue<int, vector<int>, greater<int>> pq; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    v.reserve(n); 
    for(int i = 0; i < n; i++){
        cin >> dead >> num; 
        v.push_back({dead, num}); 
    }
    sort(v.begin(), v.end()); 
    for(int i = 0; i < n; i++){
        pq.push(v[i].second);
        if(v[i].first < pq.size()) pq.pop();  
    }
    while(pq.size()){
        ret += pq.top(); pq.pop(); 
    }
    cout << ret << '\n'; 

    return 0; 
}