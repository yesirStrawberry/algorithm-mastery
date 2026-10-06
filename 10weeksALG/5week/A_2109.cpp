#include <bits/stdc++.h>
using namespace std; 

int n, ret; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    if(n == 0){
        cout << 0 << '\n'; 
        return 0; 
    }
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;  

    sort(v.rbegin(), v.rend()); 
    priority_queue<int> pq; 
    int j = 0; 
    int max_day = v[0].first; 
    for(int i = max_day; i > 0; i--){ 
        while(j < n && v[j].first == i)pq.push(v[j++].second); 
        if(pq.size()){
            ret += pq.top(); pq.pop();
        } 
    }
    cout << ret << '\n'; 

    return 0; 
}