#include <bits/stdc++.h>
using namespace std; 

int wordList[54]; 
int n, k, mx = -1; 
int ancti = 532741; 

void combi(int start, int bs, int dep){
  if(dep == k){
    int cnt = 0; 
    for(int i = 0; i < n; i++){
      int word = wordList[i]; 
      if((~word | bs) == -1) cnt++; 
    }
    mx = mx < cnt ? cnt : mx; 
    return; 
  }
  for(int i = start << 1; i < (1 << 26); i *= 2){
    if(i & ancti) continue; 
    bs |= i; 
    combi(i, bs, dep + 1); 
    bs &= ~i; 
  }
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); 
  cin >> n >> k; 
  if(k < 5){
    cout << 0; return 0; 
  }

  k -= 5; 
  string s; int word; 
  for(int i = 0; i < n; i++){
    cin >> s; word = 0; 
    for(int alp : s){
      int idx = 1 << (alp - 'a'); 
      if(idx & ancti) continue; 
      word |= idx; 
    }
    wordList[i] = word;
  }
  combi(1, 0, 0); 
  cout << mx; 

  return 0; 
}
