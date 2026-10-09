#include <bits/stdc++.h>
using namespace std; 

int arr[100004], chk[100004]; 
long long n, s, e, ret; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> arr[i]; 
    while(e < n){
        if(!chk[arr[e]]){
            chk[arr[e]]++;
            e++; 
        }else{
            ret += e - s; 
            chk[arr[s]]--; 
            s++; 
        }
    }
    ret += (e - s) * (e - s + 1) / 2; 
    cout << ret << '\n'; 

    return 0; 
}