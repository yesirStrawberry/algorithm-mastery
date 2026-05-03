/*
N-Queen 을 recursive하게 구현하라
* 각각의 경우의 board를 출력하라
* 모든 가능한 경우의 수를 출력하라
*/

#include <stdio.h>

int pos[20];
int flag_a[20];
int flag_b[2*(20) - 1]; // / 대각선 i + j
int flag_c[2*(20) - 1]; // \ 대각선 (N - 1) - i + j
int cnt = 0; 
int N; 

void init_flag_pos();

void print_pos();

void set(int i); 

int main(void){
    printf("N : "); scanf("%d", &N); 
    init_flag_pos(); 
    set(0); 
    printf("cnt : %d", cnt);
    
    return 0; 
}


void init_flag_pos(){
    for(int i = 0; i < N; i++){
        pos[i] = 0; 
        flag_a[i] = 0; 
    } 
    for(int i = 0; i < N; i++){
        flag_b[i] = 0; 
        flag_c[i] = 0;
    }    
}


void set(int i){
    for(int j = 0; j < N; j++){
        if(!flag_a[j] && !flag_b[i+j] && !flag_c[(N - 1)-i+j]){
            pos[i] = j; 
            if(i == N - 1) {
                print_pos();
                cnt++;
            }
            else{
                flag_a[j] = flag_b[i + j] = flag_c[(N - 1) - i + j] = 1; 
                set(i + 1);
                flag_a[j] = flag_b[i + j] = flag_c[(N - 1) - i + j] = 0; 
            }
        }
    }
}


void print_pos(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < pos[i] ; j++) putchar('O');
        putchar('*');
        for(int j = pos[i] + 1; j < N ; j++) putchar('O');
        putchar('\n');
    }
    putchar('\n');
}
