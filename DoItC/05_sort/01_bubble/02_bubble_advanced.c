/*
이미 정렬이 된 배열은 더 이상 값을 바꾸어 줄 필요가 없음을 이용하여, 
advanced bubble function인 bubble2를 구현하시오
*/

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t; }while(0)

void bubble_progress(int a[], int n); 

void bubble2_progress(int a[], int n);

void print_bubble_progress(const int a[], int n, int j, int is_swap);

int main(void){
    
    int a[10] = {4,2,1,6,3,8,7,9,5,10};
    int b[10] = {4,2,1,6,3,8,7,9,5,10};
    int n =  10;
    
    bubble_progress(a, n); 
    for(int* p = a; p < a + n; p++) printf("% 2d", *p);
    putchar('\n'); 
    
    bubble2_progress(b, n); 
    for(int* p = b; p < b + n; p++) printf("% 2d", *p);
    putchar('\n'); 
    
    return 0; 
}


void bubble2_progress(int a[], int n){
    int pass = 0; 
    int cmp = 0; 
    int cnt_swap = 0; 
    char is_swap = '-';
    
    int is_exchg = 0; 
    for(int i = 0; i < n; i++){
        printf("pass : %d\n", ++pass); 
        
        is_exchg = 0; 
        for(int j = n - 1; j > i; j--){
            cmp++;
            if(a[j - 1] > a[j]){
                swap(int, a[j - 1], a[j]);
                is_exchg = 1; 
                is_swap = '+'; 
                cnt_swap++; 
            }
            print_bubble_progress(a, n, j, is_swap); 
        }
        if(!is_exchg) break; 
    }
    printf("cmp : %d\n", cmp); 
    printf("cnt_swap : %d\n", cnt_swap); 
}

void bubble_progress(int a[], int n){
    int pass = 0; 
    int cmp = 0; 
    int cnt_swap = 0; 
    char is_swap = '-'; 
    for(int i = 0; i < n; i++){
        printf("pass : %d\n", ++pass); 
        for(int j = n - 1; j > i; j--){
            is_swap = '-'; 
            cmp++;
            if(a[j - 1] > a[j]){
                swap(int, a[j - 1], a[j]); 
                is_swap = '+'; 
                cnt_swap++; 
            }
            print_bubble_progress(a, n, j, is_swap); 
        }
    }
    printf("cmp : %d\n", cmp); 
    printf("cnt_swap : %d\n", cnt_swap); 
}
void print_bubble_progress(const int a[], int n, int j, int is_swap){
    for(int i = 0; i < n; i++){
        if(i == j) printf(" %c", is_swap); 
        else printf("  "); 
        printf("% 2d", a[i]); 
    }
    putchar('\n'); 
}

