/*
Deque(Double Ended Queue)를 구현한다.
이를 위한 implement file이다. 
*/

#include <stdlib.h>
#include <stdio.h>
#include "IntDeque.h"

int init_Dque(IntDque *dq, int max){
    if((dq->dque = calloc(max, sizeof(int))) == NULL) return -1; 
    dq->max = max; 
    dq->num = dq->front = dq->rear = 0; 
    return 0; 
}

// front는 data가 들어있는 idx임으로, 먼저 update 하고 할당한다. 
int push_front(IntDque *dq, int x){
    // dq 다 차있나 체크
    if(dq->num >= dq->max) return -1; 
    
    // front update
    dq->front--; 
    if(dq->front < 0) dq->front = dq->max - 1; 
    
    // dq에 값 할당
    dq->dque[dq->front] = x;
    
    // num update
    dq->num++; 
    
    return 0; 
}

// rear는 값이 들어갈 idx임으로, 먼저 update하고 할당한다. 
int push_rear(IntDque *dq, int x){
    // dq 다 차있나 체크
    if(dq->num >= dq->max) return -1; 
    
    // dq에 값 할당
    dq->dque[dq->rear] = x; 
    
    // rear update
    dq->rear++; 
    if(dq->rear >= dq->max) dq->rear = 0; 
    
    // num update; 
    dq->num++; 
    
    return 0; 
}

// front는 data가 들어있는 idx임으로, 먼저 x에 할당하고 updqte한다. 
int pop_front(IntDque *dq, int *x){
    // 빼야될 값이 있나 체크
    if(dq->num <= 0) return -1; 
    
    // x에 값 할당
    *x = dq->dque[dq->front]; 
    
    // front update
    dq->front++; 
    if(dq->front >= dq->max) dq->front = 0; 
    
    // num update; 
    dq->num--; 
    
    return 0; 
}

// rear는 값이 들어갈 idx임으로, 먼저 update하고 x에 할당한다. 
int pop_rear(IntDque *dq, int *x){
    // 빼야될 값이 있나 체크
    if(dq->num <= 0) return -1; 

    // rear update
    dq->rear--; 
    if(dq->rear < 0) dq->rear = dq->max - 1; 
    
    // x에 값 할당
    *x = dq->dque[dq->rear];
    
    // num update
    dq->num--; 
    
    return 0; 
}

void print_IntDeque(const IntDque *dq){
    puts("--------------------"); 
    int idx; 
    for(int i = 0; i < dq->num; i++){
        idx = (dq->front + i) % dq->max; 
        printf("dque : %d\n", dq->dque[idx]); 
    }
    puts("--------------------");
}
