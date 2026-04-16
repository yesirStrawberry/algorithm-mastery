#include <stdlib.h>
#include <stdio.h>
#include "DualStack.h"

int init_DualStack(DualStack *s, int nmemb){
    if((s->arr = calloc(nmemb, sizeof(int))) == NULL) return -1; 
    s->nmemb = nmemb; 
    s->top1 = 0;
    s->top2 = 0; 
    return 0; 
}

int push1(DualStack *s, int x){
    if(s->top1 + s->top2 >= s->nmemb) return -1; 
    s->top1++; 
    s->arr[s->top1 - 1] = x; 
    return 0; 
}

int push2(DualStack *s, int x){
    if(s->top1 + s->top2 >= s->nmemb) return -1; 
    s->top2++; 
    s->arr[(s->nmemb - 1) - (s->top2 - 1)] = x; 
    return 0; 
}

int pop1(DualStack *s, int *x){
    if(s->top1 <= 0) return -1; 
    *x = s->arr[s->top1 - 1]; 
    s->top1--; 
}


int pop2(DualStack *s, int *x){
    if(s->top2 <= 0) return -1; 
    *x = s->arr[(s->nmemb - 1) - (s->top2 - 1)]; 
    s->top2--; 
    return 0; 
}

void print_dualStack(const DualStack *s){
    puts("----------------"); 
    for(int i = 0; i < s->top1; i++){
        printf("stack1[%d] : %d\n", i, s->arr[i]); 
    }    
    for(int i = 0; i < s->top2; i++){
        printf("stack2[%d] : %d\n", i, s->arr[(s->nmemb - 1) - i]); 
    }
    puts("----------------"); 
}
