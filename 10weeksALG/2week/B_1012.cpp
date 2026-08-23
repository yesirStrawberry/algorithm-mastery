#include <bits/stdc++.h>
using namespace std; 

int visited[54][54], arr[54][54]; 
int n, m; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 

void dfs(int y, int x){
    visited[y][x] = true; 
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
        if(visited[ny][nx]) continue; 
        if(arr[ny][nx] == 0) continue; 
        dfs(ny, nx); 
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t; 
    while(t--){
        int k, cnt = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited)); 
        cin >> m >> n >> k; 
        while(k--){
            int y, x; 
            cin >> x >> y; 
            arr[y][x] = 1; 
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j]) continue; 
                if(arr[i][j] == 0) continue; 
                cnt++; 
                dfs(i, j); 
            }
        }
        cout << cnt << '\n'; 
    }
    return 0; 
}
