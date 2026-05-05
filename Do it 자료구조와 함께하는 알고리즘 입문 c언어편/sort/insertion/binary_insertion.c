/*
insertion sort 과정 중, 
이미 정렬이 완료된 곳 중에 한 곳을 찾는 과정에 binary_search을 활용하시오
또한 memmove를 활용하여, 배열을 옮기는 작업을 수행하시오
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* binary_search(const void* key, const void* base, 
                    size_t nmemb, size_t size, 
                    int(*compar)(const void* , const void*));
int int_cmp(const void* a, const void* b); 
void insertion_binary_sort(int a[], int n); 
void print_array(const int a[], int n); 
void print_progress(int i, int j);


int main(void) {
    // 테스트용 배열
    int a[10] = {4, 2, 1, 6, 3, 8, 7, 9, 5, 10};
    int n = 10;

    printf("--- Original Array ---\n");
    print_array(a, n);
    printf("\n--- Sorting Process ---\n");

    insertion_binary_sort(a, n);

    printf("\n--- Sorted Array ---\n");
    print_array(a, n);

    return 0;
}

void insertion_binary_sort(int a[], int n){
    int tmp;
    
    for(int i = 1; i < n; i++){
        print_array(a, n); // for visualize
        
        tmp = a[i]; 
        
        int* p = (int*)binary_search(&tmp, a, i, sizeof(int), int_cmp); 
        
        
        memmove(p + 1, p, (size_t)(&a[i] - p)*sizeof(int)); 
        /* memmove(목적주소, 출발주소, 옮길 크기)
        < 내부적으로 발생하는 일 >  
        int* k = &(a[i]); 
        while(p < k){
            *k = *(k - 1);
            k--; 
        }
        */
        
        *p = tmp; 
        
        print_progress(i, (size_t)(p - a)); // for visualize
    }
}


void* binary_search(const void* key, const void* base, 
                    size_t nmemb, size_t size, 
                    int(*compar)(const void* , const void*)){
    
    char* pb = (char*)base; 
    int pr_idx = nmemb - 1; 
    int pl_idx = 0; 
    int pc_idx; 
    int judge; 
    
    do{
        pc_idx = (pl_idx + pr_idx)/2;
        
        judge = compar(key, pb + pc_idx * size); 
        if(judge < 0){
            pr_idx = pc_idx - 1; 
        }
        else if(judge > 0){
            pl_idx = pc_idx + 1; 
        }
        else return pb + pc_idx * size; 

    }while(pl_idx <= pr_idx); 
    
    return pb + pl_idx * size;
} 

int int_cmp(const void* a, const void* b){
    if(*(int*)a < *(int*)b) return -1;
    else if(*(int*)a > *(int*)b) return 1;
    else return 0; 
}

void print_array(const int a[], int n){
    for(int i = 0; i < n; i++) printf("% 3d", a[i]); 
    putchar('\n');
}

void print_progress(int i, int j){
    char line[100]; 
    memset(line, ' ', sizeof(line)); 
    int start = 3 * j + 2; 
    int end = 3 * i + 2; 
    
    if(i == j){
        line[end] = '+'; 
    }
    else{
        line[start] = '^'; 
        for(int k = start + 1; k < end; k++) line[k] = '-'; 
        line[end] = '+';
    }
    line[end + 1] = '\0';
    printf("%s\n", line); 
}
