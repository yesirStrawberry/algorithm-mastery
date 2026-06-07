#include <stdio.h>
#include <stdlib.h>
#include "CircDbLinkedList.h"

/**
 * @brief 새로운 데이터 노드를 동적 할당 및 초기화합니다.
 * @return 할당 성공 시 생성된 노드의 포인터, 메모리 할당 실패 시 NULL 반환
 * @details calloc을 사용하여 노드의 모든 멤버(data, next, prev)를 
 * 0(NULL)으로 안전하게 초기화하며 동적 할당을 수행합니다.
 * 할당 실패 시 표준 에러 스트림(stderr)으로 로그를 출력합니다.
 */
static Dnode* alloc_Dnode() {
	Dnode *new_node = calloc(1, sizeof(Dnode));
	if(new_node == NULL) {
		fprintf(stderr, "Error : alloc_Dnode Failed\n");
		return NULL;
	}
	return new_node;
}

/**
 * @brief 지정된 노드의 데이터 필드와 양방향 링크 포인터를 설정합니다.
 * @param n 설정을 변경할 대상 노드의 포인터
 * @param data 노드에 저장할 원본 member 데이터의 포인터
 * @param prev 대상 노드의 이전 노드(prev)로 연결할 주소
 * @param next 대상 노드의 다음 노드(next)로 연결할 주소
 * @details 인자로 받은 데이터의 값을 대상 노드에 복사하고, 
 * 앞뒤 노드와의 링크 관계를 한 번에 매핑해 주는 헬퍼 함수입니다.
 */
static void set_Dnode(Dnode *n, const member *data, Dnode *prev, Dnode *next) {
	n->data = *data;
	n->prev = prev;
	n->next = next;
}

/**
 * @brief 원형 이중 연결 리스트가 비어있는 상태인지 확인합니다.
 * @param list 검사할 리스트의 포인터
 * @return 리스트가 비어있으면 1(참), 데이터 노드가 존재하면 0(거짓) 반환
 * @details 더미 노드(head)의 다음 노드 포인터(next)가 다시 더미 노드 자신을 
 * 가리키고 있는지 여부를 판별하여 리스트의 빈 상태를 체크합니다.
 */
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




































