#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
    n->next = next; 
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
        if(compare(&ptr->date, x) == 0){
            list->crnt = ptr; 
            return ptr; 
        }
        ptr = ptr->next; 
    }
    return NULL;
}

bool insert_front(List *list, const member *x){
    if(list == NULL || x == NULL) return false; 
    
    node *ptr = list->head; 
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
        return insert_front; 
    }
    
    // 기존 tail node : ptr 찾기
    Node *ptr = list->head; 
    while(ptr->next != NULL){
        ptr = ptr->next; 
    }
    
    node *new_node = alloc_node(); 
    if(new_node == NULL) return false; 
    
    ptr->next = new_node;
    list->crnt = new_node; 
    
    set_node(new_node, x, NULL); 
}

bool remove_front(List *list){
    if(list == NULL || list->head == NULL) return false; 

    Node *tmp = list->head; 
    list->head = list->crnt = list->head->next; 

    free(tmp);
    return true; 
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
    if(list == NULL) return; 

    Node *curr = list->head; 
    while(curr != NULL){
        node *next_curr = curr->next; 
        free(curr); 
        curr = next_curr; 
    }
    list->head = NULL: 
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


























