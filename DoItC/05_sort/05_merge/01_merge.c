/*
merge sort 구현
*/

#include <stdio.h>
#include <stdlib.h>

void mergesort(int a[], int left, int right){
    if(left >= right) return; 
    
    int* buff = calloc(right - left + 1, sizeof(int)); 
    
    int center = (left + right) / 2; 
    
    mergesort(a, left, center); 
    mergesort(a, center + 1, right); 
    
    int i; 
    int j = 0; 
    int p = 0;  
    int k = left;
    
    for(i = left; i <= center; i++){
        buff[p++] = a[i];
    }
    while(i <= right && j < p){
        a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
    }
    while(j < p){
        a[k++] = buff[j++];
    }
       
    free(buff);
}

int main()
{
    int a[] = {5, 6, 4, 8, 3, 7, 9, 0, 1, 5, 2, 3}; 
    int n = sizeof(a)/ sizeof(a[0]);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    
    mergesort(a, 0, n - 1); 
    
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    return 0;
}
