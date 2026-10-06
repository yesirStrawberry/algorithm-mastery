#include <bits/stdc++.h>
using namespace std; 

stack<char> stk; 
string totalStr, bomb, curr, res; 
int Size;
char last; 

int main(void){
    cin >> totalStr >> bomb; 
    Size = bomb.size(); 
    last = bomb[Size - 1]; 
    for(char c : totalStr){
        stk.push(c); 
        if(stk.size() >= Size && c == last){
            curr = ""; 
            for(int i = 0; i < Size; i++){
                curr += stk.top(); stk.pop(); 
            }
            reverse(curr.begin(), curr.end()); 
            if(curr != bomb){
                for(int i = 0; i < Size; i++) stk.push(curr[i]); 
            }
        }
    }
    if(stk.empty()) cout << "FRULA" << '\n'; 
    else{
        while(stk.size()){
            res += stk.top(); stk.pop(); 
        }
        reverse(res.begin(), res.end()); 
        cout << res << '\n'; 
    }

    return 0; 
}