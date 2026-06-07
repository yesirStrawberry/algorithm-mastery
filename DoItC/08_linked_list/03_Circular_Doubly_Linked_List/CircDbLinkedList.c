#include <stdio.h>
#include <stdlib.h>
#include "CircDbLinkedList.h"

/*
typedef struct __node{
    member dada;
    struct __node *next;
    struct __node *prev;
}Dnode;

typedef struct{
    Dnode *head;
    Dnode *crnt;
}Dlist;
*/

static Dnode* alloc_Dnode() {
	Dnode *new_node = calloc(1, sizeof(Dnode));
	if(new_node == NULL) {
		fprintf(stderr, "Error : alloc_Dnode Failed\n");
		return NULL;
	}
	return new_node;
}

static void set_Dnode(Dnode *n, const member *data, Dnode *prev, Dnode *next) {
	n->data = *data;
	n->prev = prev;
	n->next = next;
}

static int is_empty(const Dlist *list) {
	return list->head->next == list->head;
}

void init_Dlist(Dlist *list) {
	Dnode *dummynode = alloc_Dnode();
	list->head = dummynode;
	list->crnt = dummynode;
	dummynode->prev = dummynode;
	dummynode->next = dummynode;
}

Dnode* search(Dlist *list, const member *x,
              int compr(const member *x, const member *y)) {
	Dnode* ptr = list->head->next;
	while(ptr != list->head) {
		if(compr(x, &ptr->data) == 0) {
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

int move_next(Dlist *list) {
	if(is_empty(list)) {
		return 0;
	}
	if(list->crnt->next == list->head) {
		list->crnt = list->head->next;
	} else {
		list->crnt = list->crnt->next;
	}
	return 1;
}

int move_prev(Dlist *list) {
	if(is_empty(list)) {
		return 0;
	}
	if(list->crnt->prev == list->head) {
		list->crnt = list->head->prev;
	} else {
		list->crnt = list->crnt->prev;
	}
	return 1;
}

/*insert 함수들*/

// n바로 뒤에 삽입
void insert_after(Dlist *list, Dnode *n, const member *x) {
	Dnode* new_node = alloc_Dnode();
	Dnode* new_node_next = n->next;

	n->next->prev = new_node;
	n->next = new_node;

	set_Dnode(new_node, x, n, new_node_next);
	list->crnt = new_node;
}

void insert_front(Dlist *list, const member *x) {
	insert_after(list, list->head, x);
}

void insert_rear(Dlist *list, const member *x) {
	insert_after(list, list->head->prev, x);
}

/*remove 함수들*/
void remove_Dnode(Dlist *list, Dnode *n) {
	if (n == list->head) {
		fprintf(stderr, "Warning: Cannot remove the dummy node.\n");
		return;
	}

	n->prev->next = n->next;
	n->next->prev = n->prev;
	list->crnt = n->prev;
	if(list->crnt == list->head) {
		list->crnt = list->head->next;
	}
	free(n);
}

void remove_front(Dlist *list) {
	if(!is_empty(list)) {
		remove_Dnode(list, list->head->next);
	}
}

void remove_rear(Dlist *list) {
	if(!is_empty(list)) {
		remove_Dnode(list, list->head->prev);
	}
}

void remove_current(Dlist *list) {
	if(list->crnt != list->head) {
		remove_Dnode(list, list->crnt);
	}
}

void clear(Dlist *list) {
	while(!is_empty(list)) {
		remove_front(list);
	}
}

void terminate_Dlist(Dlist *list) {
	clear(list);
	free(list->head);
}

/*print 함수들*/
void print_Dnode(const Dnode *n) {
	puts("-----------------");
	print_member(&n->data);
	printf("node address : %p\n", (void*)n);
	printf("next address : %p\n", (void*)n->next);
	printf("prev address : %p\n", (void*)n->prev);
}

void print_current(const Dlist *list) {
	if(is_empty(list) || list->crnt == list->head) {
		puts("list is empty or current node is not exist");
		return;
	}
	print_Dnode(list->crnt);
}

void print_list(const Dlist *list) {
	if(is_empty(list)) {
		puts("empty list");
		return;
	}
	Dnode *ptr = list->head->next;
	puts("-----------------");
	puts("print_list");
	while(ptr != list->head) {
		print_Dnode(ptr);
		ptr = ptr->next;
	}
}

void print_list_rsv(const Dlist *list) {
	if(is_empty(list)) {
		puts("empty list");
		return;
	}
	Dnode *ptr = list->head->prev;
	puts("-----------------");
	puts("print_list");
	while(ptr != list->head) {
		print_Dnode(ptr);
		ptr = ptr->prev;
	}
}




































