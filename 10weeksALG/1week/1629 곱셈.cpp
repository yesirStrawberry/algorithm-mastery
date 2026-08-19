#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main(void) {
  ll a, b, c; 
  ll arr[32]; 
  int bits[32]; 
  memset(bits, 0, sizeof(int)*32); 
  cin >> a >> b >> c; 

  arr[0] = a % c; 
  for(int i = 1; i < 32; i++){
    arr[i] = arr[i - 1]*arr[i - 1] % c; 
  }

  int cnt = 0; 
  while(b != 0){
    bits[cnt] = b % 2; 
    b /= 2; 
    cnt++; 
  }

  ll res = 1; 
  for(int i = 0; i < 32; i++){
    if(bits[i]){
      res = res * arr[i] % c; 
    }
  }

  cout << res; 

	return 0; 
}
