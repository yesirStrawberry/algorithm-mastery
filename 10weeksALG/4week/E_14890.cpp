#include <bits/stdc++.h>
using namespace std; 

int arr[104][104], arrC[104][104], slide[104][104], visited[104][104]; 
int N, L; 

void setSlide(int arr[104][104]){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N - L; j++){
      bool flagU = true, flagD = true; 
      int k;
      for(k = j; k < j + L; k++){
        if(visited[i][k] || arr[i][j] != arr[i][k]) flagU = false; 
      }
      if(arr[i][j] + 1 != arr[i][k]) flagU = false; 
      for(k = j + 1; k <= j + L; k++){
        if(visited[i][k] || arr[i][j] - 1 != arr[i][k]) flagD = false; 
      }
      if(flagU || flagD){
        slide[i][j] = 1; 
        if(flagU){
          for(k = j; k < j + L; k++) visited[i][k] = true; 
        }else if(flagD){
          for(k = j + 1; k <= j + L; k++) visited[i][k] = true; 
        }
      }
    }
  }
}

int move(int arr[104][104]){
  int ret = 0; 
  for(int i = 0; i < N; i++){
    int curr = 0; 
    while(curr < N - 1){
      if(slide[i][curr]) curr += L; 
      else if(arr[i][curr] == arr[i][curr + 1]) curr += 1; 
      else break; 
    }
    if(curr == N - 1) ret++;
  }
  return ret; 
}

int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
  cin >> N >> L; 
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> arr[i][j]; 
      arrC[j][i] = arr[i][j]; 
    }
  }
  setSlide(arr);
  int row = move(arr);   
  memset(slide, 0, sizeof(slide)); 
  memset(visited, 0, sizeof(visited)); 
  setSlide(arrC); 
  int col = move(arrC); 
  cout << row + col; 

  return 0; 
}
