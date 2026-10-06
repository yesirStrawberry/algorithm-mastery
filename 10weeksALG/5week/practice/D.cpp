#include <bits/stdc++.h>
using namespace std; 

int n;
double tmp;  
priority_queue<double> pq; 

int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> tmp; 
        pq.push(tmp);
        if(pq.size() > 5){
            pq.pop(); 
        }
    }
    cout << "-------------" << '\n'; 
    stack<double> s; 
    for(int i = 0; i < 5; i++){
        s.push(pq.top()); 
        pq.pop(); 
    }
    for(int i = 0; i < 5; i++){
        cout << s.top() << '\n'; 
        s.pop(); 
    }

    return 0; 
}