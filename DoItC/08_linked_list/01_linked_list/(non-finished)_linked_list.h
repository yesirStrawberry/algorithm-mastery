#ifndef __linked_list
#define __linked_list

#include "member.h"


typedef struct __node{
    member data; 
    struct __node *next; 
}Node; 

typedef struct{
    Node *head; 
    Node *crnt;
}List;

void init_list(List *list);

Node* search(List *list, const member* x, int compare(const member *x, const member *y));

bool insert_front(List *list, const member *x);

void insert_reer(List *list, const member *x);

bool remove_front(List *list);

void remove_reer(List *list);

void remove_current(List *list);

void clear(List *list);

void print_node(const List *list);

void print_list(const List *list);

void terminate_list(List *list); 

#endif
