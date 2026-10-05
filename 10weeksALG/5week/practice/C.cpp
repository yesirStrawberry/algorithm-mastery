#include <bits/stdc++.h>
using namespace std; 

int n, m, k, ret; 

int main(void){
    cin >> n >> k;
    vector<pair<int, int>> v(n); 
    vector<int> bags(k);    
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second; 
    }
    for(int i = 0; i < k; i++){
        cin >> bags[i]; 
    }
    sort(v.begin(), v.end()); 
    sort(bags.begin(), bags.end()); 
    priority_queue<int> pq; 

    int j = 0; 
    for(int i = 0; i < k; i++){
        while(j < n && v[j].first <= bags[i]) {
            pq.push(v[j].second);
            j++; 
        }
        if(pq.size()){
            ret += pq.top(); 
            pq.pop(); 
        }
    }
    cout << ret << '\n';
    return 0; 
}