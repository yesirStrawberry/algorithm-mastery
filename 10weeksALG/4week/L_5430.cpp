#include <bits/stdc++.h>
using namespace std; 

int arr[104]; 
int s, e, pos, n;
bool errFlag = 0;  

void set_arr(string arrS){
    int idx = 0; 
    string snum = ""; 
    for(char c : arrS){
        if(c < '0' || c > '9'){
            if(snum.size() != 0){
                arr[idx] = stoi(snum); 
                idx++;
                snum = "";
            } 
        }else snum += c; 
    }
}

void print_res(){
    if(errFlag){
        cout << "error" << '\n';
        return;    
    }
    vector<int> v; 
    for(int i = s; i < e; i++) v.push_back(arr[i]); 
    if(pos) reverse(v.begin(), v.end());
    string res = "["; 
    for(int num : v){
        res += to_string(num) + ","; 
    }
    if(res.size() > 1 )res[res.size() - 1] = ']'; 
    else res += ']'; 
    cout << res << '\n'; 
}

void good_print(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr); 
}

int main(void){
    good_print(); 
    int t; 
    string arrS, instructions; 
    cin >> t; 
    while(t--){ 
        cin >> instructions; 
        cin >> n;
        cin >> arrS; 
        set_arr(arrS);
        s = 0; e = n; pos = 0; errFlag = 0;  
        for(char ins : instructions){
            if(ins == 'R') pos ^= 1; 
            else if(ins == 'D'){
                if(s >= e){
                    errFlag = 1; 
                    break; 
                }
                if(pos) e--; 
                else s++; 
            }
        }
        print_res(); 
    }

    return 0; 
}