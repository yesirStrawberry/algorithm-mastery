#include <bits/stdc++.h>
using namespace std; 

int n, L, R; 
int visited[54][54], arr[54][54]; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 

int dfs(int y, int x, vector<pair<int, int>>& v){
  visited[y][x] = true; 
  v.push_back({y, x}); 
  int ret = arr[y][x]; 
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i]; 
    int nx = x + dx[i]; 
    if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue; 
    if(visited[ny][nx]) continue; 
    int dif = abs(arr[ny][nx] - arr[y][x]); 
    if(dif < L || R < dif) continue; 
    ret += dfs(ny, nx, v); 
  }
  return ret; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> n >> L >> R; 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> arr[i][j]; 
    }
  }
  
  int moveCnt = 0; 
  while(true){
    int cnt = 0; 
    fill(&visited[0][0], &visited[0][0] + 54*54, 0); 
    vector<vector<pair<int, int>>> vList; 
    vector<int> valList; 
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(visited[i][j]) continue; 
        vector<pair<int, int>> v; 
        int sum = dfs(i, j, v); 
        int val = sum/v.size(); 
        vList.push_back(v); 
        valList.push_back(val); 
      }
    }
    for(int i = 0; i < vList.size(); i++){
      int val = valList[i]; 
      for(auto [y, x] : vList[i]) arr[y][x] = val; 
    }

    if(vList.size() == n*n) break; 
    moveCnt++; 
  }

  cout << moveCnt; 

  return 0; 
}
