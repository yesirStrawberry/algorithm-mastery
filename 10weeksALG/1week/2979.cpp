#include <bits/stdc++.h>
using namespace std;

void solve() {
    int arr[104]; 
    memset(arr, 0, 104 * sizeof(int)); 
    
    int a[4]; 
    int s, e; 
    int t = 0;
    a[0] = 0; 
    cin >> a[1] >> a[2] >> a[3]; 
    
    for(int i = 0; i < 3; i++){
        cin >> s >> e; 
        for(int j = s; j < e; j++){
            arr[j]++; 
        }
        t = t < e ? e : t; 
    }
    
    int sum = 0; 
    for(int i = 0; i < t; i++){
        sum += a[arr[i]] * arr[i];
    }
    
    cout << sum; 
}
