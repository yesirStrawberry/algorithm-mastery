#include <bits/stdc++.h>
using namespace std; 

char arr[4][4];
int n, m, mx = -1;  
int op, visited, bs, edge; 

int zeros(int x){
  int cnt = 0; 
  if(x == 0) return cnt;
  while(!(x & 1)){
    cnt++; 
    x >>= 1; 
  } 
  return cnt; 
}

string dfs(int x){
  visited |= x; 
  int z = zeros(x); 
  string ret = ""; 
  ret += arr[z / m][z % m]; 
  int nx; 
  if(op) nx = x << m; 
  else nx = x << 1; 
  if(nx >= edge) return ret; 
  if(nx & visited) return ret; 
  if((nx & bs) != 0 && op == 0) return ret;
  if((nx & bs) == 0 && op != 0) return ret; 
  if(op == 0 && (z / m) != ((z + 1) / m)) return ret; 
  ret += dfs(nx);  
  return ret; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); 
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j]; 
    }
  } 
  edge = 1 << (n * m); 
  for(bs = 0; bs < edge; bs++){
    int sum = 0; 
    visited = 0; 
    for(int x = 1; x < edge; x *= 2){
      if(visited & x) continue; 
      op = x & bs; 
      sum += stoi(dfs(x)); 
    }
    mx = mx < sum ? sum : mx; 
  }
  cout << mx; 

  return 0; 
}
