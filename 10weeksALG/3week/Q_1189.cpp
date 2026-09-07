#include <bits/stdc++.h>
using namespace std; 

int n, m, k; 
char arr[10][10]; 
int visited[10][10]; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 
int cnt = 0; 
int ey, ex; 

void dfs(int y, int x, int dep){
  if(dep == k){
    if(y == ey && x == ex) cnt++; 
    return; 
  }
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i]; 
    int nx = x + dx[i]; 
    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
    if(visited[ny][nx]) continue;
    if(arr[ny][nx] == 'T') continue; 
    visited[ny][nx] = 1; 
    dfs(ny, nx, dep + 1); 
    visited[ny][nx] = 0;
  }
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> n >> m >> k; 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> arr[i][j]; 
  }
  ey = 0; ex = m - 1; 
  visited[n - 1][0] = 1; 
  dfs(n - 1, 0, 1); 
  cout << cnt; 

  return 0; 
}
