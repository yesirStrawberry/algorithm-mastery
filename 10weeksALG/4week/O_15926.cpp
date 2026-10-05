#include <bits/stdc++.h>
using namespace std;

int main(void){
    stack<int> st; 
    int n, mx = 0; string s; 
    cin >> n >> s; 
    for(char c : s){
        if(c == '(') {
            st.push(-1);
            continue; 
        } 
        if(!st.size()){
            st.push(-2); 
            continue; 
        }
        
        if(st.top() == -1){
            st.pop(); 
            st.push(2); 
        }
        else if(st.top() > 0){
            int num = st.top(); st.pop(); 
            if(st.size() && st.top() == -1){
                st.pop(); 
                st.push(num + 2); 
            }else{
                st.push(num); 
                st.push(-2); 
            }
        }
        int sum = 0; 
        while(st.size() && st.top() > 0){
            sum += st.top(); st.pop(); 
        }
        if(sum){
            st.push(sum);
            mx = mx < sum ? sum : mx; 
        }  
    }
    cout << mx << '\n'; 

    return 0; 
}