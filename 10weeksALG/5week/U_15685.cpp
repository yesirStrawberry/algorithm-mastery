#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 
const int board_size = 2500; 
const int dy[] = {0, -1, 0, 1}, dx[] = {1, 0, -1, 0};  
int n, arr[board_size + 4][board_size + 4]; 

void print_arr(){
    ofstream outFile("U_output.csv"); 
    for(int i = 0; i < board_size + 1; i++){
        for(int j = 0; j < board_size + 1; j++){
            outFile << arr[i][j]; 
            if(j < board_size) outFile << ","; 
        }  
        outFile << '\n'; 
    }
}

void dragon_curve(int y, int x, int d, int g){
    stack<int> st, next_st; 
    arr[y][x] = 1; 
    y = y + dy[d]; 
    x = x + dx[d]; 
    arr[y][x] = 1; 
    next_st.push(d);
    while(g > 0){
        st = next_st; 
        while(!st.empty()){
            d = st.top(); st.pop(); 
            d = (d + 1) % 4; 
            y = y + dy[d]; 
            x = x + dx[d]; 
            arr[y][x] = 1; 
            next_st.push(d); 
        }
        g--; 
    }
}

ll get_square_num(int s){
    ll cnt = 0; 
    for(int i = 0; i <= board_size - s; i++){
        for(int j = 0; j <= board_size - s; j++){
            if(!arr[i][j]) continue;
            if(!arr[i + s][j]) continue;
            if(!arr[i][j + s]) continue;
            if(!arr[i + s][j + s]) continue;
            cnt++;  
        }
    }
    return cnt; 
}

ll get_multi_size_square_num(){
    ll cnt = 0; 
    for(int i = 1; i < board_size; i++){
        cnt += get_square_num(i); 
    }
    return cnt; 
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 

    cin >> n; 
    for(int i = 0; i < n; i++){
        int y, x, d, g; 
        cin >> x >> y >> d >> g; 
        dragon_curve(y, x, d, g); 
    }

    cout << get_square_num(1) << '\n'; 
    // cout << get_multi_size_square_num() << '\n'; 
    print_arr();

    return 0; 
}