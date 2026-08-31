#include <bits/stdc++.h>
using namespace std; 

int arr[1004][1004], visited[1004][1004]; 
int n, m; 

const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 

void bfs_fire(int fy, int fx); 
int bfs_jihun(int jy, int jx); 

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  vector<pair<int, int>> fireList; 
  cin >> n >> m; 
  string s;  
  int jy, jx; 
  for(int i = 0; i < n; i++){
    cin >> s; 
    for(int j = 0; j < m; j++){ 
      if(s[j] == '#') arr[i][j] = -1; 
      else{
        if(s[j] == 'J') tie(jy, jx) = {i , j};  
        else if(s[j] == 'F') fireList.push_back({i, j}); 
        arr[i][j] = 0; 
      }
    }
  }

  for(auto [fy, fx] : fireList) bfs_fire(fy, fx); 
  
  int res = bfs_jihun(jy, jx);
  if(res) cout << res; 
  else cout << "IMPOSSIBLE"; 

  return 0; 
}

void bfs_fire(int fy, int fx){
  queue<pair<int, int>> q; 
  int y, x, ny, nx, dep; 
  arr[fy][fx] = 1; 
  q.push({fy, fx}); 
  while(!q.empty()){
    tie(y, x) = q.front(); 
    q.pop(); 
    for(int i = 0; i < 4; i++){
      ny = y + dy[i]; 
      nx = x + dx[i]; 
      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
      if(arr[ny][nx] == -1) continue; 
      dep = arr[y][x] + 1;
      if(arr[ny][nx] != 0 && arr[ny][nx] <= dep) continue; 
      arr[ny][nx] = dep;  
      q.push({ny, nx}); 
    }
  }
}

int bfs_jihun(int jy, int jx){
  queue<pair<int, int>> q;
  int y, x, ny, nx, dep;  
  visited[jy][jx] = 1; 
  q.push({jy, jx}); 
  while(!q.empty()){
    tie(y, x) = q.front(); 
    q.pop(); 
    if(y == 0 || y == n - 1 || x == 0 || x == m - 1) return visited[y][x];  
    for(int i = 0; i < 4; i++){
      ny = y + dy[i]; 
      nx = x + dx[i]; 
      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
      if(arr[ny][nx] == -1) continue; 
      if(visited[ny][nx]) continue; 
      dep = visited[y][x] + 1; 
      if(arr[ny][nx] != 0 && arr[ny][nx] <= dep) continue; 
      visited[ny][nx] = dep; 
      q.push({ny, nx}); 
    }
  }
  return false; 
}
