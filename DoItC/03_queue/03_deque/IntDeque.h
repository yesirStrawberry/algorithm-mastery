/*
Deque(Double Ended Queue)를 구현한다. 
이를 위한 Header file이다. 
*/

#ifndef ___IntDeque
#define ___IntDeque

typedef struct{
    int* dque; 
    int max; 
    int num; 
    int front; // data가 들어있는 idx
    int rear; // data가 들어갈 idx
}IntDque;

int init_Dque(IntDque *dq, int max);

int push_front(IntDque *dq, int x);

int push_rear(IntDque *dq, int x);

int pop_front(IntDque *dq, int *x);

int pop_rear(IntDque *dq, int *x);

void print_IntDeque(const IntDque *dq);

#endif
