#include <stdlib.h> 
#include <stdio.h>
#include "IntQueue.h"

int init_IntQueue(IntQueue *q, int max){
    if((q->que = calloc(max, sizeof(int))) == NULL) return -1; 
    q->max = max; 
    q->num = 0; 
    return 0; 
}

int enqueue(IntQueue *q, int x){
    if(q->num >= q->max) return -1; 
    q->num++;
    q->que[q->num - 1] = x; 
    return 0; 
}

int dequeue(IntQueue *q, int *x){
    if(q->num <= 0) return -1; 
    *x = q->que[0];

    // 이때 element를 하나씩 당기면서, O(n)이 된다. 
    for(int i = 0; i < q->num - 1; i++){
        q->que[i] = q->que[i + 1];  
    }
    
    q->num--; 

    return 0; 
}

void print_IntQueue(const IntQueue *q){
    int *p = q->que; 
    int *end = q->que + q->num; 
    for(; p < end; p++){
        printf("%d, ",*p); 
    }
    puts(""); 
}
