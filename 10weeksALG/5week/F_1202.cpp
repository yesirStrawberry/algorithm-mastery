#include <bits/stdc++.h>
using namespace std; 

int n, k;
long long ret; 
vector<pair<int, int>> v;
vector<int> bags;  
priority_queue<int> pq; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n >> k;
    v.reserve(n); 
    bags.reserve(k); 
    
    int mi, vi, ci; 
    for(int i = 0; i < n; i++){
        cin >> mi >> vi; 
        v.push_back({mi, vi}); 
    }
    for(int i = 0; i < k; i++){
        cin >> ci; 
        bags.push_back(ci); 
    }
    sort(v.begin(), v.end()); 
    sort(bags.begin(), bags.end()); 

    int j = 0; 
    for(int i = 0; i < k; i++){
        while(j < n && v[j].first <= bags[i]) pq.push(v[j++].second);
        if(pq.size()){
            ret += pq.top(); 
            pq.pop(); 
        }
    }
    cout << ret << '\n'; 

    return 0;
}