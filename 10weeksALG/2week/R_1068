#include <bits/stdc++.h>
using namespace std; 

vector<vector<int>> nodeList; 

int search(int idx){
  if(nodeList[idx].size() == 0){
    if(idx == 0) return 0; 
    else return 1; 
  }

  int ret = 0; 
  for(int child : nodeList[idx]){
    ret += search(child); 
  }
  return ret; 
}

void eraseDel(int del_idx){
  for(vector<int>& childList : nodeList){
    auto it = find(childList.begin(), childList.end(), del_idx); 
    if(it != childList.end()){
      childList.erase(it); 
    }
  }
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 

  int n, anc; cin >> n; 
  vector<int> childList; 
  nodeList.push_back(childList); 
  for(int curr = 0; curr < n; curr++){
    cin >> anc; 
    nodeList[anc + 1].push_back(curr + 1); 
    vector<int> childList; 
    nodeList.push_back(childList); 
  }
  int del_idx; 
  cin >> del_idx;
  eraseDel(del_idx + 1); 
 
  cout << search(0) << '\n';  

  return 0; 
}
