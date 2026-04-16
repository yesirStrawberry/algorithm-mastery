/*
이분 탐색 및 중복되는 element중 
가장 앞의 element의 주소를 반환하는 
bsearchx를 설계하시오. 
*/

#include <stdio.h>
#include <stdlib.h>

void *bsearchx(const void *key, const void *base, size_t nmemb,
               size_t size, int(*compar)(const void*, const void*));

// bsearchx 내부에서 활용되며, 배열 상에서 같은 요소 중가장 앞쪽의 요소의 포인터를 반환
void *find_first_ele(const void* base, const void* pc, size_t size, 
                     int(*compar)(const void*, const void*)); 
                     
int int_cmp(const void *a, const void *b); 

int main(void){
    int* a; int na; int key; 
    printf("array size : "); scanf("%d", &na); 
    a = calloc(na, sizeof(int)); 
    
    // 오름차순 입력 강제
    for(int i = 0; i < na; i++){
        do{
            printf("a[%d] : ", i); scanf("%d", &a[i]);
        }while(i != 0 && a[i - 1] > a[i]); 
    }
    
    // key 입력 
    printf("key : "); scanf("%d", &key); 
    
    // 이분탐색 실행
    int *p = bsearchx(&key, a, na, sizeof(int), 
             (int(*)(const void*, const void*))int_cmp); 
    
    
    // 확인          
    for(int i = 0; i < na; i++) printf("% 3d", i); 
    printf("\n"); 
    for(int i = 0; i < na; i++) printf("% 3d", a[i]); 
    printf("\n"); 
    if(p != NULL) printf("a[%ld] : %d", (long)(p - a), *p); 
    else printf("Can't find"); 
    
    return 0; 
}


void *bsearchx(const void *key, const void *base, size_t nmemb,
               size_t size, int(*compar)(const void *, const void *)) {
	
	char *pb = (char*)base;
	char *pl = pb;
	char *pr = pb + (nmemb - 1)*size;
	char *pc;
	
	size_t pl_idx, pr_idx;
	int ret;

	do {
		// pc update
		pl_idx = (pl - pb)/size;
		pr_idx = (pr - pb)/size;
		pc = pb + ((pl_idx + pr_idx)/2)*size;
		
		// key와 pc 비교 
		ret = compar(key, pc);
		if(ret < 0) pr = pc - 1*size;
		else if(ret > 0) pl = pc + 1*size;
 		else return find_first_ele(base, pc, size, compar); 
 		
	} while(pl <= pr);

	return NULL;
}

void *find_first_ele(const void* base, const void* pc, size_t size, 
                     int(*compar)(const void*, const void*)) {
    char* temp_pc = (char*) pc; 
    char* pb = (char*) base;
    char* prev_p; 
    while(pb < temp_pc){
        prev_p = temp_pc - size; 
        if(!compar(temp_pc, prev_p)) temp_pc = prev_p; 
        else break; 
    }
    return temp_pc; 
}



int int_cmp(const void *a, const void *b){
    if(*(int*)a < *(int*)b) return -1; 
    else if (*(int*)a > *(int*)b) return 1; 
    else return 0; 
}
