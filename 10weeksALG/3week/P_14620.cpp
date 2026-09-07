#include <bits/stdc++.h>
using namespace std; 

const int dy[] = {0, -1, 0, 1, 0}; 
const int dx[] = {0, 0, 1, 0, -1}; 
int n, edge,  mn = 987654321; 
int visited[14][14], arr[14][14]; 

int setFlower(int y, int x, int val){
  int price = 0; 
  for(int i = 0; i < 5; i++){
    int ny = y + dy[i]; 
    int nx = x + dx[i]; 
    visited[ny][nx] = val; 
    price += arr[ny][nx]; 
  }
  return price; 
}

bool check(int y, int x){
  if(y <= 0 || y >= n - 1 || x <= 0 || x >= n - 1) return false; 
  for(int i = 0; i < 5; i++){
    int ny = y + dy[i]; 
    int nx = x + dx[i]; 
    if(visited[ny][nx]) return false; 
  }
  return true; 
}

void combi(int start, int dep, int sum){
  if(dep == 3){
    mn  = min(sum, mn); 
    return; 
  }
  int y, x; 
  for(int i = 0; i < edge; i++){
    y = i / n; x = i % n; 
    if(!check(y, x)) continue; 
    int price = setFlower(y, x, 1); 
    combi(i, dep + 1, sum + price); 
    setFlower(y, x, 0); 
  }
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> n; 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> arr[i][j]; 
    }
  }
  edge = n * n; 
  combi(-1, 0, 0);  
  cout << mn; 
  return 0; 
}
