#include <bits/stdc++.h>
using namespace std; 

int arr[104][104], n, m, k, mn = 987654321; 
struct tri{
    int a, b, c; 
}; 
vector<tri> v; 
int visited[10]; 

void rotate(tri t, int arr[104][104]){
    int r = t.a, c = t.b, s = t.c; 
    int i, j, prev; 
    while(s > 0){
        int sy = r - s, sx = c - s; 
        int ey = r + s, ex = c + s; 
        int tmp = arr[sy][sx]; 
        int i = sy; j = sx;
        for(; i < ey; i++) arr[i][j] = arr[i + 1][j]; 
        for(; j < ex; j++) arr[i][j] = arr[i][j + 1]; 
        for(; i > sy; i--) arr[i][j] = arr[i - 1][j]; 
        for(; j > sx; j--) arr[i][j] = arr[i][j - 1]; 
        arr[sy][sx + 1] = tmp;  
        s--; 
    }
}

int getMin(int arr[104][104]){
    int ret = 987654321; 
    for(int i = 0; i < n; i++){
        int sum = 0; 
        for(int j = 0; j < m; j++) sum += arr[i][j]; 
        ret = ret < sum ? ret : sum; 
    }
    return ret; 
}

void go(int dep, int arr[104][104]){
    if(dep == k){
        mn = min(mn, getMin(arr)); 
        return; 
    }
    int nxt[104][104]; 
    for(int i = 0; i < k; i++){
        if(visited[i]) continue;
        visited[i] = 1; 
        memcpy(nxt, arr, sizeof(nxt)); 
        rotate(v[i], nxt); 
        go(dep + 1, nxt);
        visited[i] = 0;  
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n >> m >> k; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> arr[i][j]; 
    }
    int a, b, c; 
    for(int i = 0; i < k; i++){
        cin >> a >> b >> c; 
        v.push_back({a - 1, b - 1, c}); 
    }
    go(0, arr); 
    cout << mn << '\n'; 
    return 0; 
}