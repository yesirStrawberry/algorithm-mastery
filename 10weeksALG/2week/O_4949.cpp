#include <bits/stdc++.h> 
using namespace std; 

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  
  string s; 
  while(true){
    getline(cin, s);
    if(s == ".") break; 

    stack<char> st;  
    for(char c : s){
      if(c != '[' && c != ']' && c != '(' && c != ')') continue; 
      if(st.size() == 0) st.push(c); 
      else if(st.top() == '[' && c == ']') st.pop(); 
      else if(st.top() == '(' && c == ')') st.pop(); 
      else st.push(c); 
    }
    if(st.size() == 0) cout << "yes" << '\n'; 
    else cout << "no" << '\n'; 
  } 

  return 0; 
}
