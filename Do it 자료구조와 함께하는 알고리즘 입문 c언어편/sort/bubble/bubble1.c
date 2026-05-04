/*
bubble 정렬을 수행하는 함수  bubble과 
왼쪽부터 정렬을 수행하는 함수 bubble_left
bubble 정렬의 과정을 보여주는 bubble_progress 함수를 작성하시오. 
*/

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t; }while(0)

void bubble(int a[], int n); 

void bubble_left(int a[], int n); 

void bubble_progress(int a[], int n); 
void print_bubble_progress(const int a[], int n, int j, int is_swap);

void init_darray(int a[], int* n); 

int main(void){
    int* a; int n; 
    init_darray(a, &n); 
    bubble(a, n); 
    
    for(int* p = a; p < a + n; p++) printf("% 2d", *p);
    putchar('\n'); 
    
    free(a); 
    return 0; 
}

void init_darray(int a[], int* n){
    printf("n : "); scanf("%d", n); 
    a = calloc(*n, sizeof(int)); 
    for(int i = 0; i < *n; i++){
        printf("a[%d] : ", i); 
        scanf("%d", &a[i]); 
    }
}


void bubble(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            if(a[j - 1] > a[j]){
                swap(int, a[j - 1], a[j]); 
            }
        }
    }
}
