#include <bits/stdc++.h>
using namespace std; 

int x, cnt; 

int main(void){
  cin >> x; 
  for(int i = 1; i <= (1 << 6); i *= 2){
    if(i & x) cnt++; 
  }
  cout << cnt; 

  return 0; 
}
