#include <iostream>
#include <vector> 
using namespace std; 

long long fibo(int n){
    if(n == 0) return 0; 
    if(n == 1) return 1; 
    return fibo(n-1) + fibo(n-2); 
}

vector<long long> v; 

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    v.push_back(0);
    v.push_back(1); 
    long long n; 
    for(int i = 2; i <= 40; i++){
        n = v[v.size() - 1] + v[v.size() - 2];
        v.push_back(n); 
    }
    
    int t, a;
    cin >> t; 
    for(int i = 0; i < t; i++){
        cin >> a; 
        if(a == 0){
            cout << 1 << " " << 0 << '\n'; 
        }
        else{
            cout << v[a - 1] << " " << v[a] << '\n';
        }
    }
    
    return 0; 
}