#include <bits/stdc++.h>
using namespace std; 

char arr[54][54]; 
int visited[54][54]; 
int n, m, mx = -1; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 

int bfs(int sy, int sx){
  fill(&visited[0][0], &visited[0][0] + 54*54, 0); 
  queue<pair<int, int>> q;
  int y, x, ny, nx, last;  
  visited[sy][sx] = 1; 
  q.push({sy, sx}); 
  while(!q.empty()){
    tie(y, x) = q.front(); 
    q.pop(); 
    for(int i = 0; i < 4; i++){
      ny = y + dy[i]; 
      nx = x + dx[i]; 
      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
      if(visited[ny][nx]) continue;
      if(arr[ny][nx] != 'L') continue; 
      last = visited[y][x] + 1; 
      visited[ny][nx] = last;
      q.push({ny, nx});  
    }
  }
  return last - 1; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> n >> m; 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j]; 
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(arr[i][j] != 'L') continue; 
      mx = max(mx, bfs(i, j)); 
    }
  }
  cout << mx; 

  return 0; 
}
