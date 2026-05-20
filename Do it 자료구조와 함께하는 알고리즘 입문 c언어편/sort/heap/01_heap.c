/*
* heap sort를 구현하시오
* 변수명을 보다 명시적으로 바꾸었음
** index 변수에는 _idx를 붙임

* if문에 조건을 그대로 넣는 것이 아닌 boolian 변수를 넣음
** boolian 변수명이 if문 조건에 이름을 붙여 보다 이해하기 쉬움
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SWAP(type, x, y) do{type t = x; x = y; y = t; } while(0)

static void shift_down(int array[], int start_idx, int end_idx); 

void heapsort(int array[], int size){
    if(size <= 1) return; 
    for(int i = (size - 1)/2; i >= 0; i--){
        shift_down(array, i, size - 1); 
    }
    for(int i = size - 1; i > 0; i--){
        SWAP(int, array[0], array[i]); 
        shift_down(array, 0, i - 1); 
    }
    return; 
}

static void shift_down(int array[], int start_idx, int end_idx){
    int target_val = array[start_idx]; 
    int parent_idx = start_idx; 
    int selected_child_idx; 
    
    while(true){
        int lchild_idx = parent_idx*2 + 1; 
        int rchild_idx = lchild_idx + 1; 
        
        bool has_left_child = (lchild_idx <= end_idx); 
        if(!has_left_child) break; 
        
        bool has_larger_right_child = 
            (rchild_idx <= end_idx && array[rchild_idx] > array[lchild_idx]); 
        if(has_larger_right_child){
            selected_child_idx = rchild_idx; 
        }else{
            selected_child_idx = lchild_idx; 
        }
        
        bool has_heap_order = (target_val >= array[selected_child_idx]); 
        if(has_heap_order){
            break;
        }

        array[parent_idx] = array[selected_child_idx]; 
        parent_idx = selected_child_idx; 
    }
    array[parent_idx] = target_val; 
}



int main()
{
    int a[] = {5, 6, 4, 8, 3, 7, 9, 0, 1, 5, 2, 3}; 
    int n = sizeof(a)/ sizeof(a[0]);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    
    heapsort(a, n);  
    
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    return 0;
}
