/* 요소의 값이 내림차순으로 정렬된 long형 배열에서의 검색을 bsearch 함수를 사용하는 프로그램 작성*/

#include  <stdio.h>
#include  <stdlib.h>

int long_cmpr(const void *a, const void *b);

int main(void)
{
    long* a; int na; long ky; 
    printf("element number : "); scanf("%d", &na);
    a = (long*)calloc(na, sizeof(long)); 
    
    // desc
    int i = 0; 
    while(i < na){
        printf("a[%d] : ", i); scanf("%ld", &a[i]); 
        if(i == 0 || a[i] < a[i - 1]) i++; 
        else printf("Re\n"); 
    }
    
    printf("--------------------------------------------\n");
    for(int i = 0; i < na; i++)printf("a[%d] : %ld\n", i, a[i]); 
    
    // key 
    printf("--------------------------------------------\n");
    printf("key : "); scanf("%ld", &ky); 
    
    // binary search 
    long* p; 
    p = (long*)bsearch(
            &ky, 
            a,
            na,
            sizeof(long),
            (int(*)(const void*, const void*))long_cmpr
        ); 
        
    if(p == NULL){printf("Can't find\n"); return 0;}
    
    printf("a[%d : %ld]", (int)(p - a), ky);
    
    return 0; 
}


int long_cmpr(const void *a, const void *b){
    if(*(long*)a < *(long*)b) return 1; 
    else if(*(long*)a > *(long*)b) return -1;
    else return 0; 
}
