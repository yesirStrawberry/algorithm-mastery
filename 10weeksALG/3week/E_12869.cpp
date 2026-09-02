#include <bits/stdc++.h>
using namespace std; 

int n; 
int visited[64][64][64]; 
const int dx[] = {-9, -9, -3, -3, -1, -1}; 
const int dy[] = {-3, -1, -9, -1, -9, -3}; 
const int dz[] = {-1, -3, -1, -9, -3, -9}; 

int bfs(int sx, int sy, int sz){
  queue<array<int, 3>> q; 
  int nx, ny, nz; 
  q.push({sx, sy, sz}); 
  visited[sx][sy][sz] = 1; 
  while(!q.empty()){
    auto [x, y, z] = q.front(); 
    q.pop(); 
    if(x == 0 && y == 0 && z == 0) return visited[x][y][z] - 1; 
    for(int i = 0; i < 6; i++){
      nx = max(x + dx[i], 0);  
      ny = max(y + dy[i], 0);  
      nz = max(z + dz[i], 0);  
      if(visited[nx][ny][nz]) continue; 
      visited[nx][ny][nz] = visited[x][y][z] + 1; 
      q.push({nx, ny, nz});
    }
  }
  return -1; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> n; 
  int arr[3] = {0, 0, 0}; 
  for(int i = 0; i < n; i++) cin >> arr[i]; 
  cout << bfs(arr[0], arr[1], arr[2]) << '\n'; 

  return 0; 
}
