#include <bits/stdc++.h>
using namespace std; 

int n, m, mx = -1; 
int arr[24][24], visited[30]; 
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}; 

void dfs(int y, int x, int dep){
  mx = max(mx, dep); 
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i]; 
    int nx = x + dx[i]; 
    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
    int next_alp = arr[ny][nx] - 'A';  
    if(visited[next_alp]) continue; 
    visited[next_alp] = 1; 
    dfs(ny, nx, dep + 1); 
    visited[next_alp] = 0; 
  }
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> n >> m; 
  for(int i = 0; i < n; i++){
    string row; 
    cin >> row; 
    for(int j = 0; j < m; j++){
      arr[i][j] = row[j]; 
    }
  }

  visited[arr[0][0] - 'A'] = 1; 
  dfs(0, 0, 1); 

  cout << mx; 

  return 0; 
}
