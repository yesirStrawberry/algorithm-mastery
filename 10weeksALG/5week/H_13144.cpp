#include <bits/stdc++.h>
using namespace std; 

int visited[100004]; 
long long ret, cnt, n, s, e, x, a, b; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    s = 0; e = n + 1; 
    for(int i = 1; i <= n; i++){
        cin >> x; 
        if(!visited[x]) { visited[x] = i; continue; } 
        a = visited[x]; b = i; 
        if(s < a && b < e) cnt -= (a - s) * (e - b); 
        if(s < a){ cnt += (a - s) * (n + 1 - b); s = a; }
        if(b < e){ cnt += (e - b) * (a); e = b; }
        visited[x] = i; 
    }
    ret = (n * (n + 1)) / 2; 
    ret -= cnt; 
    cout << ret << '\n'; 
    return 0; 
}