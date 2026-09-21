#include <bits/stdc++.h>
using namespace std; 

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  int n; cin >> n; 
  string direction; 
  int idx; 
  int s = 0; 
  while(n--){
    cin >> direction; 
    if(direction == "add"){
      cin >> idx; 
      s |= (1 << --idx);
    }else if(direction == "remove"){
      cin >> idx; 
      s &= ~(1 << --idx); 
    }else if(direction == "check"){
      cin >> idx;
      if(s & (1 << --idx)) cout << 1 << '\n'; 
      else cout << 0 << '\n'; 
    }else if(direction == "toggle"){
      cin >> idx;
      s ^= (1 << --idx); 
    }else if(direction == "all"){
      s = 0x000fffff; 
    }else if(direction == "empty"){
      s = 0; 
    }
  }
  
  return 0; 
}
