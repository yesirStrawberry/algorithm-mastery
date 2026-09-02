#include <bits/stdc++.h>
using namespace std; 

int visited[100004], route[100004]; 

int move(int x, int op){
  if(op == 1) return x + 1; 
  else if(op == -1) return x - 1; 
  else return 2*x; 
}

void bfs(int sx, int e){
  queue<int> q; 
  int nx, cnt = 0, fastest; 
  bool flag = false; 
  visited[sx] = 1;  
  route[sx] = 1; 
  q.push(sx);
  while(!q.empty()){
    int x = q.front(); 
    q.pop(); 
    if(x == e) flag = true; 
    if(flag) continue; 
    int dep = visited[x] + 1; 
    for(int i : {1, -1, 2}){
      nx = move(x, i); 
      if(nx < 0 || nx > 100000) continue; 
      if(visited[nx] == dep) route[nx] += route[x]; 
      if(visited[nx]) continue; 
      visited[nx] = dep; 
      route[nx] = route[x]; 
      q.push(nx); 
    }
  }
}

int main(void){
  int s, e; 
  cin >> s >> e; 
  bfs(s, e); 
  cout << visited[e] - 1 << '\n' << route[e] << '\n'; 

  return 0; 
}
