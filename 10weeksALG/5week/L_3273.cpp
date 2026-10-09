#include <bits/stdc++.h>
using namespace std; 

int n, x, s, e, ret; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    vector<int> v(n); 
    s = 0; e = n - 1;  
    for(int i = 0; i < n; i++) cin >> v[i]; 
    cin >> x;
    sort(v.begin(), v.end()); 
    int sum;  
    while(s < e){
        sum = v[s] + v[e]; 
        if(sum > x) e--; 
        else if(sum < x) s++; 
        else{ ret++, s++, e--; }
    }
    cout << ret << '\n'; 

    return 0; 
}