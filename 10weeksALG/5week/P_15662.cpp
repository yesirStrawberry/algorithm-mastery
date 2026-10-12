#include <bits/stdc++.h>
using namespace std; 

int visited[1004]; 
int t, k; 
pair<int, int> op[1004], arr[1004]; 

void setInput(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> t; 
    for(int i = 0; i < t; i++){
        string s;
        cin >> s; 
        int bs = 0;  
        for(char c : s){
            bs += (c - '0'); 
            bs <<= 1; 
        }
        bs >>= 1; 
        arr[i].first = bs; 
    }
    cin >> k; 
    for(int i = 0; i < k; i++){
        cin >> op[i].first >> op[i].second; 
        op[i].first--; 
    }
}

void rotate(pair<int, int>& p){
    if(p.second == 0) return; 
    int bs = p.first;
    if(p.second == 1){
        int tmp = (bs & 1) << 7; 
        bs >>= 1; 
        bs += tmp; 
        bs &= 0x000000ff; 
    }else if(p.second == -1){
        int tmp = (bs & (1 << 7)) >> 7; 
        bs <<= 1; 
        bs += tmp; 
        bs &= 0x000000ff; 
    }
    p.first = bs; 
    p.second = 0; 
    return; 
}

void dfs(int x, int dir){
    visited[x] = 1; 
    arr[x].second = dir; 
    for(int d : {-1, 1}){
        int nx = x + d; 
        if(nx < 0 || nx >= t) continue; 
        if(visited[nx]) continue; 
        int x_side  =  arr[x].first & (1 << (3 + 2 * d)); 
        int nx_side = arr[nx].first & (1 << (3 - 2 * d)); 
        if((x_side && nx_side) || (!x_side && !nx_side)) continue; 
        dfs(nx, -dir); 
    }
}

int getSolve(){
    int cnt = 0; 
    int idx7 = (1 << 7); 
    for(int i = 0; i < t; i++){
        if(arr[i].first & idx7) cnt++; 
    }
    return cnt; 
}

int main(){ 
    setInput(); 
    for(int i = 0; i < k; i++){
        int idx = op[i].first; 
        int dir = op[i].second; 
        dfs(idx, dir); 
        for(int j = 0; j < t; j++) rotate(arr[j]); 
        fill(&visited[0], &visited[0] + 1004, 0); 
    }
    cout << getSolve() << '\n'; 

    return 0; 
}