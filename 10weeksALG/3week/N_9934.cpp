#include <bits/stdc++.h>
using namespace std; 

int arr[1030]; 
vector<int> ret[14]; 

void go(int s, int e, int dep){
  if(s > e) return; 
  int mid = (s + e)/2; 
  ret[dep].push_back(arr[mid]); 
  go(s, mid - 1, dep + 1); 
  go(mid + 1, e, dep + 1); 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  int n; cin >> n; 
  int edge = (1 << n) - 1; 
  for(int i = 0; i < edge; i++){
    cin >> arr[i]; 
  }
  go(0, edge - 1, 0); 
  for(int i = 0; i < n; i++){
    for(int val : ret[i]) cout << val << ' '; 
    cout << '\n'; 
  }

  return 0; 
}
