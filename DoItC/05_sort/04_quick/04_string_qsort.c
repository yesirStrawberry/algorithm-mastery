/*
string을 ASC로 정렬한다.
*/

#include <stdio.h>
#include <string.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

typedef struct{
    int left; 
    int right; 
}node;

void string_qsort(char** a, int n){
    node st[100];
    int top = -1; 
    st[++top] = (node){0, n - 1}; 
    while(top > -1){
        node curr = st[top--]; 
        int pl = curr.left; 
        int pr = curr.right; 
        char* x = a[(curr.left + curr.right) / 2]; 
        
        do{
            while(strcmp(a[pl], x) < 0) pl++; 
            while(strcmp(a[pr], x) > 0) pr--; 
            if(pl <= pr){
                swap(char*, a[pl], a[pr]); 
                pl++; 
                pr--; 
            }
        }while(pl <= pr); 
        
        if((curr.right - pl) < (pr-curr.left)){
            if(pr > curr.left) st[++top] = (node){curr.left, pr};
            if(pl < curr.right) st[++top] = (node){pl, curr.right}; 
        }
        else{
            if(pl < curr.right) st[++top] = (node){pl, curr.right};
            if(pr > curr.left) st[++top] = (node){curr.left, pr};
        }
    }
}

int main(void){
    char* a[] = {
        "Apple", 
        "Banana", 
        "C", 
        "Data Structure", 
        "QuickSort", 
        "AI"
    }; 
    int n = sizeof(a) / sizeof(a[0]);
    string_qsort(a, n); 
    for(int i = 0; i < n; i++){printf("%s ", a[i]);}
    return 0; 
}
