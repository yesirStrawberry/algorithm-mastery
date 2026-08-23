#include <bits/stdc++.h>
using namespace std; 

int n, m; 
int visited[104][104], arr[104][104]; 
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1}; 

void bfs(int sy, int sx){
    queue<pair<int, int>> q; 
    q.push({sy, sx}); 
    visited[sy][sx] = 1; 
    
    while(q.size()){
        int y, x; 
        tie(y, x) = q.front(); 
        q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
            if(visited[ny][nx]) continue; 
            if(arr[ny][nx] == 0) continue; 
            
            visited[ny][nx] = visited[y][x] + 1; 
            q.push({ny, nx}); 
        }
    }
}

int main(void){
    string s; 
    cin >> n >> m; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        for(int j = 0; j < m; j++){
            if(s[j] == '1') arr[i][j] = 1; 
            else arr[i][j] = 0; 
        }
    }
    
    bfs(0, 0); 
    
    cout << visited[n - 1][m - 1]; 
    
    return 0; 
}
