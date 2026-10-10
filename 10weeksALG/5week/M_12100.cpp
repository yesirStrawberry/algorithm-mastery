#include <bits/stdc++.h>
using namespace std; 

int n, mx, arr[24][24];

void tpose(); 
void moveRight(); 
void moveLeft(); 
void moveUp(); 
void moveDown(); 
int getMax(); 
void go(int dep);
void (*moveFunc[4])() = {moveRight, moveLeft, moveUp, moveDown};  

int main(void){
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> arr[i][j]; 
    }
    go(0); 
    cout << mx << '\n';
    return 0; 
}

void go(int dep){
    if(dep == 5){
        mx = max(mx, getMax());
        return;  
    }
    int backup[24][24]; 
    for(int i = 0; i < 4; i++){
        memcpy(backup, arr, sizeof(int)*24*24); 
        moveFunc[i](); 
        go(dep + 1); 
        memcpy(arr, backup, sizeof(int)*24*24); 
    }
}

int getMax(){
    int ret = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ret = ret < arr[i][j] ? arr[i][j] : ret; 
        }
    }
    return ret; 
}

void tpose(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++) swap(arr[i][j], arr[j][i]); 
    }
}

void moveRight(){
    int e, s; 
    for(int i = 0; i < n; i++){
        e = n - 1; s = n - 2; 
        while(s >= 0){
            if(s == e) s--; 
            else if(arr[i][s] == 0){
                s--; 
            }  
            else if(arr[i][e] == 0){
                arr[i][e] = arr[i][s]; 
                arr[i][s] = 0; 
                s--; 
            }else if(arr[i][s] == arr[i][e]){
                arr[i][e] *= 2; 
                arr[i][s] = 0; 
                e--; 
                s--; 
            }else if(arr[i][s] != arr[i][e]){
                e--; 
            }
        }
    }
}

void moveLeft(){
    int e, s; 
    for(int i = 0; i < n; i++){
        e = 0; s = 1; 
        while(s <= n - 1){
            if(s == e) s++; 
            else if(arr[i][s] == 0){
                s++; 
            }  
            else if(arr[i][e] == 0){
                arr[i][e] = arr[i][s]; 
                arr[i][s] = 0; 
                s++; 
            }else if(arr[i][s] == arr[i][e]){
                arr[i][e] *= 2; 
                arr[i][s] = 0; 
                e++; 
                s++; 
            }else if(arr[i][s] != arr[i][e]){
                e++; 
            }
        }
    }
}

void moveUp(){
    tpose(); 
    moveLeft(); 
    tpose(); 
}

void moveDown(){
    tpose(); 
    moveRight(); 
    tpose(); 
}
