#include <bits/stdc++.h>
using namespace std; 
const int INF = 987654321; 
vector<int> adj[10]; 
int n, sumA, sumB, mn = INF; 
int visited[10], arr[10];

int zeroCount(int num){
  if(num == 0) return 0; 
  int cnt = 0; 
  while(!(num & 1)){
    cnt++; 
    num >>= 1; 
  }
  return cnt; 
}

int dfs(int x, int bs, char c){
  int ret = 1; 
  visited[x] = 1; 
  c == 'a' ? sumA += arr[x] : sumB += arr[x]; 
  for(int nx : adj[x]){
    if(visited[nx]) continue; 
    if(!(bs & (1 << nx))) continue; 
    ret += dfs(nx, bs, c); 
  }
  return ret; 
}

int main(void){ 
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> n; 
  for(int i = 0; i < n; i++) cin >> arr[i]; 
  int adj_cnt; 
  for(int i = 0; i < n; i++){
    cin >> adj_cnt; 
    int tmp; 
    for(int j = 0; j < adj_cnt; j++){
      cin >> tmp; 
      adj[i].push_back(tmp - 1); 
    }
  }
  int sa, sb; 
  for(int bs = 1; bs < (1 << n) - 1; bs++){
    sumA = sumB = 0; 
    memset(&visited, 0, sizeof(visited)); 
    sa = zeroCount(bs & -bs); 
    sb = zeroCount(~bs & -(~bs)); 
    if(dfs(sa, bs, 'a') +  dfs(sb, ~bs, 'b') == n)
      mn = min(abs(sumA - sumB), mn);     
  }
  if(mn == INF) cout << -1; 
  else cout << mn; 

  return 0; 
}
