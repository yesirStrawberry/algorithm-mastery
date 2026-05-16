/*
void m_sort(void* base, size_t nmemb, size_t size, 
            int (*compar)(void* int, void* int)); 
위의 형식으로 병합정렬을 수행할 수 있도록 작성하시오. 
*/

/*수정사항
1. *pos_sorted = *pos_buff로 element를 입력함
    >> char* 임으로 1byte 씩으로밖에 수정이 안됨
    >> memcpy()로 element 입력

2. __msort에 전달해야되는 매개변수 중 값이 변하지 않는 것들은
   base, buff, size, compar가 있는데
   이를 하나의 struct에 묶어서 전달하도록 수정
   static void __msort(void* base, void* buff, size_t size, int l_idx, int r_idx,
                       int (*compar)(void*, void*))
   >> static void __msort(MsortContext* ctx, int l_idx, int r_idx)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    void* base; 
    void* buff; 
    size_t size; 
    int (*compar)(void*, void*); 
}MsortContext; 

static void __msort(MsortContext* ctx, int l_idx, int r_idx);

void m_sort(void* base, size_t nmemb, size_t size, 
            int (*compar)(void *, void *)){
    char* buff = calloc(nmemb, size);
    MsortContext ctx = (MsortContext){base, buff, size, compar}; 
    __msort(&ctx, 0, nmemb - 1); 
    free(buff); 
    return; 
}

static void __msort(MsortContext* ctx, int l_idx, int r_idx){
    if(l_idx >= r_idx) return; 
    int mid_idx = (l_idx + r_idx) / 2; 
    
    __msort(ctx, l_idx, mid_idx); 
    __msort(ctx, mid_idx + 1, r_idx); 
    
    char* base_ptr = (char*)(ctx->base); 
    char* buff_ptr = (char*)(ctx->buff); 
    size_t size = ctx->size;
    
    char* src_ptr;    // 복사 대상 주소
    char* dest_ptr;   // 복사 목적지 주소
    char* left_ptr;   // 병합시 왼쪽 그룹(buff) 요소 주소
    char* right_ptr;  // 병합시 오른쪽 그룹(base) 요소 주소
    char* sorted_ptr; // 정렬된 값이 들어갈 base 주소
    
    int r_curr = mid_idx + 1; // 오른쪽 그룹(base) 추적 인덱스  
    int l_curr = 0;           // 왼쪽 그룹(buff) 추적 인덱스
    int buff_cnt = 0;         // buff에 저장된 요소 개수
    int m_curr = l_idx;       // 최종 병합 위치 인덱스
    
    int temp_idx = l_idx; 
    while(temp_idx <= mid_idx){
        dest_ptr = buff_ptr + buff_cnt * size; 
        src_ptr = base_ptr + temp_idx * size; 
        memcpy(dest_ptr, src_ptr, size);
        buff_cnt++; 
        temp_idx++; 
    }
    while(r_curr <= r_idx && l_curr < buff_cnt){
        sorted_ptr = base_ptr + m_curr * size; 
        left_ptr = buff_ptr + l_curr * size; 
        right_ptr = base_ptr + r_curr * size;
        if(ctx->compar(left_ptr, right_ptr) <= 0){
            memcpy(sorted_ptr, left_ptr, size);
            l_curr++; 
        }else{
            memcpy(sorted_ptr, right_ptr, size);
            r_curr++; 
        }
        m_curr++; 
    }
    while(l_curr < buff_cnt){
       sorted_ptr = base_ptr + m_curr * size; 
       left_ptr = buff_ptr + l_curr * size; 
       memcpy(sorted_ptr, left_ptr, size);;
       l_curr++; m_curr++; 
    }
    return;
}

int int_cmp(void* a, void* b){
    if(*(int*)a < *(int*)b) return 1; 
    else if(*(int*)a > *(int*)b) return -1;
    else return 0; 
}

int main()
{
    int a[] = {5, 6, 4, 8, 3, 7, 9, 0, 1, 5, 2, 3}; 
    int n = sizeof(a)/ sizeof(a[0]);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    
    m_sort(a, n, sizeof(int), int_cmp);  
    
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    return 0;
}
