/*
Ring Int Queue 사용을 위한 header file이다. 
*/

#ifndef ____IntQueue
#define ____IntQueue

typedef struct{
    int num; 
    int max; 
    int front; 
    int rear; 
    int* que; 
}IntQueue;

int init_IntQueue(IntQueue *q, int max);

int enqueue(IntQueue *q, int x);

int dequeue(IntQueue *q, int* x);

int peek(const IntQueue *q, int *x);

void clear(IntQueue *q);

int capacity(const IntQueue *q);

int size(const IntQueue *q); 

int is_empty(const IntQueue *q);

int is_full(const IntQueue *q);

// index를 반환한다. 
int search(const IntQueue *q, int x);

// front부터의 상대적 위치를 반환한다. 
// return값이 5라면 5번재 dequeue시에 해당되는 값이 dequeue된다. 
int search2(const IntQueue *q, int x);

void print_IntQueue(const IntQueue *q);

void terminate(IntQueue *q); 

#endif 
