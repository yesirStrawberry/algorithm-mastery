#include <bits/stdc++.h>
using namespace std; 

int main(void){
    string a, b; 
    cin >> a >> b; 
    reverse(a.begin(), a.end()); 
    reverse(b.begin(), b.end()); 
    int carry = 0, curr, currA, currB; 
    string res = "";  
    for(int i = 0; i < a.size() || i < b.size(); i++){
        currA = i < a.size() ? a[i] - '0' : 0; 
        currB = i < b.size() ? b[i] - '0' : 0; 
        curr = carry + currA + currB; 
        carry = curr / 10; 
        curr = curr % 10; 
        res = (char)(curr + '0') + res; 
    }
    if(carry) res = (char)(carry + '0') + res; 
    cout << res << '\n'; 

    return 0; 
}