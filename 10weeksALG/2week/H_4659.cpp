#include <bits/stdc++.h>
using namespace std; 

bool vowelCheck(char c){
    for(char temp : "aeiou"){
        if(temp == c) return true; 
    }return false; 
}

int main(void){
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); cout.tie(nullptr); 
  string s; 
  while(cin >> s){
    if(s == "end") break;
    bool flag = true; 
    bool oneVowel = false; 

    int prev = -1, vcnt = 0, lcnt = 0; 
    for(int c : s){
      if(vowelCheck(c)){
        vcnt++; lcnt = 0; 
        oneVowel = true; 
      } 
      else {
        lcnt++; vcnt = 0; 
      }
      if(vcnt == 3 || lcnt == 3) flag = false;
      if(prev == c && c != 'e' && c != 'o') flag = false; 

      prev = c; 
    }
    if(!oneVowel) flag = false; 
    if(flag) cout << "<" << s << "> is acceptable." << '\n'; 
    else cout << "<" << s << "> is not acceptable." << '\n'; 
  }
  
  return 0; 
}
