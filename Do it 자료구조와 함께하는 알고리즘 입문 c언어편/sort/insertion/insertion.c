/*
삽입정렬을 수행하는 insertion_sort 함수를 작성하라
*/
#include <stdio.h>

void insertion_sort(int a[], int n);

int main()
{
    int a[10] = {4,2,1,6,3,8,7,9,5,10};
    int n = 10; 
    insertion_sort(a, n); 
    for(int* p = a; p < a + n; p++) printf("% 2d", *p); 
    putchar('\n'); 

    return 0;
}


void insertion_sort(int a[], int n){
    int i, j, tmp; 
    for(i = 1; i < n; i++){
        tmp = a[i]; 
        for(j = i; j > 0 && a[j - 1] > tmp; j--){
            a[j] = a[j - 1]; 
        }
        a[j] = tmp; 
    }
}
