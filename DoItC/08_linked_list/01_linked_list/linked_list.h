#ifndef __linked_list
#define __linked_list

#include <stdbool.h>
#include "member.h"


typedef struct __node{
    member data; 
    struct __node *next; 
}Node; 

typedef struct{
    Node *head; 
    Node *crnt;
}List;

bool init_list(List *list);

Node* search(List *list, const member* x, int compare(const member *x, const member *y));

bool insert_front(List *list, const member *x);

bool insert_reer(List *list, const member *x);

bool remove_front(List *list);

bool remove_reer(List *list);

bool remove_current(List *list);

void clear(List *list);

void print_node(const List *list);

void print_list(const List *list);

void terminate_list(List *list); 

#endif
