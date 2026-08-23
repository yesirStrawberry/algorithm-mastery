#include <bits/stdc++.h>
using namespace std; 

string arr[70]; 

string go(int n, int y, int x){
    char c = arr[y][x]; 
    string ret = ""; 

    bool isSame = true; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(c != arr[y + i][x + j]) isSame = false; 
        }
    }
    
    if(isSame){
        ret += c; 
        return ret; 
    }
    
    ret += "("; 
    ret += go(n/2, y, x); 
    ret += go(n/2, y, x + n/2); 
    ret += go(n/2, y + n/2, x); 
    ret += go(n/2, y + n/2, x + n/2); 
    ret += ")"; 
    return ret; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> arr[i]; 
    
    cout << go(n, 0, 0); 
    
    return 0; 
}
