#include <bits/stdc++.h>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr); 
    
    int n, m, k; 
    int arr[30]; 
    cin >> n >> m; 
    cin >> k; 
    for(int i = 0; i < k; i++) cin >> arr[i]; 
    
    int s = 1;
    int move = 0; 
    for(int i = 0; i < k; i++){
        int p = arr[i]; 
        if(p < s){
            move += s - p; 
            s = p; 
        }else if(p >= s + m){
            move += (p + 1) - (s + m); 
            s = (p + 1) - m; 
        }
    }
    cout << move << '\n'; 
    
    return 0; 
}
