/*
이분탐색을 활용하여, key에 해당하는 element의 index를 반환하는 함수를 작성하시오
이때, 배열에 key가 존재하지 않는 경우에, 
배열의 값 중 key보다 큰 element 중 가장 작은 element를 반환해야 한다. 
*/
#include <stdio.h>
#include <stdlib.h>
int binary_search(const void* key, const void* base, 
                    size_t nmemb, size_t size, 
                    int(*compar)(const void* , const void*));

int int_cmp(const void* a, const void* b); 

int main(void) {
    // 1. 테스트용 정렬된 배열 (0, 10, 20, 30, 40)
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    int key;
    int res_idx;

    printf("--- Test Array: [10, 20, 30, 40, 50] ---\n\n");

    // 케이스 1: 배열에 존재하는 값 찾기 (30은 index 2에 있음)
    key = 30;
    res_idx = binary_search(&key, a, n, sizeof(int), int_cmp);
    printf("Search for %d: Index %d (Expected: 2)\n", key, res_idx);

    // 케이스 2: 배열에 없는 값 찾기 (25는 20과 30 사이, 즉 index 2에 삽입되어야 함)
    key = 25;
    res_idx = binary_search(&key, a, n, sizeof(int), int_cmp);
    printf("Search for %d: Insert at Index %d (Expected: 2)\n", key, res_idx);

    // 케이스 3: 가장 작은 값보다 작은 경우 (0에 삽입되어야 함)
    key = 5;
    res_idx = binary_search(&key, a, n, sizeof(int), int_cmp);
    printf("Search for %d: Insert at Index %d (Expected: 0)\n", key, res_idx);

    // 케이스 4: 가장 큰 값보다 큰 경우 (n인 5에 삽입되어야 함)
    key = 100;
    res_idx = binary_search(&key, a, n, sizeof(int), int_cmp);
    printf("Search for %d: Insert at Index %d (Expected: 5)\n", key, res_idx);

    return 0;
}



int binary_search(const void* key, const void* base, 
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
        else return pc_idx; 

    }while(pl_idx <= pr_idx); 
    
    return pl_idx;
} 

int int_cmp(const void* a, const void* b){
    if(*(int*)a < *(int*)b) return -1;
    else if(*(int*)a > *(int*)b) return 1;
    else return 0; 
}
