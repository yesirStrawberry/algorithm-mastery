#include <bits/stdc++.h>
using namespace std; 

vector<int> prime, psum; 
int visited[4000004]; 
int n, ret; 

int main(void){
    cin >> n; 
    for(int i = 2; i <= n; i++){
        if(visited[i]) continue; 
        prime.push_back(i); 
        for(int j = i; j <= n; j += i) visited[j] = 1; 
    }
    int sum = 0; psum.push_back(sum); 
    for(int i = 0; i < prime.size(); i++){
        sum += prime[i]; 
        psum.push_back(sum); 
    }
    int l = 0, r = 0, subsum; 
    while(l <= r && r < psum.size()){
        subsum = psum[r] - psum[l]; 
        if(subsum > n) l++; 
        else if(subsum < n) r++; 
        else{
            ret++; r++; 
        }
    }
    cout << ret << '\n'; 

    return 0; 
}