#include <bits/stdc++.h>
using namespace std; 

int n, visited[10]; 
char opList[10];
string mx = "0000000000", mn = "9999999999";

void go(int idx, string num);
bool check(char a, char b, char op);

int main(void){
  cin >> n; 
  for(int i = 0; i < n; i++) cin >> opList[i]; 
  go(-1, ""); 
  cout << mx << '\n'; 
  cout << mn << '\n'; 

  return 0; 
}

void go(int idx, string num){
  if(num.size() == n + 1){
    mx = mx < num ? num : mx; 
    mn = mn > num ? num : mn; 
    return; 
  }
  for(int i = 0; i < 10; i++){
    if(visited[i]) continue; 
    char next = (char)(i + '0'); 
    if(idx != -1 && !check(num[idx], next, opList[idx])) continue; 
    visited[i] = 1; 
    go(idx + 1, num + next); 
    visited[i] = 0; 
  }
}

bool check(char a, char b, char op){
  if(a < b && op == '<') return true; 
  if(a > b && op == '>') return true; 
  return false; 
}
