#include <bits/stdc++.h>
using namespace std; 

int t, k; 
pair<int, int> op[1004], arr[1004]; 

void set_input(){
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
        bs = (bs >> 1) | ((bs & 1) << 7); 
    }else if(p.second == -1){
        bs = ((bs << 1) & 0xff) | ((bs >> 7) & 1); 
    }
    bs &= 0xff;
    p.first = bs; 
    p.second = 0; 
    return; 
}

void set_dir(int sx, int sdir){
    int dir = sdir; 
    int nx, x_side, nx_side;
    arr[sx].second = dir;   
    for(int x = sx; x < t - 1; x++){
        nx = x + 1; 
        x_side = arr[x].first & (1 << 5); 
        nx_side = arr[nx].first & (1 << 1); 
        if(bool(x_side) == bool(nx_side)) break; 
        dir = -dir; 
        arr[nx].second = dir; 
    }
    dir = sdir; 
    for(int x = sx; x > 0; x--){
        nx = x - 1; 
        x_side = arr[x].first & (1 << 1); 
        nx_side = arr[nx].first & (1 << 5); 
        if(bool(x_side) == bool(nx_side)) break; 
        dir = -dir; 
        arr[nx].second = dir; 
    }
}

int get_solve(){
    int cnt = 0; 
    int idx7 = (1 << 7); 
    for(int i = 0; i < t; i++){
        if(arr[i].first & idx7) cnt++; 
    }
    return cnt; 
}

int main(){ 
    set_input(); 
    for(int i = 0; i < k; i++){
        int idx = op[i].first; 
        int dir = op[i].second; 
        set_dir(idx, dir);  
        for(int j = 0; j < t; j++) rotate(arr[j]); 
    }
    cout << get_solve() << '\n'; 

    return 0; 
}