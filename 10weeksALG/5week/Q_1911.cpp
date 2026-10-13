#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

ll n, l, pos, cnt; 
vector<pair<ll, ll>> v; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n >> l;
    v.reserve(n); 
    ll a, b; 
    for(int i = 0; i < n; i++){
        cin >> a >> b; 
        v.push_back({a, b}); 
    }
    sort(v.begin(), v.end()); 
    for(pair<ll, ll> p : v){
        ll s = p.first, e = p.second;
        if(pos < s){
            pos = s;
            pos += l - 1; 
            cnt++;
        }  
        while(pos < e - 1){
            pos += l; 
            cnt++;  
        }
    }
    cout << cnt << '\n'; 

    
    return 0; 
}