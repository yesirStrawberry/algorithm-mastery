#include <bits/stdc++.h>
using namespace std; 

int n, arr[25]; 
int mn = 987654321; 

void go(int dep){
  if(dep == n){
    int ret = 0; 
    for(int i = 1; i < (1 << n); i *= 2){
      int cnt = 0; 
      for(int j = 0; j < n; j++){
        if(arr[j] & i) cnt++; 
      }
      ret += min(cnt, n - cnt); 
    }
    mn = min(ret, mn); 
    return; 
  }
  go(dep + 1); 
  arr[dep] = ~arr[dep]; 
  go(dep + 1); 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n; 
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < n; j++){
      if(s[j] == 'T') arr[i] |= (1 << j); 
    }
  }
  go(0); 
  cout << mn; 

  return 0; 
}
