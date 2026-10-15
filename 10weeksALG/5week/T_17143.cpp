#include <bits/stdc++.h>
using namespace std; 

struct shark{
    int d, s, z; 
}; 

int n, m, ret; 
shark arr[104][104]; 
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}; 
const int dir_map[] = {0, 0, 2, 1, 3}; 

void print_arr(){
    cout << "arr" << '\n'; 
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << arr[i][j].s << arr[i][j].d << arr[i][j].z << ' ';
        } 
        cout << '\n'; 
    }
}

void move_shark(){
    shark tmp[104][104] = {{0, 0, 0}};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j].z == 0) continue; 
            int d = arr[i][j].d; 
            int s = arr[i][j].s; 
            int z = arr[i][j].z; 
            int y = i, x = j; 
            for(int k = 0; k < s; k++){
                int ny = y + dy[d]; 
                int nx = x + dx[d]; 
                if(ny < 1 || ny > n || nx < 1 || nx > m){
                    d = (d + 2) % 4; 
                    ny = y + dy[d]; 
                    nx = x + dx[d]; 
                }
                y = ny; x = nx; 
            }
            if(tmp[y][x].z < z){
                tmp[y][x] = {d, s, z};
            }  
        }
    }
    memcpy(arr, tmp, sizeof(tmp));  
}

void set_input(){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    int num_of_shark; 
    cin >> n >> m >> num_of_shark; 
    int y, x; 
    for(int i = 0; i < num_of_shark; i++){
        cin >> y >> x; 
        cin >> arr[y][x].s >> arr[y][x].d >> arr[y][x].z;
        arr[y][x].d = dir_map[arr[y][x].d];  
    }
}

int main(void){
    set_input(); 
    for(int pos = 1; pos <= m; pos++){
        int y = 0, x = pos; 
        while(y <= n && arr[y][x].z == 0) y++; 
        // print_arr();
        // cout << "y : " << y << " x : " << x << '\n';
        // cout <<  "arr[y][x].z : " << arr[y][x].z << '\n'; 
        ret += arr[y][x].z; 
        arr[y][x] = {0, 0, 0}; 
        move_shark(); 
    }
    cout << ret << '\n'; 

    return 0; 
}