#include <bits/stdc++.h> 
using namespace std; 

int visited[70][70], arr[70][70], arr_origin[70][70]; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 
int n, m; 

vector<array<int, 3>> v;  

void dfs(int y, int x){
  visited[y][x] = true; 
  arr[y][x] = 2; 
  
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i]; 
    int nx = x + dx[i]; 
    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
    if(visited[ny][nx]) continue; 
    if(arr[ny][nx] != 0) continue; 
    dfs(ny, nx); 
  }
}

void combi(int start, vector<int> b, const int sizeN, const int k){
  if(b.size() == k){
    array<int, 3> tri;  
    int idx = 0; 
    for(int i : b){
      if(arr_origin[i / m][i % m] != 0) return; 
      tri[idx++] = i;    
    }
    v.push_back(tri); 

    return; 
  }

  for(int i = start + 1; i < sizeN; i++){
    b.push_back(i); 
    combi(i, b, sizeN, k); 
    b.pop_back(); 
  }
}


int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  
  cin >> n >> m; 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr_origin[i][j]; 
    }
  }
  
  vector<int> b; 
  combi(-1, b, m*n, 3); 
  int mx = -1; 
  
  for(array<int, 3> tri : v){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = arr_origin[i][j]; 
        }
    }
    for(int i : tri){
      arr[i / m][i % m] = 1; 
    }
    fill(&visited[0][0], &visited[0][0] + 70*70, 0); 
    int cnt = 0; 
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(visited[i][j]) continue; 
        if(arr[i][j] != 2) continue; 
        dfs(i, j); 
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(arr[i][j] == 0) cnt++; 
      }
    }

    mx = mx < cnt ? cnt : mx; 
  }
  cout << mx; 
  return 0; 
}
