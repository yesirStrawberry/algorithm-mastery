#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	map<char, int> mp;
	for(char c : s) mp[c]++;

    int isOdd = 0;
    char mid_char = '\0'; 
    
	for(auto& [ key, val] : mp) {
		if(val % 2 != 0){
    		isOdd++; 
    		mid_char = key; 
		} 
		if(isOdd > 1){
		    cout << "I'm Sorry Hansoo" << '\n'; 
    		return 0;   
		}
	}
	
	for(char c = 'A'; c <= 'Z'; c++){
	    for(int i = 0; i < mp[c] / 2; i++) cout << c; 
	}
	if(isOdd) cout << mid_char; 
	for(char c = 'Z'; c >= 'A'; c--){
	    for(int i = 0; i < mp[c] / 2; i++) cout << c; 
	}

	return 0;
}
