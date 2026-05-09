/*
quick sort 를 recursive가 아닌 implementary하게 작성
구간의 크기가 9 이하면 insertion sort를 수행한다.

또한 이를 quick_sort_impl과 비교한다. 
*/

/*실행결과 
데이터 개수: 3000000
-------------------------------
cnt : 01
General Quick Sort: 0.746 sec
Quick + Insertion Sort: 0.611 sec
-------------------------------
cnt : 02
General Quick Sort: 0.705 sec
Quick + Insertion Sort: 0.603 sec
-------------------------------
cnt : 03
General Quick Sort: 0.701 sec
Quick + Insertion Sort: 0.593 sec
-------------------------------
cnt : 04
General Quick Sort: 0.695 sec
Quick + Insertion Sort: 0.595 sec
-------------------------------
cnt : 05
General Quick Sort: 0.688 sec
Quick + Insertion Sort: 0.591 sec
-------------------------------
cnt : 06
General Quick Sort: 0.667 sec
Quick + Insertion Sort: 0.573 sec
-------------------------------
cnt : 07
General Quick Sort: 0.693 sec
Quick + Insertion Sort: 0.583 sec
-------------------------------
cnt : 08
General Quick Sort: 0.672 sec
Quick + Insertion Sort: 0.603 sec
-------------------------------
cnt : 09
General Quick Sort: 0.680 sec
Quick + Insertion Sort: 0.580 sec
-------------------------------
cnt : 10
General Quick Sort: 0.677 sec
Quick + Insertion Sort: 0.612 sec
-------------------------------
average General Quick Sort : 0.692 sec
average Quick + Insertion Sort : 0.594 sec
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define swap(type, x, y) do{type t = x; x = y; y = t; }while(0)

typedef struct{
    int left; 
    int right; 
}node; 

void quick_sort_impl(int a[], int n);
void quick_sort_impl_insertion(int a[], int n);
void print_arr(const int a[], int n);


int main() {
    const int N = 3000000;
    const int CNT = 10; 
    int cnt = 0; 
    double sum_quick = 0; 
    double sum_quick_insertion = 0; 
    
    printf("데이터 개수: %d\n", N);
    while(cnt++ < CNT){
        puts("-------------------------------"); 
        printf("cnt : %02d\n", cnt);
        int *origin = (int *)malloc(sizeof(int) * N);
        int *arr = (int *)malloc(sizeof(int) * N);
        
        // 무작위 데이터 생성
        srand(time(NULL));
        for (int i = 0; i < N; i++) origin[i] = rand();
    
        // 1. 일반 퀵 정렬 테스트
        memcpy(arr, origin, sizeof(int) * N);
        clock_t start = clock();
        quick_sort_impl(arr, N);
        clock_t end = clock();
        printf("General Quick Sort: %.3f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
        sum_quick += (double)(end - start) / CLOCKS_PER_SEC;
    
        // 2. 삽입 정렬 혼합 퀵 정렬 테스트
        memcpy(arr, origin, sizeof(int) * N);
        start = clock();
        quick_sort_impl_insertion(arr, N);
        end = clock();
        printf("Quick + Insertion Sort: %.3f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
        sum_quick_insertion += (double)(end - start) / CLOCKS_PER_SEC;
    
        free(origin);
        free(arr);
    }
    
    puts("-------------------------------"); 
    printf("average General Quick Sort : %.3f sec\n", sum_quick / CNT); 
    printf("average Quick + Insertion Sort : %.3f sec\n", sum_quick_insertion / CNT); 
    
    return 0;
}

void quick_sort_impl_insertion(int a[], int n){
    if(n < 2) return; 
    
    node st[100];  
    int top = -1; 
    st[++top] = (node){0, n - 1}; 
    while(top != -1){
        node curr = st[top--]; 
        
        // 구간의 크기가 9 이하면 insertion sort로 수행
        if(curr.right - curr.left < 9){
            int i, j, tmp; 
            for(i = curr.left + 1; i < curr.right; i++){
                tmp = a[i]; 
                for(j = i; j > curr.left && a[j - 1] > tmp; j--){
                    a[j] = a[j - 1]; 
                }
                a[j] = tmp; 
            }
            continue; 
        }
        
        int pl = curr.left; 
        int pr = curr.right; 
        int x = a[(curr.left + curr.right) / 2]; 
        do{
            while(a[pl] < x) pl++; 
            while(a[pr] > x) pr--;
            if(pl <= pr){
                swap(int, a[pl], a[pr]);
                pl++; 
                pr--; 
            }
        }while(pl <= pr);
        
        // 요소의 개수가 많은 걸 먼저 push
        if((curr.right - pl) < (curr.left - pr)){
            if(pr > curr.left) st[++top] = (node){curr.left, pr};
            if(pl < curr.right) st[++top] = (node){pl, curr.right}; 
        }
        else{
            if(pl < curr.right) st[++top] = (node){pl, curr.right};
            if(pr > curr.left) st[++top] = (node){curr.left, pr};
        }
    }
}

void quick_sort_impl(int a[], int n){
    node st[100];  
    int top = -1; 
    st[++top] = (node){0, n - 1}; 
    while(top != -1){
        node curr = st[top--]; 
        int pl = curr.left; 
        int pr = curr.right; 
        int x = a[(curr.left + curr.right) / 2]; 
        do{
            while(a[pl] < x) pl++; 
            while(a[pr] > x) pr--;
            if(pl <= pr){
                swap(int, a[pl], a[pr]);
                pl++; 
                pr--; 
            }
        }while(pl <= pr);
            
        // 요소의 개수가 많은 걸 먼저 push
        if((pl - curr.right) < (pr-curr.left)){
            if(pr > curr.left) st[++top] = (node){curr.left, pr};
            if(pl < curr.right) st[++top] = (node){pl, curr.right}; 
        }
        else{
            if(pl < curr.right) st[++top] = (node){pl, curr.right};
            if(pr > curr.left) st[++top] = (node){curr.left, pr};
        }
    }
}
