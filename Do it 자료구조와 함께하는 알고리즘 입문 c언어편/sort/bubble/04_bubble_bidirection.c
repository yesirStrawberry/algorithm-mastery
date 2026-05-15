/*
양방향 bubble sort
홀수 pass일 때는 backward로, 
짝수 pass일 때는 forward로, 
정렬하는 함수 작성
*/
#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t; }while(0)

int bubble_bidirection(int a[], int n); 
int forward_pass(int a[], int* s, int* e);
int backward_pass(int a[], int* s, int* e);

int main(void){
    int a[10] = {4,2,1,6,3,8,7,9,5,10};    
    bubble_bidirection(a, 10); 
    for(int* p = a; p < a + 10; p++) printf("% 2d", *p); 
    putchar('\n');
    
    return 0; 
}


int bubble_bidirection(int a[], int n){
    int s = 0; 
    int e = n - 1; 
    int pass = 0; 
    int last = 0; 
    
    while(s < e){
        ++pass; 
        if(pass % 2 == 0) forward_pass(a, &s, &e);
        else backward_pass(a, &s, &e);
    }
}

int forward_pass(int a[], int* s, int* e){
    int last_i = *s;
    for(int i = *s; i < *e; i++){
        if(a[i] > a[i + 1]){
            swap(int, a[i], a[i + 1]);
            last_i = i; 
        } 
    }
    *e = last_i; 
}

int backward_pass(int a[], int* s, int* e){
    int last_i = *e; 
    for(int i = *e; i > *s; i--){
        if(a[i - 1] > a[i]){
            swap(int, a[i - 1], a[i]);
            last_i = i; 
        }
    }
    *s = last_i;
}
