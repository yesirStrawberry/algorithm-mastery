#include <bits/stdc++.h>
using namespace std; 

int arr[304][304], visited[304][304];
int n, m;  
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 

int bfs(int sy, int sx, int ey, int ex){
  queue<pair<int, int>> currQ, nextQ; 
  int y, x, ny, nx, turn = 0; 
  visited[sy][sx] = 1; 
  currQ.push({sy, sx}); 
  while(!currQ.empty()){
    turn++; 
    while(!currQ.empty()){
      tie(y, x) = currQ.front(); currQ.pop(); 
      for(int i = 0; i < 4; i++){
        ny = y + dy[i]; nx = x + dx[i]; 
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
        if(visited[ny][nx]) continue; 
        if(arr[ny][nx] != 0) nextQ.push({ny, nx}); 
        else currQ.push({ny, nx}); 
        visited[ny][nx] = 1; 
      }
    }
    if(visited[ey][ex]) break; 
    currQ = nextQ; 
  }
  return turn; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> n >> m; 
  int sy, sx, ey, ex; 
  string row; 
  cin >> sy >> sx >> ey >> ex; 
  for(int i = 0; i < n; i++){
    cin >> row; 
    for(int j = 0; j < m; j++){
      if(row[j] == '#' || row[j] == '*') arr[i][j] = 0; 
      else arr[i][j] = row[j] - '0'; 
    }
  }

  cout << bfs(--sy, --sx, --ey, --ex); 

  return 0; 
}
