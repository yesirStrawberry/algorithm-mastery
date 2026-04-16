/*
Ring Int Queue 사용을 위한 IntQueue.h의 implement file 이다. 
*/

#include <stdlib.h>
#include <stdio.h>
#include "IntQueue.h"

int init_IntQueue(IntQueue *q, int max){
    if((q->que = calloc(max, sizeof(int))) == NULL) return -1; 
    q->max = max; 
    q->num = q->front = q->rear = 0; 
    return 0; 
}

int enqueue(IntQueue *q, int x){
    if(q->num >= q->max) return -1;
    q->que[q->rear] = x; 
    q->rear++; 
    if(q->rear >= q->max) q->rear = 0;  
    q->num++;
    return 0; 
}

int dequeue(IntQueue *q, int* x){
    if(q->num <= 0) return -1;
    *x = q->que[q->front]; 
    q->front++;
    if(q->front == q->max) q->front = 0; 
    q->num--; 
    return 0; 
}

int peek(const IntQueue *q, int *x){
    if(q->num <= 0) return -1; 
    *x = q->que[q->front]; 
    return 0; 
}

void clear(IntQueue *q){
    q->num = q->front = q->rear = 0; 
}

int capacity(const IntQueue *q){
    return q->max; 
}

int size(const IntQueue *q){
    return q->num; 
}

int is_empty(const IntQueue *q){
    return q->num <= 0; 
}

int is_full(const IntQueue *q){
    return q->num >= q->max; 
}

int search(const IntQueue *q, int x){
    int idx; 
    for(int i = 0; i < q->num; i++){
        idx = (q->front + i) % q->max; 
        if(q->que[idx] == x) return idx; 
    }
    return -1; 
}

int search2(const IntQueue *q, int x){
    int idx; int cnt = 0;  
    for(int i = 0; i < q->num; i++){
        idx = (q->front + i) % q->max; 
        if(q->que[idx] == x) return cnt;
        cnt++; 
    }
    return -1; 
}


void print_IntQueue(const IntQueue *q){
    puts("-------------------------");
    for(int i = 0; i < q->num; i++){
        int idx = (i + q->front) % q->max;
        printf("a[%d] : % 2d\n", idx, q->que[idx]); 
    }
    puts("-------------------------");
}

void terminate(IntQueue *q){
    if(q->que != NULL) free(q->que); 
    q->max = q->num = q->front = q->rear = 0; 
}
