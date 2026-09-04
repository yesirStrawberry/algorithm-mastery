#include <bits/stdc++.h>
using namespace std; 

int visited[2][500004]; 

int bfs(int s, int e){
  queue<int> q; int turn = 0; 
  visited[turn % 2][s] = 1; 
  q.push(s); 
  while(!q.empty()){
    e += turn; 
    if(e > 500000) return -1; 
    if(visited[turn % 2][e]) break;
    int qSize = q.size(); 
    while(qSize--){
      int x = q.front(); q.pop(); 
      for(int nx : {x - 1, x + 1, 2*x}){
        if(nx < 0 || nx > 500000) continue; 
        if(visited[(turn + 1) % 2][nx]) continue; 
        visited[(turn + 1) % 2][nx] = visited[turn % 2][x] + 1; 
        q.push(nx); 
      }
    }
    turn++; 
  }
  return turn; 
}

int main(void){
  int s, e; 
  cin >> s >> e; 
  cout << bfs(s, e); 

  return 0; 
}
