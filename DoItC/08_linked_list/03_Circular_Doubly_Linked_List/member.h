#ifndef __member
#define __member

typedef struct{
    char name[20]; 
    int age; 
}member;

void print_member(const member *x);

#endif /*__member*/