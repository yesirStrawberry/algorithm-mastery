#ifndef ___Dualstack
#define ____DualStack

#include <stdlib.h>

typedef struct{
    int *arr;  
    int nmemb; 
    int top1; 
    int top2; 
}DualStack; 

int init_DualStack(DualStack *s, int nmemb); 

int push1(DualStack *s, int x);

int push2(DualStack *s, int x);

int pop1(DualStack *s, int *x);

int pop2(DualStack *s, int *x);

void print_dualStack(const DualStack *s);


#endif
