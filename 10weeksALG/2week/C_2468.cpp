#include <bits/stdc++.h>
using namespace std; 

int t, n; 
int arr[104][104], visited[104][104]; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 

void dfs(int y, int x){
    visited[y][x] = true; 
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue; 
        if(visited[ny][nx]) continue; 
        if(arr[ny][nx] - t <= 0) continue; 
        
        dfs(ny, nx); 
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j]; 
        }
    }
    
    t = -1; 
    int max = -1; 
    while(t++ <= 100){
        memset(visited, 0, sizeof(visited));
        int cnt = 0; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) continue; 
                if(arr[i][j] - t <= 0) continue; 
                cnt++; 
                dfs(i, j); 
            }
        }
        max = max < cnt ? cnt : max; 
    }
    
    cout << max; 
    
    return 0; 
}
