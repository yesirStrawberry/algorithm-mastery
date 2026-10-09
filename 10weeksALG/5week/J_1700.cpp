#include <bits/stdc++.h>
using namespace std; 

const int SIZE = 104; 
int chk[SIZE], arr[SIZE], n, k, ret, chkSize;

int getNextIdx(int x, int idx);
void deletePlug();

int main(void){
    cin >> n >> k; 
    for(int i = 0; i < k; i++) cin >> arr[i]; 
    for(int i = 0; i < k; i++){
        if(chk[arr[i]]){
            chk[arr[i]] = getNextIdx(arr[i], i); 
        }  
        else if(chkSize < n){
            chk[arr[i]] = getNextIdx(arr[i], i); 
            chkSize++;  
        }
        else if(chkSize == n){
            deletePlug(); 
            chk[arr[i]] = getNextIdx(arr[i], i); 
            chkSize++;
        }
    }
    cout << ret << '\n'; 

    return 0; 
}

int getNextIdx(int x, int idx){
    int next_idx = idx + 1; 
    while(next_idx < k && arr[idx] != arr[next_idx]) {
        next_idx++; 
    } 
    return next_idx; 
}

void deletePlug(){
    int mx = 0, del_idx; 
    for(int i = 0; i < SIZE; i++){
        if(mx < chk[i]){
            mx = chk[i]; 
            del_idx = i; 
        }
    }
    chk[del_idx] = 0; 
    chkSize--; 
    ret++; 
}