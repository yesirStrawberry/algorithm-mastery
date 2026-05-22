#include <stdio.h>
#include <stdlib.h>

void fsort_int(int arr[], int nmemb){
    // max 값 구하기
    int max = arr[0]; 
    for(int i = 1; i < nmemb; i++){
        if(max < arr[i]) max = arr[i]; 
    }
    
    int* freq = calloc(max + 1, sizeof(int)); // calloc은 0으로 자동 초기화됨
    int* sorted = calloc(nmemb, sizeof(int)); 
    
    // f : 도수분포표 
    for(int i = 0; i < nmemb; i++){
        freq[arr[i]]++; 
    }
    
    // f : 누적도수분포표
    for(int i = 1; i <= max; i++){
        freq[i] += freq[i - 1]; 
    }
    
    // b : 정렬이 완료된 배열
    for(int i = 0; i < nmemb; i++){
        sorted[--freq[arr[i]]] = arr[i]; 
    }
    
    // 배열 복사
    for(int i = 0; i < nmemb; i++) arr[i] = sorted[i]; 
    
    free(freq); 
    free(sorted); 
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
