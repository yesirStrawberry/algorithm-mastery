#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

int n; 
stack<pair<ll, ll>> s; 
ll tmp, ret; 

int main(void){
    cin >> n;  
    for(int i = 0; i < n; i++){
        cin >> tmp; 
        ll cnt = 1; 
        while(s.size() && s.top().first <= tmp){
            ret += s.top().second;
            if(s.top().first == tmp){
                cnt = s.top().second + 1; 
            }else{
                cnt = 1; 
            }
            s.pop(); 
        }
        if(s.size()) ret++; 
        s.push({tmp, cnt}); 
    }
    cout << ret << '\n'; 

    return 0; 
}