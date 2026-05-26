/*
qsort와 같은 형식으로 호출할 수 있는 아래의 함수를 직접 작성하시오. 
void q_sort(void *base, size_t nmemb, size_t size_t, 
            int(*compar)(const void *, const void *))
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void q_sort(void *base, size_t nmemb, size_t size, 
            int(*compar)(const void *, const void *)){
    
    if(nmemb < 2) return; 
    
    typedef struct{
        size_t left; 
        size_t right; 
    }node; 
    
    char* pb = base; 
    
    node st[100]; 
    int top = -1; 
    st[++top] = (node){0, nmemb - 1}; 
    
    char pivot[size]; 
    
    while(top != -1){
        node curr = st[top--]; 
        char* pl = pb + curr.left*size;
        char* pr = pb + curr.right*size; 
        memcpy(pivot, pb + ((curr.left + curr.right) / 2)*size, size);
        
        do{
            while(compar(pl, pivot) < 0) pl += size;
            while(compar(pr, pivot) > 0) pr -= size; 
            
            if(pl <= pr){
                for(size_t i = 0; i < size; i++){
                    char t = *(pl + i); 
                    *(pl + i) = *(pr + i); 
                    *(pr + i) = t; 
                }
                pl += size; 
                pr -= size; 
            }
        }while(pl <= pr);
        
        size_t pl_idx = (pl - pb)/size; 
        size_t pr_idx = (pr - pb)/size; 
        
        if((curr.right - pl_idx) < (pr_idx - curr.left)){
            if((pr_idx - curr.left) > 0) st[++top] = (node){curr.left, pr_idx}; 
            if((curr.right - pl_idx) > 0) st[++top] = (node){pl_idx, curr.right}; 
        }
        else{
            if((curr.right - pl_idx) > 0) st[++top] = (node){pl_idx, curr.right}; 
            if((pr_idx - curr.left) > 0) st[++top] = (node){curr.left, pr_idx}; 
        }
    }
}

int string_cmp(const char** a, const char** b){
    return strcmp(*a, *b);
}


int main()
{
    char* data[] = {
        "Apple", 
        "Banana", 
        "C", 
        "Data Structure", 
        "QuickSort", 
        "AI"
    };  
    int n = sizeof(data)/sizeof(data[0]); 
    
    q_sort(data, 
          n,
          sizeof(char*),
          (int(*)(const void *, const void *))string_cmp
          ); 
    
    for(int i = 0; i < n; i++) printf(" %s",data[i]); 
    putchar('\n'); 
    
    return 0;
}
