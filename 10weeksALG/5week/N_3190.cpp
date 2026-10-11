#include <bits/stdc++.h>
using namespace std; 

int t, n, k, l, sk_board[104][104], apple[104][104]; 
int idx = 1; 
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}; 
char chg[10004]; 
deque<pair<int, int>> sk; 

void setInput(){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    cin >> k;
    int y, x; 
    for(int i = 0; i < k; i++){
        cin >> y >> x; 
        apple[y - 1][x - 1] = 1; 
    }
    cin >> l; 
    char c; 
    for(int i = 0; i < l; i++){
        cin >> x >> c; 
        chg[x] = c; 
    }
}

pair<int, int> getNext(pair<int, int> p){
    int y = p.first, x = p.second; 
    int ny = y + dy[idx]; 
    int nx = x + dx[idx]; 

    if(chg[t] == 'L') idx = (idx - 1 + 4) % 4; 
    else if(chg[t] == 'D') idx = (idx + 1) % 4; 
    
    return {ny, nx}; 
}

int main(void){
    setInput(); 
    
    sk.push_back({0, 0}); 
    sk_board[0][0] = 1; 
    int ny, nx; 
    while(1){
        t++;  
        tie(ny, nx) = getNext(sk[0]); 
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) break; 
        if(sk_board[ny][nx]) break;

        if(apple[ny][nx]){
            apple[ny][nx] = 0; 
        }else{
            int py, px; 
            tie(py, px) = sk.back(); 
            sk_board[py][px] = 0; 
            sk.pop_back(); 
        }
        sk_board[ny][nx] = 1;  
        sk.push_front({ny, nx}); 
    }
    cout << t << '\n'; 

    return 0; 
}