#include <bits/stdc++.h>
using namespace std; 

struct food{
  int p, f, s, v, c; 
}; 

const int INTMAX = 987654321; 
int n, mp, mf, ms, mv, mc = INTMAX; 
food arr[20]; 
string best_order; 

void solve(int num){
  food curr = {0, 0, 0, 0, 0}; 
  string curr_order; 
  for(int i = 0; i < n; i++){
    if(num & (1 << i)){
      curr.p += arr[i].p; 
      curr.f += arr[i].f; 
      curr.s += arr[i].s; 
      curr.v += arr[i].v; 
      curr.c += arr[i].c;  
      curr_order += to_string(i + 1) + ' '; 
    }
  }
  if(curr.p >= mp && 
    curr.f >= mf && 
    curr.s >= ms &&
    curr.v >= mv 
  ){
    if(curr.c < mc){
      mc = curr.c; 
      best_order = curr_order; 
    }else if(curr.c == mc){
      if(curr_order < best_order) best_order = curr_order;  
    }
  }  
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> n; 
  cin >> mp >> mf >> ms >> mv; 
  for(int i = 0; i < n; i++){
    food tmp; 
    cin >> tmp.p >> tmp.f >> tmp.s >> tmp.v >> tmp.c; 
    arr[i] = tmp; 
  }
  for(int i = 0; i < (1 << n); i++){
    solve(i); 
  }
  if(mc == INTMAX) cout << -1; 
  else{
    cout << mc << '\n'; 
    cout << best_order << '\n'; 
  }

  return 0; 
}
