/*
N-Queen 을 iterative하게 구현하라
* 각각의 경우의 board를 출력하라
* 모든 가능한 경우의 수를 출력하라
*/

#include <stdio.h>

int set(int n);
void print_pos(const int* pos, const int n);

int main(void){
    int n; int cnt; 
    
    for(int i = 0; i < 14; i++){
        printf("%02d Queen : %d\n", i, set(i));
    }
    
    return 0; 
}

int set(int n){
    int pos[20] = {0}; 
    int flag_a[20] = {0};
    int flag_b[2*(20) - 1] = {0}; // / 대각선 i + j
    int flag_c[2*(20) - 1] = {0}; // \ 대각선 (N - 1) - i + j
    int cnt = 0; 
    int i = 0, j = 0; 
    int found; 
    
    while(1){
        found = 0;
        for(; j < n; j++){
            if(!flag_a[j] && !flag_b[i+j] && !flag_c[(n - 1)-i+j]){
                pos[i] = j; 
                if(i == n - 1){
                    print_pos(pos, n); //n queen의 모든 경우 출력
                    cnt++; 
                }
                else{
                    flag_a[j] = flag_b[i + j] = flag_c[(n - 1) - i + j] = 1;
                    i++; 
                    j = 0; 
                    found = 1; 
                    break; 
                }
            }
        }
        // BackTracking
        if(!found){
            if(--i < 0) break; 
            j = pos[i]; 
            flag_a[j] = flag_b[i + j] = flag_c[(n - 1) - i + j] = 0;
            j++; 
        }
    }
    
    return cnt; 
}

void print_pos(const int* pos, const int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < pos[i] ; j++) putchar('O');
        putchar('*');
        for(int j = pos[i] + 1; j < n ; j++) putchar('O');
        putchar('\n');
    }
    putchar('\n');
}

