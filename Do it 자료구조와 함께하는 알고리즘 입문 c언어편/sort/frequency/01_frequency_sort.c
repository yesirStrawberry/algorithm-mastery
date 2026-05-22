#include <stdio.h>
#include <stdlib.h>

void fsort_int(int a[], int n){
    // max 값 구하기
    int max = a[0]; 
    for(int i = 0; i < n; i++){
        if(max < a[i]) max = a[i]; 
    }
    
    int* f = calloc(max + 1, sizeof(int)); 
    int* b = calloc(n, sizeof(int)); 
    
    // f : 도수분포표 
    for(int i = 0; i <= max; i++) f[i] = 0; 
    for(int i = 0; i < n; i++){
        f[a[i]]++; 
    }
    
    // f : 누적도수분포표
    for(int i = 1; i <= max; i++){
        f[i] += f[i - 1]; 
    }
    
    // b : 정렬이 완료된 배열
    for(int i = n - 1; i >= 0; i--){
        b[--f[a[i]]] = a[i]; 
    }
    
    // 배열 복사
    for(int i = 0; i < n; i++) a[i] = b[i]; 
    
    free(f); 
    free(b); 
}



int main(void){
    int a[] = {5, 6, 4, 8, 3, 7, 9, 0, 1, 5, 2, 3}; 
    int n = sizeof(a)/ sizeof(a[0]);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    
    fsort_int(a, n); 
    
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    return 0;
}
