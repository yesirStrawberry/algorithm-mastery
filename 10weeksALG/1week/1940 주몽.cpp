#include <bits/stdc++.h>
using namespace std;
bool arr[100004]; 

int main(void){
  fill(arr, arr + 100004, false);
  int n, m, value, cnt = 0;  
  vector<int> v; 
  v.reserve(15000); 
  
  cin >> n; 
  cin >> m; 
  while(n--){
    cin >> value; 
    v.push_back(value); 
    arr[value] = true; 
  }

  for(int x : v){
    int y = m - x; 
    if(y <= 0 || y >= 100004 || x == y) continue; 
    
    if(arr[y]){
      cnt++; 
      arr[x] = arr[y] = false; 
    }
  }

  cout << cnt << '\n'; 

  return 0; 
}
