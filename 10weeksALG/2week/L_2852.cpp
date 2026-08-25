#include <bits/stdc++.h>
using namespace std; 

pair<int, int> arr[104]; 

int getIntTime(string s){
  int pos = s.find(':'); 
  string min = s.substr(0, pos); 
  string sec = s.substr(pos + 1, string::npos);
  return stoi(min)*60 + stoi(sec); 
}

string parse(int n){
  if(n == 0) return "00"; 
  else if(n < 10) return "0" + to_string(n); 
  return to_string(n); 
}

string getStringTime(int time){
  string ret = ""; 
  ret += parse(time / 60); 
  ret += ":"; 
  ret += parse(time % 60); 
  return ret; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  int n; cin >> n; 
  int team; string s; 
  for(int i = 0; i < n; i++){
    cin >> team >> s; 
    arr[i] = {team, getIntTime(s)}; 
  }
  int idx = 0, score1 = 0, score2 = 0, time1 = 0, time2 = 0; 
  for(int t = 0; t < 48*60; t++){
    if(t == arr[idx].second){
      if(arr[idx].first == 1) score1++; 
      else score2++; 
      idx++; 
    }
    if(score1 > score2) time1++; 
    else if(score1 < score2) time2++; 
  }
  cout << getStringTime(time1) << '\n';
  cout << getStringTime(time2) << '\n'; 

  return 0; 
}
