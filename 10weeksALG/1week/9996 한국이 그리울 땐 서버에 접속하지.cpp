#include "header.h"
#include <bits/stdc++.h>
using namespace std; 


vector<string> split(const string& input, string dl){
    vector<string> res; 
    auto s = 0; 
    auto e = input.find(dl); 
    while(e != string::npos){
        res.push_back(input.substr(s, e - s)); 
        s = e + dl.size(); 
        e = input.find(dl, s); 
    }
    res.push_back(input.substr(s, e - s)); 
    return res; 
}

int solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    string patS, patE; 
    string pat; 
    string s; 
    
    cin >> n; 
    cin >> pat; 
    
    vector <string> patV = split(pat, "*");
    
    patE = patV[1];
    patS = patV[0];

    while(n--){
        cin >> s; 
        if( patS == s.substr(0, patS.size()) && 
            patE == s.substr(s.size() - patE.size(), patE.size()))
            cout << "DA" << '\n'; 
        else cout << "NE" << '\n'; 
    }

    return 0; 
}

