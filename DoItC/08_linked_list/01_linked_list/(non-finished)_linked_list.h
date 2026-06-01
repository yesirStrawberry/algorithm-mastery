#ifndef __linked_list
#define __linked_list

#include "member.h"


/* header for source
#include <stdlib.h>
#include <stdio.h>
*/

typedef struct __node{
    member data; 
    struct __node *next; 
}Node; 

typedef struct{
    Node *head; 
    Node *crnt;
}List;

static Node* alloc_node(void){
    Node *new_node = calloc(1, sizeof(Node)); 
    if (new_node == NULL) {
        // 유언...
        fprintf(stderr, "[CRITICAL ERROR] Failed to allocate memory in alloc_node().\n");
        return NULL;
    }
    
    return new_node; 
}

static void set_node(Node *n, const member *x, const Node *next){
    if(n == NULL) return; 
    if(x != NULL) n->data = *x; 
    n->next = next; 
    return; 
}

void init_list(List list){
    if(list == NULL) return; 
    list->crnt = NULL; 
    list->head = NULL; 
}

Node* search(List *list, const member* x, int compare(const member *x, const member *y)){
    if(list->head == NULL) return NULL;
    Node *ptr = list->head; 
    while(ptr != NULL){
        if(compare(&(ptr->date), x) == 0){
            list->crnt = ptr; 
            return ptr; 
        }
        ptr = ptr->next; 
    }
    return NULL;
}

void insert_front(List *list, const member *x){
    Node *ptr = list->head; 
    list->head = list->crnt = alloc_node(); 
    set_node(list->head, x, ptr); 
}

void insert_reer(List *list, const member *x){
    if(list->head == NULL){
        insert_front(list, x); 
        return; 
    }
    
    Node *ptr = list->head; 
    while(ptr->next != NULL){
        ptr = ptr->next; 
    }
    
    ptr->next = list->crnt = alloc_node();
    set_node(ptr->next, x, NULL); 
}

void remove_front(List *list){
    if(list->head == NULL) return; 
    
    Node *ptr = list->head->next; 
    free(list->head);
    list->head = list->crnt = ptr; 
}

void remove_reer(List *list){
    if(list->head == NULL) return; 
    if(list->head->next == NULL){
        remove_front(list);
        return; 
    }
    Node *ptr = list->head; 
    Node *pre; 
    
    while(ptr->next != NULL){
        pre = ptr; 
        ptr = ptr->next; 
    }
    set_node(pre, pre->data, NULL);
    list->crnt = pre; 
    free(ptr); 
}

void remove_current(List *list){
    if(list->head == NULL) return; 
    if(list->head->next == NULL) {
        remove_front(list);
        return;
    } 
    
    // find pre
    Node *ptr = list->head;
    Node *pre;
    while(ptr != list->crnt){
        pre = ptr; 
        ptr = ptr->next; 
    }
    
    // cut current node; 
    set_node(pre, pre->data, ptr->next); 
    list->crnt = pre; 
    free(ptr); 
}

void clear(List *list){
    while(list->head != NULL){
        remove_front(list); 
    }
    list->crnt = NULL; 
}

void print_node(const List *list){
    if(list->crnt == NULL) return; 
    print_member(&list->crnt->data);
    return;
}

void print_list(const List *list){
    if(list->head == NULL) return; 
    node *ptr = list->head; 
    while(ptr->next != NULL){
        print_member(&pre->data); 
        ptr = ptr->next; 
    }
    return; 
}

void terminate_list(List *list){
    clear(list); 
    return; 
}

#endif /*__linked_list*/



























