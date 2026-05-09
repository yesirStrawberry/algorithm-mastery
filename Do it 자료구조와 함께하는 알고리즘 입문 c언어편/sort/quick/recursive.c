/*
quick sort를 recursive하게 수행하는 함수 작성
진행과정을 나타내시오
*/

/*실행결과 
---------------------------------
{5, 8, 4, 2, 6, 1, 3, 5, 9, 7}
---------------------------------
a[0] ~ a[9] : {5, 8, 4, 2, 6, 1, 3, 5, 9, 7}
a[0] ~ a[5] : {5, 5, 4, 2, 3, 1}
a[0] ~ a[2] : {1, 3, 2}
a[0] ~ a[1] : {1, 2}
a[3] ~ a[5] : {4, 5, 5}
a[3] ~ a[4] : {4, 5}
a[6] ~ a[9] : {6, 8, 9, 7}
a[6] ~ a[7] : {6, 7}
a[8] ~ a[9] : {9, 8}
---------------------------------
{1, 2, 3, 4, 5, 5, 6, 7, 8, 9}
*/

#include <stdio.h>

#define swap(type, x, y) do{type t = x; x = y; y = t; }while(0)

void quick_sort_recur(int a[], int left, int right);
void print_progress(const int a[], int left, int right);
void print_arr(const int a[], int n);

int main(void) {
    // 테스트용 임의 배열 (무작위, 역순, 중복값 포함)
    int data[] = {5, 8, 4, 2, 6, 1, 3, 5, 9, 7};
    int n = sizeof(data) / sizeof(data[0]);
    
    puts("---------------------------------");
    print_arr(data, n);
    
    puts("---------------------------------");
    quick_sort_recur(data, 0, n - 1);
    
    puts("---------------------------------");
    print_arr(data, n);

    return 0;
}

void quick_sort_recur(int a[], int left, int right){
    print_progress(a, left, right); 
    int pl = left; 
    int pr = right;
    int x = a[(left + right) / 2]; 
    do{
        while(a[pl] < x) pl++; 
        while(a[pr] > x) pr--; 
        if(pl <= pr){
            swap(int, a[pl], a[pr]);
            pl++; 
            pr--; 
        }
    }while(pl <= pr);
    if(pr > left) quick_sort_recur(a, left, pr); 
    if(pl < right) quick_sort_recur(a, pl, right); 
}


void print_progress(const int a[], int left, int right){
    printf("a[%d] ~ a[%d] : {", left, right); 
    for(int i = left; i < right; i++) printf("%d, ", a[i]); 
    printf("%d}\n", a[right]); 
}


void print_arr(const int a[], int n){
    printf("{"); 
    for(int i = 0; i < n - 1; i++){
        printf("%d, ", a[i]); 
    }
    printf("%d}\n", a[n - 1]);
}
