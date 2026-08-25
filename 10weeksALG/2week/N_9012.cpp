#include <bits/stdc++.h> 
using namespace std; 

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  
  int n; cin >> n;
  string s; 
  while(n--){
    cin >> s;
    stack<char> st;  
    for(char c : s){
      if(st.size() == 0) st.push(c); 
      else if(st.top() == '(' && c == ')') st.pop(); 
      else st.push(c); 
    }
    if(st.size() == 0) cout << "YES" << '\n'; 
    else cout << "NO" << '\n'; 
  } 

  return 0; 
}
