#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

struct freq{
    int key; 
    int val; 
    int order; 
}; 

bool compare(const freq& a, const freq& b){
    if(a.val == b.val) return a.order < b.order; // val 같으면, order 오름차순 
    return a.val > b.val; // val로 내림차순, 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, c; 
    map<ll, pair<int, int>> mp; 
    
    cin >> n >> c; 
    
    for(int i = 1; i <= n; i++){
        int temp; 
        cin >> temp; 
        mp[temp].first++; 
        if(mp[temp].second == 0) mp[temp].second = i; 
    }
    
    vector<freq> v; 
    for(auto [key, val] : mp){
        freq fq = {key, val.first, val.second}; 
        v.push_back(fq); 
    }
    
    sort(v.begin(), v.end(), compare); 
    for(auto fq : v){
        for(int i = 0; i < fq.val; i++) cout << fq.key << " "; 
    }
    
    return 0; 
}
