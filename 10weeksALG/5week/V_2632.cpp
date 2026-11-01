#include <bits/stdc++.h>
using namespace std; 

map<int, int> mpA, mpB; 
int psumA[2004], psumB[2004]; 
int order, n, m, cnt; 

void setInput(){
    cin >> order >> n >> m; 
    int num; 
    for(int i = 1; i <= n; i++){
        cin >> num; 
        psumA[i] = psumA[i - 1] + num;     
    } 
    for(int i = n + 1; i <= 2 * n; i++){
        psumA[i] = psumA[n] + psumA[i - n]; 
    }
    for(int i = 1; i <= m; i++){
        cin >> num; 
        psumB[i] = psumB[i - 1] + num;     
    } 
    for(int i = m + 1; i <= 2 * m; i++){
        psumB[i] = psumB[m] + psumB[i - m]; 
    }
}

void make(int psum[], int n, map<int, int>& mp){
    for(int diff = 1; diff <= n; diff++){
        for(int s = diff; s < n + diff; s++){
            int sum = psum[s] - psum[s - diff]; 
            mp[sum]++; 
            if(diff == n) break; 
        }
    }
}

int main(void){
    setInput(); 
    make(psumA, n, mpA); 
    make(psumB, m, mpB); 
    cnt = mpA[order] + mpB[order]; 
    for(int i = 1; i < order; i++){
        auto itA = mpA.find(i);
        auto itB = mpB.find(order - i);
        if(itA != mpA.end() && itB != mpB.end()){
            cnt += itA->second * itB->second;
        }
    }
    cout << cnt << '\n'; 
    
    return 0; 
}