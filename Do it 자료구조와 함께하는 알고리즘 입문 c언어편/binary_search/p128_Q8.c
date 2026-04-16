// p.128 Q8
/*
bsearch 함수와 같은 형식으로 호출할 수 있는 binary_search를 작성하시오
이분 탐색과정을 보여줄 수 있어야 합니다. 
*/

#include <stdio.h>
#include <stdlib.h>

void* binary_search(
    const void *key,
    const void *base,
    size_t nmemb, 
    size_t size,
    int (*compar)(const void *, const void *)
    ); 
    
void show_progress(const void* base, size_t nmemb, size_t size,
    const void* pl,const void* pr,const void* pc);  

int int_cmp(const void *key, const void *ele);

    
int main(void){
    int na; int *a; int* p; int key; 
    printf("array_size : "); scanf("%d", &na); 
    a = calloc(na, sizeof(int));
    
    // 오름차순으로 입력받기
    for(int i = 0; i < na; i++){
        do{
            printf("a[%d] : ", i); scanf("%d", &a[i]);   
        }while(i != 0 && a[i - 1] >= a[i]);
    }
    
    // 찾을 값 찾기
    printf("key : "); scanf("%d", &key); 
    
    // 이분탐색 실행
    p = (int*)binary_search(
            &key, 
            a,
            na,
            sizeof(int),
            (int(*)(const void *, const void *))int_cmp
        );
        
    if(p == NULL){
        printf("can't find"); return 0; 
    }
    printf("a[%d] : %d\n", (int)(p - a), key); 
    
    return 0; 
}


// 이분탐색 
void* binary_search(
    const void *key,
    const void *base,
    size_t nmemb, 
    size_t size,
    int (*compar)(const void *, const void *)
    )
{
    char *pr; char *pl; char* pc;
    char *pb = (char*) base; 
    int judge; 
    pl = pb; 
    pr = pb + size*(nmemb - 1); 
    
    
    do{
        // 이분탐색 중앙점 찍기
        size_t pl_idx = (pl - pb) / size; 
        size_t pr_idx = (pr - pb) / size; 
        pc = pb + ((pl_idx + pr_idx)/2) * size; 
        
        // 진행상황 찍기
        show_progress(base, nmemb, size, pl, pr, pc); 
        
        // 이분탐색 범위 업데이트
        judge = compar(key, pc); 
        if(judge == 0){
            return pc; 
        }else if(judge > 0){
            pl = pc + size*1; 
        }else{
            pr = pc - size*1; 
        }
    }while(pl <= pr);
    
    return NULL; 
}

// 진행상황 표시
void show_progress(const void* base, size_t nmemb, size_t size,
    const void* pl,const void* pr,const void* pc)
{
    char* pb = (char*) base;
    char* temp_pb = pb; 
    char* end = pb + nmemb*size;
    
    printf("   | "); 
    for(; pb < end; pb += size){
        if(pb == pl) printf(" <-"); 
        else if(pb == pr) printf(" -> ");
        else if(pb == pc) printf("  +"); 
        else printf("   ");
    }
    printf("\n"); 
    
    
    printf("% 3d| ",*(int*)pc); 
    for(pb = temp_pb; pb < end; pb += size){
        printf("% 3d",*(int*)pb);
    }
    printf("\n");
}

// 비교함수
int int_cmp(const void *key, const void *ele){
    if(*(int*)key < *(int*)ele) return -1; 
    else if(*(int*)key > *(int*)ele) return 1; 
    else return 0;
}
