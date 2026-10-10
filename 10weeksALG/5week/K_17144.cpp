#include <bits/stdc++.h>
using namespace std; 
#define SWAP(prev, i, j) do{int curr = arr[i][j]; arr[i][j] = prev; prev = curr; } while(false)  

int n, m, t, arr[54][54], nxt[54][54]; 
int ay, ax, by, bx, cnt; 
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}; 

void setInput(); 
void spread(); 
void circulate(int fil, int cil); 
int getRet(); 

int main(void){
    setInput(); 
    for(int i = 0; i < t; i++){
        spread(); 
        circulate(ay, by); 
    }
    cout << getRet() << '\n'; 
    return 0; 
}

void setInput(){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n >> m >> t; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1){
                if(cnt == 0){
                    ay = i; ax = j; cnt++;  
                }else{
                    by = i; bx = j; 
                }
            }
        }  
    }
}
 
void spread(){
    fill(&nxt[0][0], &nxt[0][0] + 54*54, 0); 
    nxt[by][bx] = -1; 
    nxt[ay][ax] = -1; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] <= 0) continue; 
            int cnt = 0; 
            int nm = arr[i][j] / 5; 
            for(int k = 0; k < 4; k++){
                int ny = i + dy[k]; 
                int nx = j + dx[k]; 
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
                if(arr[ny][nx] == -1) continue; 
                nxt[ny][nx] += nm; 
                cnt++; 
            }
            nxt[i][j] += arr[i][j] - (cnt * nm); 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = nxt[i][j]; 
        }
    }
}

void circulate(int fil, int cil){
    int prev = 0, i = fil, j = 1, curr; 
    for(; j < m - 1; j++) SWAP(prev, i, j); 
    for(; i > 0; i--) SWAP(prev, i, j);
    for(; j > 0; j--) SWAP(prev, i, j);
    for(; i < fil; i++) SWAP(prev, i, j);
    prev = 0; i = cil; j = 1; 
    for(; j < m - 1; j++) SWAP(prev, i, j); 
    for(; i < n - 1; i++) SWAP(prev, i, j); 
    for(; j > 0; j--) SWAP(prev, i, j); 
    for(; i > cil; i--) SWAP(prev, i, j);
}

int getRet(){
    int ret = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != -1) ret += arr[i][j];  
        }
    }
    return ret; 
}