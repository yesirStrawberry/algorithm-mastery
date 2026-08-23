#include <bits/stdc++.h>
using namespace std;

int arr[104][104], visited[104][104];
int n, m; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 

int dfs(int y, int x){
    visited[y][x] = true; 
    int ret = 1;  
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
        if(visited[ny][nx]) continue; 
        if(arr[ny][nx] == 1) continue; 
        ret += dfs(ny, nx); 
    }
    return ret; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m; 
    int k; cin >> k; 
    
    int sy, sx, ey, ex; 
    while(k--){
        cin >> sx >> sy >> ex >> ey; 
        for(int i = sy; i < ey; i++){
            for(int j = sx; j < ex; j++){
                arr[i][j] = 1; 
            }
        }
    }
    
    vector<int> ret; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j]) continue; 
            if(arr[i][j] == 1) continue; 
            ret.push_back(dfs(i, j)); 
        }
    }
    
    sort(ret.begin(), ret.end()); 
    cout << ret.size() << '\n'; 
    for(int val : ret) cout << val << " "; 
    
    return 0; 
}
