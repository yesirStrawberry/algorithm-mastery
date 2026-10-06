#include <bits/stdc++.h>
using namespace std; 

string totalStr, bomb, ret; 

int main(void){
    cin >> totalStr >> bomb; 
    for(char c : totalStr){
        ret.push_back(c); 
        if(ret.size() >= bomb.size() && ret.substr(ret.size() - bomb.size(), bomb.size()) == bomb){
            // ret.erase(ret.end() - bomb.size(), ret.end()); 
            for(int i = 0; i < bomb.size(); i++) ret.pop_back(); 
        }
    }
    cout << ret << '\n'; 

    return 0; 
}