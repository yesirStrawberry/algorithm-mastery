#include "header.h"
// -------------------------------------------
#include <bits/stdc++.h>
using namespace std; 

int solve(void){
    int arr[100004], psum[100004];
    memset(arr, 0, sizeof(int)*100004); 
    memset(psum, 0, sizeof(int)*100004); 
    
    int n, k;
    cin >> n >> k; 
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i]; 
        psum[i] = psum[i - 1] + arr[i]; 
    }
    
    int s, e, val, max; 
    s = 0; 
    e = k; 
    max = psum[e] - psum[s]; 
    
    while(e <= n){
        val = psum[e] - psum[s]; 
        max = max < val ? val : max; 
        s++; e++; 
    }
    
    cout << max; 
    
    return 0; 
}
