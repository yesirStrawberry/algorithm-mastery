#include <bits/stdc++.h>
using namespace std; 

bool cmp(const string& a, const string& b){
  if(a.size() == b.size()){
    for(int i = 0; i < a.size(); i++){
      if(a[i] == b[i]) continue; 
      return a[i] < b[i]; 
    }
  }
  return a.size() < b.size(); 
}

string parse(string s){
  if(s.size() == 1) return s; 
  if(s[0] == '0'){
    int i; 
    for( i = 0; i < s.size(); i++){
      if(s[i] != '0') break; 
    }
    if(i == s.size()) return "0"; 
    return s.substr(i);
  }  
  return s; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr);
 
  int n; 
  string s;
  vector<string> v;  
  cin >> n; 
  while(n--){
    cin >> s; 
    // cout << "s : " << s << '\n'; // 
    string snum = ""; 
    for(int i = 0; i < s.size(); i++){
      // cout << "--------------" << '\n'; 
      // cout << "c : " << s[i] << '\n'; //
      char c = s[i]; 
      if('0' <= c && c <= '9'){
        snum += c;
        if(i + 1 == s.size()) v.push_back(parse(snum));  
      }else{
        if(snum.size() == 0) continue; 
        v.push_back(parse(snum)); 
        snum = ""; 
      }

      // cout << "snum : " << snum << '\n'; 
      // cout << "v : ";
      // for(string s : v) cout << s << ' '; //
      // cout << '\n';
    }
  }

  sort(v.begin(), v.end(), cmp); 
  for(string s : v) cout << s << '\n'; 

  return 0; 
}
