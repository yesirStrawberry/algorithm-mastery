#include <bits/stdc++.h>
using namespace std; 

int mx = INT_MIN; 
vector<int> numList; 
vector<char> opList; 

int cal(char op, int a, int b){
  switch(op){
    case '*' : return a*b; 
    case '+' : return a+b; 
    case '-' : return a-b;
    defalut : return -1;   
  }return -1;
}

int getVal(vector<int>& v){
  vector<int> newNumList; 
  vector<char> newOpList; 

  int idx = 0; 
  for(int i : v){
    int num = numList[idx];
    while(i > 1){
      num = cal(opList[idx], num, numList[idx + 1]); 
      idx++; i--; 
    } 
    newNumList.push_back(num);  
    if(idx < opList.size()) newOpList.push_back(opList[idx]); 
    idx++; 
  }
  int ret = newNumList[0]; 
  for(int i = 0; i < newOpList.size(); i++){
    ret =  cal(newOpList[i], ret, newNumList[i + 1]); 
  }
  return ret; 
}

void go(vector<int>& v){
  int curr = getVal(v); 
  mx = max(mx, curr); 
  for(int i = 0; i < v.size() - 1; i++){
    vector<int> nv; 
    for(int j = 0; j < v.size(); j++){
      if(i == j) continue; 
      nv.push_back(v[j]); 
    }
    nv[i] += v[i]; 
    if(nv[i] > 2) continue; 
    
    go(nv); 
  }  
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  int n; cin >> n; 
  int tmp_int; char tmp_char; 
  vector<int> v; 
  for(int i = 0; i < n; i++){
    if(i % 2 == 0){
      cin >> tmp_int; 
      numList.push_back(tmp_int); 
      v.push_back(1); 
    }else{
      cin >> tmp_char; 
      opList.push_back(tmp_char); 
    }
  }
  
  go(v); 
  cout << mx; 

  return 0; 
}
