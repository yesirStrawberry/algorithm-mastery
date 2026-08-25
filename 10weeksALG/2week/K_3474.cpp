#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t; cin >> t; 
  while(t--){
    ll cnt = 0, n; 
    cin >> n; 
    for(ll val = n / 5; val > 0; val /= 5) cnt += val; 
    cout << cnt << '\n'; 
  }

  return 0; 
}
