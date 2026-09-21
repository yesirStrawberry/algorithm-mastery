#include <bits/stdc++.h>
using namespace std; 

int n, m; 
int arr[54][54], visited[54][54]; 
const int dy[] = {0, -1, 0, 1}; 
const int dx[] = {-1, 0, 1, 0}; 
int roomCnt, roomSize, mx; 

int dfs(int y, int x){
  int ret = 1; 
  visited[y][x] = 1; 
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i]; 
    int nx = x + dx[i]; 
    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
    if(visited[ny][nx]) continue; 
    if(arr[y][x] & (1 << i)) continue; 
    ret += dfs(ny, nx); 
  }
  return ret; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); 
  cin >> m >> n; 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j]; 
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(visited[i][j]) continue; 
      roomCnt++; 
      roomSize = max(roomSize, dfs(i, j)); 
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int k = 0; k < 4; k++){
        if(!(arr[i][j] & (1 << k))) continue; 
        arr[i][j] &= ~(1 << k);
        int ny = i + dy[k]; 
        int nx = j + dx[k]; 
        bool outRange = ny < 0 || ny >= n || nx < 0 || nx >= m; 
        if(!outRange){
          arr[ny][nx] &= ~(1 << ((k + 2) % 4)); 
        }
        fill(&visited[0][0], &visited[0][0] + 54*54, 0); 
        int cnt = dfs(i, j);
        mx = max(mx, cnt); 
        if(!outRange){
          arr[ny][nx] |= 1 << ((k + 2) % 4); 
        }
        arr[i][j] |= 1 << k;  
      }
    }
  }

  cout << roomCnt << '\n'; 
  cout << roomSize << '\n'; 
  cout << mx << '\n'; 

  return 0; 
}
