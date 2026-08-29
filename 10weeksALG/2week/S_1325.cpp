#include <bits/stdc++.h>
using namespace std; 
#define N 10004

int visited[N]; 
map<int, vector<int>> mp; 
vector<int> adj[N]; 

int dfs(int x){
  visited[x] = true; 
  int ret = 1; 
  for(int nx : adj[x]){
    if(visited[nx]) continue; 
    ret += dfs(nx); 
  }
  return ret; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 

  int n, m, a, b, cnt, mx; 
  cin >> n >> m; 
  while(m--){
    cin >> a >> b; 
    adj[b].push_back(a); 
  }
  mx = -1; 
  for(int i = 1; i <= n; i++){
    fill(&visited[0], &visited[0] + N, 0); 
    cnt = dfs(i); 
    mx = mx < cnt ? cnt : mx; 
    mp[cnt].push_back(i); 
  }
  for(int val : mp[mx]) cout << val << ' '; 

  return 0; 
}
