//Ring Buffer 없이 Queue를 구현한다.
//dequeue 가 O(n)이다.  

#ifndef ___IntQueue
#define ___IntQueue

typedef struct{
    int max; 
    int num; 
    int *que; 
}IntQueue; 

int init_IntQueue(IntQueue *q, int max);

int enqueue(IntQueue *q, int x); 

int dequeue(IntQueue *q, int *x); 

void print_IntQueue(const IntQueue *q); 

#endif
