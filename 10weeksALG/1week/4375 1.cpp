#include <bits/stdc++.h>
using namespace std; 

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  
  int n; 
  int prev, next; 
  while(cin >> n){
    int cnt = 1;
    prev = 1 % n; 
    while(prev != 0){
      next =  (prev * 10 + 1) % n; 
      cnt++; 
      prev = next; 
    }
    cout << cnt << '\n'; 
  }

  return 0; 
}
