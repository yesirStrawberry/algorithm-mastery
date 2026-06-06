#include <stdlib.h>
#include <stdio.h>
#include "ArrayLinkedList.h"
#include "member.h"

// 삽입할 record의 index를 반환한다. 
static Index get_index(List *list){
    if(list->deleted == null){
        if(list->max + 1 >= list->size){
            printf("can't insert\n"); 
            return null; 
        }
        list->max += 1; 
        return list->max; 
    }
    Index rec = list->deleted; 
    list->deleted = list->arr[rec].next; 
    return rec; 
}

// delete array에 선택 idx를 집어넣는다. 
static void delete_index(List *list, Index idx){
    Index tmp = list->deleted; 
    list->deleted = idx; 
    list->arr[idx].next = tmp; 
}

static void set_node(Node *n, const member *x, Index idx){
    n->data = *x; 
    n->next = idx; 
}

void init_list(List *list, Index size){
    if(size <= 0){
        fprintf(stderr, "[ERROR] size is too small.\n");
        return; 
    }
    list->arr = calloc(size, sizeof(Node)); 
    if(list->arr == NULL){
        fprintf(stderr, "[ERROR] Failed to allocate memory in init_list.\n");
        return; 
    }
    
    list->size = size; 
    list->head = null;
    list->crnt = null;
    list->max = null; 
    list->deleted = null;
}

Index search(List *list, const member *x, int compr(const member *x, const member *y)){
    Index idx = list->head; 
    while(idx != null){
        if(compr(x, &list->arr[idx].data) == 0){
            list->crnt = idx; 
            return idx; 
        }
        idx = list->arr[idx].next; 
    }
    return null; 
}

void insert_front(List *list, const member *x){
    if(list == NULL) return;
    
    Index tmp = list->head; 
    Index new_head = get_index(list); 
    
    if(new_head == null) return; 
    
    list->head = new_head; 
    list->crnt = new_head; 
    set_node(&list->arr[new_head], x, tmp); 
}

void insert_rear(List *list, const member *x){
    if(list == NULL) return; 
    if(list->head == null){
        insert_front(list, x); 
        return; 
    }
    
    Index tmp = list->head;  
    while(list->arr[tmp].next != null){
        tmp = list->arr[tmp].next; 
    }
    Index new_rear = get_index(list); 
    
    if(new_rear == null) return; 
    
    list->arr[tmp].next = new_rear; 
    list->crnt = new_rear;
    
    set_node(&list->arr[new_rear], x, null);
}


void remove_front(List *list){
    if(list == NULL || list->head == null) return;
    
    Index new_head = list->arr[list->head].next; 
    delete_index(list, list->head);
    list->head = new_head; 
    list->crnt = new_head; 
}

void remove_rear(List *list){
    if(list == NULL || list->head == null) return; 
    
    // 1. ele == 1 -> remove_front
    if(list->arr[list->head].next == null){
        remove_front(list); 
        return;
    }
    // 2. pre, rear 찾기
    Index pre; 
    Index rear = list->head; 
    while(list->arr[rear].next != null){
        pre = rear; 
        rear = list->arr[rear].next; 
    }
    // 3. rear darray에 올리기
    delete_index(list, rear); 
    
    // 4. pre를 rear로 만들기
    list->arr[pre].next = null; 
    list->crnt = pre; 
}

void remove_current(List *list){
    if(list == NULL || list->head == null) return; 
    if(list->arr[list->head].next == null || list->head == list->crnt){
        remove_front(list); 
        return; 
    }
    
    Index tmp = list->head; 
    while(list->arr[tmp].next != list->crnt){
        tmp = list->arr[tmp].next; 
    }
    
    list->arr[tmp].next = list->arr[list->crnt].next; 
    delete_index(list, list->crnt);
    
    list->crnt = tmp; 
}

void clear(List *list){
    if(list == NULL) return; 
    puts("clear");
    
    while(list->head != null){
        remove_front(list); 
    }
}

void print_node(const List *list){
    if(list == NULL || list->crnt == null){
        puts("list->crnt : NULL"); 
        return; 
    }
    
    puts("--------------");
    puts("print_node"); 
    print_member(&list->arr[list->crnt].data);
    printf("next  : %d\n", list->arr[list->crnt].next);
    return; 
}

void print_list(const List *list){
    if(list == NULL || list->head == null){
        puts("empty list");
        return; 
    }
    puts("--------------");
    puts("print_list");
    
    Index tmp = list->head; 
    while(tmp != null){
        print_member(&list->arr[tmp].data);
        printf("next  : %d\n", list->arr[tmp].next);
        tmp = list->arr[tmp].next; 
    }
    return; 
}

void print_array(const List *list){
    if(list == NULL || list->head == null){
        puts("empty list");
        return; 
    }
    
    puts("--------------");
    puts("print array"); 
    for(int i = 0; i <= list->max; i++){
        puts("--------------");
        printf("idx : %d\n", i); 
        print_member(&list->arr[i].data);
        printf("next  : %d\n", list->arr[i].next);
    }
}

void terminate_list(List *list){
    if(list == NULL) return; 
    clear(list); 
    free(list->arr); 
}
