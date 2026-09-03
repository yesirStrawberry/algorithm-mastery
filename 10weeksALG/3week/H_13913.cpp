#include <bits/stdc++.h>
using namespace std; 

int visited[100004], from[100004]; 

void bfs(int s, int e){
  int x; 
  queue<int> q; 
  visited[s] = 1;
  from[s] = -1;  
  q.push(s); 
  while(!q.empty()){
    x = q.front(); q.pop(); 
    if(x == e) break; 
    for(int nx : {x + 1, x - 1, 2 * x}){
      if(nx < 0 || nx > 100000) continue; 
      if(visited[nx]) continue; 
      visited[nx] = visited[x] + 1; 
      from[nx] = x; 
      q.push(nx);  
    }
  }
  return; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  int s, e; 
  cin >> s >> e; 
  bfs(s, e); 
  
  string ret; 
  int curr = e; 
  while(curr != -1){
    ret = to_string(curr) + " " + ret; 
    curr = from[curr];  
  }

  cout << visited[e] - 1 << '\n'; 
  cout << ret; 

  return 0; 
}
