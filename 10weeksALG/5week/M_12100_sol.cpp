#include <bits/stdc++.h>
using namespace std; 

int arr[24][24], n, mx; 

void slide(int arr[24][24]){
    int tmp[24][24] = {0}; 
    for(int i = 0; i < n; i++){
        int cnt = 0; 
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0) continue; 
            if(tmp[i][cnt] == 0) tmp[i][cnt] = arr[i][j]; 
            else if(tmp[i][cnt] == arr[i][j]){
                tmp[i][cnt] *= 2; 
                cnt++; 
            }else if(tmp [i][cnt] != arr[i][j]){
                cnt++; 
                tmp[i][cnt] = arr[i][j]; 
            }
        }
    }
    memcpy(arr, tmp, sizeof(tmp)); 
}

void rotate(int arr[24][24]){
    int tmp[24][24]; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tmp[j][n - 1 - i] = arr[i][j]; 
        }
    }
    memcpy(arr, tmp, sizeof(tmp)); 
}

int getMax(int arr[24][24]){
    int ret = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ret = ret < arr[i][j] ? arr[i][j] : ret;
        }  
    }
    return ret; 
}

void go(int arr[24][24], int dep){
    if(dep == 5){
        mx = max(mx, getMax(arr)); 
        return; 
    }
    int nxt[24][24]; 
    for(int i = 0; i < 4; i++){
        memcpy(nxt, arr, sizeof(nxt)); 
        slide(nxt); 
        go(nxt, dep + 1); 
        rotate(arr);
    }
}

int main(void){
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> arr[i][j]; 
    }
    go(arr, 0); 
    cout << mx << '\n'; 
    return 0; 
}