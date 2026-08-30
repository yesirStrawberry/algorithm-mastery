#include <bits/stdc++.h>
using namespace std; 
int n, m, mn = 1e8; 
int arr[54][54], visited[54][54]; 
vector<pair<int, int>> chickens; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 

int bfs(int sy, int sx); 
int solve(vector<int> b); 
void combi(int start, vector<int> b, const int n, const int k); 

int main(void){
  cin >> n >> m;
  int temp;  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> temp; 
      if(temp == 2){
        chickens.push_back({i, j}); 
        temp = 0; 
      }
      arr[i][j] = temp; 
    }
  }
  
  vector<int> b; 
  combi(-1, b, chickens.size(), m); 
  cout << mn << '\n'; 

  return 0; 
}

void combi(int start, vector<int> b, const int n, const int k){
  if(b.size() == k){
    mn = min(mn, solve(b)); 
    return; 
  }
  for(int i = start + 1; i < n; i++){
    b.push_back(i);
    combi(i, b, n, k); 
    b.pop_back(); 
  }
}

int solve(vector<int> b){
  for(int idx : b){
    auto [y, x] = chickens[idx]; 
    arr[y][x] = 2; 
  }

  int sum = 0; 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(arr[i][j] != 1) continue; 
      fill(&visited[0][0], &visited[0][0] + 54*54, 0); 
      sum += bfs(i, j); 
    }
  }
  for(int idx : b){
    auto [y, x] = chickens[idx]; 
    arr[y][x] = 0; 
  }
  return sum; 
}

int bfs(int sy, int sx){
  queue<pair<int, int>> q; 
  q.push({sy, sx}); 
  visited[sy][sx] = 1; 
  while(!q.empty()){
    auto [y, x] = q.front(); 
    q.pop(); 
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i]; 
      int nx = x + dx[i]; 
      if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue; 
      if(visited[ny][nx]) continue; 
      if(arr[ny][nx] == 2) return visited[y][x]; 
      visited[ny][nx] = visited[y][x] + 1; 
      q.push({ny, nx}); 
    }
  }
  return -1; 
}
