/*
어떤 type이던 정렬할 수 있는 general한 hsort 함수 작성
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    void* base;
    size_t size; 
    int(*compar)(const void*,const void*); 
    char* temp_ptr; 
    char* target_ptr; 
}HsortContext; 

static void shift_down(HsortContext* htx, size_t start_idx, size_t end_idx);  
static void generic_swap(void* x, void* y, size_t size, char* temp_ptr); 

void hsort(void* base, size_t nmemb, size_t size, int(*compar)(const void*,const void*)){
    if(nmemb <= 1) return; 
    char* global_temp = (char*)malloc(size);
    char* target_ptr = (char*)malloc(size); 
    if(global_temp == NULL || target_ptr == NULL) return; 
    
    HsortContext htx = (HsortContext){base, size, compar, global_temp, target_ptr}; 
    char* base_ptr = base; 
    
    for(int start_idx = (nmemb - 1) / 2; start_idx >= 0; start_idx--){
        shift_down(&htx, start_idx, nmemb - 1); 
    }
    for(int last_idx = nmemb - 1; last_idx > 0; last_idx--){
        char* base_root_ptr = base_ptr; 
        char* base_last_ptr = base_ptr + last_idx * size;  
        generic_swap(base_root_ptr, base_last_ptr, size, htx.temp_ptr);
        shift_down(&htx, 0, last_idx - 1); 
    }
    
    free(global_temp); 
    free(target_ptr); 
    return; 
}

static void shift_down(HsortContext* htx, size_t start_idx, size_t end_idx){
    char* base_ptr = htx->base; 
    size_t size = htx->size; 
    
    memcpy((htx->target_ptr), (base_ptr + (start_idx * size)), (htx->size)); 
    size_t parent_idx = start_idx; 
    size_t selected_child_idx; 
    size_t lchild_idx; 
    size_t rchild_idx; 
    
    char* parent_ptr; 
    char* lchild_ptr; 
    char* rchild_ptr;
    char* selected_child_ptr; 
    
    while(true){
        // 오른, 왼쪽 자식 idx 부여 
        lchild_idx = (parent_idx * 2) + 1;
        rchild_idx = (parent_idx * 2) + 2;  
        
        // 자식 있는지 검사
        bool has_child = (lchild_idx <= end_idx); 
        if(!has_child) break; 
        
        // 올바른 자식 선택
        bool has_rchild = (rchild_idx <= end_idx); 
        bool has_larger_right_child = false; 
        if(has_rchild){
            lchild_ptr = base_ptr + (lchild_idx * size); 
            rchild_ptr = base_ptr + (rchild_idx * size); 
            has_larger_right_child = (htx->compar(rchild_ptr, lchild_ptr) > 0);     
        }
        if(has_rchild && has_larger_right_child){
            selected_child_idx = rchild_idx; 
        }else{
            selected_child_idx = lchild_idx; 
        }
        
        // 만약 heap 상태면 break
        selected_child_ptr = base_ptr + (selected_child_idx * size); 
        bool has_heap_order = (htx->compar(htx->target_ptr, selected_child_ptr) >= 0); 
        if(has_heap_order) break; 
        
        // parent update 하고 아래 층 탐색
        parent_ptr = base_ptr + (parent_idx * size); 
        memcpy(parent_ptr, selected_child_ptr, size); 
        parent_idx = selected_child_idx; 
    }
    
    parent_ptr = base_ptr + (parent_idx * size); 
    memcpy(parent_ptr, htx->target_ptr, size); 
}


static void generic_swap(void* x, void* y, size_t size, char* temp_ptr){
    memcpy(temp_ptr, x, size); 
    memcpy(x, y, size); 
    memcpy(y, temp_ptr, size); 
}


int int_cmp(const void* a,const void* b){
    if(*(int*)a < *(int*)b) return -1; 
    else if(*(int*)a > *(int*)b) return 1;
    else return 0; 
}

int main()
{
    int a[] = {5, 6, 4, 8, 3, 7, 9, 0, 1, 5, 2, 3}; 
    int n = sizeof(a)/ sizeof(a[0]);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    
    hsort(a, n, sizeof(int), int_cmp); 
    
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    return 0;
}

