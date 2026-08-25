#include <bits/stdc++.h>
using namespace std; 

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, cnt = 0, val = 0; 
  cin >> n; 
  
  while(cnt < n){
    val++; 
    if(to_string(val).find("666") != string::npos) cnt++;   
  }
  cout << val << '\n'; 

  return 0; 
}
