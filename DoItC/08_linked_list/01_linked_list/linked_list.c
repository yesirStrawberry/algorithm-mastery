#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linked_list.h"

static Node* alloc_node(void){
    Node *new_node = calloc(1, sizeof(Node)); 
    if (new_node == NULL) {
        // 유언...
        fprintf(stderr, "[ERROR] Failed to allocate memory in alloc_node().\n");
        return NULL;
    }
    
    return new_node; 
}

static bool set_node(Node *n, const member *x, const Node *next){
    if(n == NULL || x == NULL) return false; 
    n->data = *x; 
    n->next = (Node*)next; 
    return true; 
}

bool init_list(List *list){
    if(list == NULL) return false; 
    list->crnt = NULL; 
    list->head = NULL; 
    return true; 
}

Node* search(List *list, const member* x, int compare(const member *x, const member *y)){
    if(list->head == NULL) return NULL;
    
    Node *ptr = list->head; 
    while(ptr != NULL){
        if(compare(&ptr->data, x) == 0){
            list->crnt = ptr; 
            return ptr; 
        }
        ptr = ptr->next; 
    }
    return NULL;
}

bool insert_front(List *list, const member *x){
    if(list == NULL || x == NULL) return false; 
    
    Node *ptr = list->head; 
    Node *new_node = alloc_node();
    
    list->head = new_node; 
    list->crnt = new_node; 
    
    set_node(new_node, x, ptr); 
    return true; 
}

bool insert_reer(List *list, const member *x){
    if(list == NULL) return false;
    
    if(list->head == NULL){
        bool is_non_error = insert_front(list, x); 
        return is_non_error; 
    }
    
    // 기존 tail node : ptr 찾기
    Node *ptr = list->head; 
    while(ptr->next != NULL){
        ptr = ptr->next; 
    }
    
    // 새로운 tail node : new_node 생성
    Node *new_node = alloc_node(); 
    if(new_node == NULL) return false; 
    
    ptr->next = new_node;
    list->crnt = new_node; 
    
    bool is_set_node_true = set_node(new_node, x, NULL); 
    if(is_set_node_true) return false;  
    return true; 
}

bool remove_front(List *list){
    if(list == NULL || list->head == NULL) return false; 

    Node *ptr = list->head; 
    list->head = list->crnt = list->head->next; 

    free(ptr);
    return true; 
}

bool remove_reer(List *list){
    if(list->head == NULL) return false; 
    if(list->head->next == NULL){
        bool is_non_error = remove_front(list);
        return is_non_error; 
    }
    
    // ptr : tail, pre : tail - 1; 
    Node *ptr = list->head; 
    Node *pre; 
    while(ptr->next != NULL){
        pre = ptr; 
        ptr = ptr->next; 
    }
    
    // cut tail
    set_node(pre, &pre->data, NULL);
    list->crnt = pre; 
    free(ptr); 
    
    return true;
}

bool remove_current(List *list){
    if(list->head == NULL) return false; 
    if(list->head->next == NULL || list->head == list->crnt) {
        bool is_non_error = remove_front(list);
        return is_non_error;
    } 
    
    // ptr : crnt, pre : crnt - 1
    Node *ptr = list->head;
    Node *pre;
    while(ptr != list->crnt){
        pre = ptr; 
        ptr = ptr->next; 
    }
    
    // cut current node; 
    set_node(pre, &pre->data, ptr->next); 
    list->crnt = pre; 
    free(ptr); 
    
    return true; 
}

void clear(List *list){
    if(list == NULL) return; 

    Node *ptr = list->head; 
    while(ptr != NULL){
        Node *next_ptr = ptr->next; 
        free(ptr); 
        ptr = next_ptr; 
    }
    list->head = NULL; 
    list->crnt = NULL; 
}

void print_node(const List *list){
    if(list->crnt == NULL){
        puts("list->crnt : NULL"); 
        return; 
    } 
    puts("--------------");
    puts("print_node");
    print_member(&list->crnt->data);
    printf("next : %lo\n", list->crnt->next);
    return;
}

void print_list(const List *list){
    if(list == NULL|| list->head == NULL) {
        puts("empty list");
        return;
    } 
    Node *ptr = list->head; 
    puts("--------------");
    puts("print_list");
    while(ptr != NULL){
        print_member(&ptr->data); 
        printf("next : %lo\n", ptr->next);
        ptr = ptr->next; 
    }
    return; 
}

void terminate_list(List *list){
    clear(list); 
    return; 
}
