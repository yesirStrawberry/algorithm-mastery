#include <bits/stdc++.h>
using namespace std; 

int nxt[40], shortcut[40], score[40], visited[40]; 
int mx;
int piece[4];  
int arr[10]; 

void init_board(){
    for(int i = 0; i <= 20; i++){
        nxt[i] = i + 1;
        score[i] = 2 * i;  
    }
    nxt[21] = 21; 
    score[21] = 0; 

    shortcut[5] = 22; 
    nxt[22] = 23; score[22] = 13; 
    nxt[23] = 24; score[23] = 16; 
    nxt[24] = 30; score[24] = 19; 

    shortcut[10] = 25; 
    nxt[25] = 26; score[25] = 22; 
    nxt[26] = 30; score[26] = 24; 

    shortcut[15] = 27; 
    nxt[27] = 28; score[27] = 28; 
    nxt[28] = 29; score[28] = 27; 
    nxt[29] = 30; score[29] = 26; 
    
    nxt[30] = 31; score[30] = 25; 
    nxt[31] = 32; score[31] = 30; 
    nxt[32] = 20; score[32] = 35; 
}

int move_piece(int x, int n){
    if(shortcut[x]){
        x = shortcut[x]; 
        n--; 
    }
    while(n--){
        x = nxt[x];
    }  
    return x; 
}

void go(int sum, int dep){
    if(dep == 10){
        mx = max(mx, sum); 
        return;
    }
    for(int i = 0; i < 4; i++){
        if(piece[i] == 21) continue;
        int np = move_piece(piece[i], arr[dep]); 
        if(np != 21 && visited[np]) continue; 
        int prev = piece[i];
        visited[np] = 1; 
        visited[prev] = 0; 
        piece[i] = np; 
        go(sum + score[np], dep + 1); 
        visited[prev] = 1; 
        visited[np] = 0;
        piece[i] = prev;  
    }
}

int main(void){
    init_board(); 
    for(int i = 0; i < 10; i++) cin >> arr[i]; 
    go(0, 0); 
    cout << mx << '\n'; 
    return 0; 
}