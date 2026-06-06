#ifndef __ArrayLinkedList
#define __ArrayLinkedList

#include "member.h"

#define null -1

typedef int Index; 

typedef struct{
    member data; 
    Index next; 
}Node; 

typedef struct{
    Node *arr; 
    Index size; 
    Index head; 
    Index crnt; 
    Index max; 
    Index deleted; 
}List;

void init_list(List *list, Index size);

Index search(List *list, const member *x, int compr(const member *x, const member *y));

void insert_front(List *list, const member *x);

void insert_rear(List *list, const member *x);

void remove_front(List *list);

void remove_rear(List *list); 

void remove_current(List *list);

void clear(List *list); 

void print_node(const List *list);

void print_list(const List *list);

void print_array(const List *list);

void terminate_list(List *list); 

#endif /*__ArrayLinkedList*/
