#include <bits/stdc++.h>
using namespace std; 
const int INF = 2000000000; 

int n, mx = -INF, mn = INF, op[4], arr[15]; 

void go(int curr, int dep){
    if(dep == n - 1){
        mx = max(mx, curr); 
        mn = min(mn, curr); 
        return; 
    }
    for(int i = 0; i < 4; i++){
        if(op[i] <= 0) continue; 
        op[i]--; 
        if(i == 0) go(curr + arr[dep + 1], dep + 1); 
        else if(i == 1) go(curr - arr[dep + 1], dep + 1); 
        else if(i == 2) go(curr * arr[dep + 1], dep + 1); 
        else if(i == 3) go(curr / arr[dep + 1], dep + 1); 
        op[i]++; 
    }
}

int main(void){
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> arr[i]; 
    for(int i = 0; i < 4; i++) cin >> op[i]; 
    go(arr[0], 0); 
    cout << mx << '\n'; 
    cout << mn << '\n'; 

    return 0; 
}