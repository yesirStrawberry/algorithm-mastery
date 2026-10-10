#include <bits/stdc++.h>
using namespace std; 

int n, arr[24][24], mn = 987654321; 

bool chkPeopleNum(int bs){
    int cnt = 0; 
    for(int i = 1; i < (1 << n); i *= 2){
        if(i & bs) cnt++; 
    }
    return cnt == n / 2; 
}

int getSinalgy(int bs){
    int ret = 0; 
    for(int i = 0; i < n; i++){
        if(!((1 << i) & bs)) continue; 
        for(int j = 0; j < n; j++){
            if(!((1 << j) & bs)) continue;
            ret += arr[i][j];  
        }
    }
    return ret; 
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j]; 
        }
    }
    for(int bs = 0; bs < (1 << n); bs++){
        if(!chkPeopleNum(bs)) continue; 
        mn = min(mn, abs(getSinalgy(bs) - getSinalgy(~bs))); 
    }
    cout << mn << '\n'; 

    return 0; 
}