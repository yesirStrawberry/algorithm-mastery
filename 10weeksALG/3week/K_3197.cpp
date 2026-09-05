#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}; 
int arr[1504][1504], visitedW[1504][1504], visitedB[1504][1504]; 
int n, m;  
queue<pair<int, int>> currWQ, currBQ, nextWQ, nextBQ;
vector<pair<int, int>> vB, vW; 

int bfs(pair<int, int> s, pair<int, int> e){
  int y, x, ny, nx, turn = 0; 
  visitedB[s.first][s.second] = 1; 
  currBQ.push(s); 
  int ey = e.first, ex = e.second; 

  while(true){
    while(!currBQ.empty()){ 
      tie(y, x) = currBQ.front(); currBQ.pop(); 
      for(int i = 0; i < 4; i++){
        ny = y + dy[i]; nx = x + dx[i]; 
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
        if(visitedB[ny][nx]) continue; 
        if(arr[ny][nx] == 1) nextBQ.push({ny, nx}); 
        else currBQ.push({ny, nx});
        visitedB[ny][nx] = 1;  
      }
    }
    if(visitedB[ey][ex]) break; 
    swap(currBQ, nextBQ); 
    while(!currWQ.empty()){
      tie(y, x) = currWQ.front(); currWQ.pop(); 
      for(int i = 0; i < 4; i++){
        ny = y + dy[i]; nx = x + dx[i]; 
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
        if(visitedW[ny][nx]) continue; 
        if(arr[ny][nx] == 1){
          nextWQ.push({ny, nx});
          arr[ny][nx] = 0; 
        }  
        else currWQ.push({ny, nx}); 
        visitedW[ny][nx] = 1; 
      }
    }
    swap(currWQ, nextWQ); 
    turn++; 
  }
  return turn; 
}


int main(void){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 

  cin >> n >> m; 
  string row; 
  for(int i = 0; i < n; i++){
    cin >> row; 
    for(int j = 0; j < m; j++){
      if(row[j] == 'X') arr[i][j] = 1; 
      else{
        arr[i][j] = 0; 
        if(row[j] == 'L') vB.push_back({i, j}); 
        visitedW[i][j] = 1; 
        currWQ.push({i, j}); 
      }
    }
  }

  cout << bfs(vB[0], vB[1]); 

  return 0; 
}
