#include <bits/stdc++.h>
using namespace std; 

int n, m; 
string s; 
int ret[104][104]; 

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  
  cin >> n >> m; 
  for(int i = 0; i < n; i++){
    cin >> s;
    int p = -1;  
    for(int j = 0; j < m; j++){
      if(s[j] == 'c') p = 0; 
      else if(p != -1) p++; 
      ret[i][j] = p;  
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << ret[i][j] << " "; 
    }cout << '\n'; 
  }

  return 0; 
}
