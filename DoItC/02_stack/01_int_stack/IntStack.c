#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack *s, int max){
    s->ptr = 0;
    s->stk = calloc(max, sizeof(int));
    if(s->stk == NULL){
        s->max = 0;
        return -1; 
    } 
    s->max = max; 
    return 0; 
}

int Push(IntStack *s, int x){
    if(s->ptr >= s->max) return -1; 
    s->stk[s->ptr++] = x; 
    return 0; 
}

int Pop(IntStack *s, int *x){
    if(s->ptr <= 0) return -1;
    
    *x = s->stk[--s->ptr]; 
    return 0; 
}

int Peek(const IntStack *s, int *x){
    if(s->ptr <= 0) return -1; 
    *x = s->stk[s->ptr - 1]; 
    return 0; 
}

void Clear(IntStack *s){
    s->ptr = 0; 
}

int Capacity(const IntStack *s){
    return s->max;
}

int Size(const IntStack *s){
    return s->ptr; 
}

int IsEmpty(const IntStack *s){
    return s->ptr <= 0; 
}

int IsFull(const IntStack *s){
    return s->ptr >= s->max; 
}

int Search(const IntStack *s, int x){
    for(int i = 0; i < s->ptr; i++){
        if(s->stk[i] == x) return i;   
    }
    return -1; 
}

void print(const IntStack *s){
    for(int i = 0; i < s->ptr; i++) printf("s->stk[%d] : %d\n",i, s->stk[i]);
    putchar('\n'); 
}

void Terminate(IntStack *s){
    if(s->stk != NULL) free(s->stk); 
    s->ptr = 0; s->max = 0; 
}
