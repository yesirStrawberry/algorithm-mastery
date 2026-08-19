#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int cnt = 0; 
	int t; 
	cin >> t; 
	while(t--){
	    string s; 
	    cin >> s; 
	    vector<char> v; 
	    v.reserve(100004); 
	    
	    for(char c : s){
	        if(v.empty()){
	            v.push_back(c); 
	            continue; 
	        }
	        if(v.back() == c) v.pop_back(); 
	        else v.push_back(c); 
	    }
	    if(v.empty()) cnt++;
	}
	cout << cnt; 
	return 0; 
}
