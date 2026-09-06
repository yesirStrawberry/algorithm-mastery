#include <bits/stdc++.h>
using namespace std; 

int arr[34][14]; 
int ret = -1; 
int n, m, h; 

void solve(vector<pair<int, int>> v);
void combi(int start, vector<pair<int, int>> v, const int edge, const int k);

int main(void){ 
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> n >> m >> h; 
  int y, x; 
  while(m--){
    cin >> y >> x; 
    arr[y - 1][x - 1] = 1; 
  }
  for(int k = 0; k <= 3; k++){
    vector<pair<int, int>> v; 
    combi(-1, v, n*h, k); 
    if(ret != -1) break; 
  }
  cout << ret; 

  return 0; 
}

void combi(int start, vector<pair<int, int>> v, const int edge, const int k){
  if(v.size() == k){
    solve(v); 
    return; 
  }
  int y, x; 
  for(int i = start + 1; i < edge; i++){
    y = i / n; 
    x = i % n; 
    if(x == n - 1) continue; 
    if(arr[y][x] == 1) continue; 
    if(x != 0 && arr[y][x - 1] == 1) continue; 
    if(arr[y][x + 1] == 1) continue; 
    v.push_back({y, x}); 
    arr[y][x] = 1; 
    combi(i, v, edge, k); 
    v.pop_back(); 
    arr[y][x] = 0; 
  }
}

void solve(vector<pair<int, int>> v){
  int flag = true; 
  
  for(int origin = 0; origin < n; origin++){
    int move = origin; 
    for(int dep = 0; dep < h; dep++){
      if(arr[dep][move] == 1) move++; 
      else if(move != 0 && arr[dep][move - 1] == 1) move--;
    }
    if(move != origin) flag = false; 
  }
  if(flag) ret = v.size(); 
}
