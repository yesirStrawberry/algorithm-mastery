/*
merge sort를 wrapper을 활용하여 단순화 하시오.
*/

/* 개선점
01_merge에서는 buff에 대한 동적 메모리할당이 재귀를 진행할 때마다 진행됨
-> buff를 한 번만 할당하게 됨

01_merge에서는 mergesort(a, 0, n - 1)로 call시 index를 혼돈할 여지가 있었음
-> mergesort(a, n); 으로 함수 선언 시 실수를 줄임

__mergesort를 static으로 선언하여, 켑슐화의 이점을 갖게 됨./
*/

#include <stdio.h>
#include <stdlib.h>

int* buff; 

static void __mergesort(int a[], int left, int right){
    if(left < right){
        int center = (right + left) / 2; 
        
        __mergesort(a, left, center); 
        __mergesort(a, center + 1, right); 
        
        int i; 
        int j = 0; 
        int k = left; 
        int p = 0; 
        
        for(i = left; i <= center; i++){
            buff[p++] = a[i]; 
        }
        while(i <= right && j < p){
            a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++]; 
        }
        while(j < p){
            a[k++] = buff[j++]; 
        }
    }
}

int mergesort(int a[], int n){
    if((buff = calloc(n, sizeof(int))) == NULL) return -1; 
    __mergesort(a, 0, n - 1); 
    free(buff); 
    return 0; 
}


int main()
{
    int a[] = {5, 6, 4, 8, 3, 7, 9, 0, 1, 5, 2, 3}; 
    int n = sizeof(a)/ sizeof(a[0]);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    
    mergesort(a, n); 
    
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    return 0;
}
