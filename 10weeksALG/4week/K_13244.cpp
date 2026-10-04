#include <bits/stdc++.h>
using namespace std; 

int n, m, visited[1004]; 
vector<int> adj[1004]; 

int dfs(int x){
    int ret = 1; 
    visited[x] = 1; 
    for(int nx : adj[x]){
        if(visited[nx]) continue;
        ret += dfs(nx); 
    }
    return ret; 
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    int t, a, b; 
    cin >> t; 
    while(t--){
        bool isTree = false; 
        fill(visited, visited + 1004, 0); 
        for(int i = 0; i < 1004; i++) adj[i].clear(); 
        
        cin >> n >> m; 
        for(int i = 0; i < m; i++){
            cin >> a >> b; 
            adj[a].push_back(b); 
            adj[b].push_back(a); 
        }
        if(n == m + 1 && n == dfs(1)) isTree = true; 
        if(isTree) cout << "tree" << '\n'; 
        else cout << "graph" << '\n'; 
    }

    return 0; 
}