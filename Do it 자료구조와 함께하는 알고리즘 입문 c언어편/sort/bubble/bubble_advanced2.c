/*
각각의 pass에서 마지막 swap이 발생한 index까지만, 
다음 pass에서 반영하면 된다. 
이를 반영한 bubble3를 구현하시오
*/
#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t; }while(0)

void bubble3(int a[], int n); 

int main(void){
    int a[10] = {4,2,1,6,3,8,7,9,5,10};    
    bubble3(a, 10); 
    for(int* p = a; p < a + 10; p++) printf("% 2d", *p); 
    putchar('\n');
    
    return 0; 
}


void bubble3(int a[], int n){
    int k = 0; 
    while(k < n - 1){
        int last_i = n - 1;
        for(int i = n - 1; i > k; i--){
            if(a[i - 1] > a[i]){
                swap(int, a[i - 1], a[i]); 
                last_i = i; 
            }
        }
        k = last_i; 
    }
}

