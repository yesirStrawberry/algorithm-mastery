#include <bits/stdc++.h>
using namespace std; 

pair<int, int> arr[1000004];
int n;   

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 

  cin >> n; 
  for(int i = 0; i < n; i++){
    cin >> arr[i].first; 
  }
  arr[n] = {-1, n}; 
  stack<int> st; 
  for(int i = n - 1; i >= 0; i--){
    int val = arr[i].first; 
    while(!st.empty() && val >= arr[st.top()].first) st.pop(); 
    if(st.empty()) arr[i].second = n; 
    else arr[i].second = st.top(); 
    st.push(i); 
  }

  for(int i = 0; i < n; i++){
    cout << arr[arr[i].second].first << ' '; 
  }

  return 0; 
}
