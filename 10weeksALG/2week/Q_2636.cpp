#include <bits/stdc++.h>
using namespace std; 

const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 

int n, m, visited[104][104], arr[104][104]; 

void dfs(int y, int x){
  visited[y][x] = true; 
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i]; 
    int nx = x + dx[i];
    if(ny < 0  || ny >= n || nx < 0 || nx >= m) continue; 
    if(visited[ny][nx]) continue; 
    if(arr[ny][nx] != 0){
      arr[ny][nx] = 2; 
      continue; 
    }
    dfs(ny, nx); 
  }
}

int melt(){
  int cheeses = 0; 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(arr[i][j] != 0) cheeses++; 
      if(arr[i][j] == 2) arr[i][j] = 0; 
    }
  }
  return cheeses; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  
  cin >> n >> m; 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j]; 
    }
  }
  
  int cnt = 0; 
  int cheeses = melt(); 
  int prev = 0; 
  while(cheeses != 0){
    prev = cheeses; 
    dfs(0, 0); 
    cheeses = melt();
    cnt++; 
    fill(&visited[0][0], &visited[0][0]+104*104, 0); 
  }
  cout << cnt - 1 << '\n'; 
  cout << prev << '\n'; 

  return 0; 
}
