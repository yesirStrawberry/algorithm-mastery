#include <bits/stdc++.h>
using namespace std; 

int n, x, l, r, ret, sum; 
vector<int> v; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    v.reserve(n); 
    int tmp; 
    for(int i = 0; i < n; i++){
        cin >> tmp; 
        v.push_back(tmp);
    }
    cin >> x; 
    sort(v.begin(), v.end()); 
    l = 0; r = n - 1; 
    while(l < r){
        sum = v[l] + v[r]; 
        if(sum > x) r--; 
        else if(sum < x) l++; 
        else{
            ret++; 
            r--; 
        }
    }
    cout << ret << '\n'; 

    return 0; 
}