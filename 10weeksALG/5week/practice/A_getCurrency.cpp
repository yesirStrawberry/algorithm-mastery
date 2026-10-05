#include <bits/stdc++.h>
using namespace std; 

int total = 12100, ret;
vector<pair<int, int>> currency = {{10000, 5}, {5000, 5}, {1000, 5}, {100, 1}}; 

int main(void){
    sort(currency.rbegin(), currency.rend()); 
    for(pair<int, int> curr : currency){
        while(total >= curr.first && curr.second > 0){
            total -= curr.first; 
            curr.second--; 
            ret++; 
        }
    }
    cout << ret << '\n'; 

    return 0; 
}