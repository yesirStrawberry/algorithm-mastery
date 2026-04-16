// p.128 Q7
/*
bsearch 함수와 같은 형식으로 호출할 수 있는 다음함수를 작성하시오
단, 선형 검색 알고리즘(brute force)을 사용하고,
배열은 정렬되어 있지 않아도 좋습니다. 
*/

#include <stdio.h>
#include <stdlib.h>

void *seqsearch(const void *key, 
                const void *base,
                size_t nmemb,
                size_t size, 
                int(*compar)(const void*, const void*)
);

int main(void){
    int* a; int na; int ky; 
    printf("array size : "); scanf("%d", &na); 
    a = calloc(na, sizeof(int)); 
    for(int i = 0; i < na; i++){
        printf("a[i] : "); scanf("%d", &a[i]); 
    }
    printf("key : "); scanf("%d", &ky);  
    
    int* p = seqsearch(
        &ky, 
        a, 
        na, 
        sizeof(int), 
        )
    
    
    return 0; 
}


void *seqsearch(const void *key, 
                const void *base,
                size_t nmemb,
                size_t size, 
                int(*compar)(const void*, const void*)
){
    char *p = (char*) base;
    char *end = p + nmemb*size; 
    
    for(;  p < end; p += size){
        if(compar((void*)key, p) == 0) {return (void*)p}
    }
    return NULL; 
}
