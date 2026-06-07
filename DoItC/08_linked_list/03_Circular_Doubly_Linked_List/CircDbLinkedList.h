/**
 * @file CircDbLinkedList.h
 * @brief 원형 이중 연결 리스트(Circular Doubly Linked List) 라이브러리 헤더
 * @details 더미 노드(Dummy Node)를 활용하여 삽입/삭제 시의 예외 처리를 최소화하고,
 * 경계면에서도 안전하게 순환할 수 있도록 설계된 원형 이중 연결 리스트입니다.
 */

#ifndef CIRC_DB_LINKED_LIST_H
#define CIRC_DB_LINKED_LIST_H

#include "member.h"

/**
 * @struct __node
 * @brief 원형 이중 연결 리스트의 노드 구조체
 */
typedef struct __node {
    member data;           /**< 데이터 필드 (member 타입) */
    struct __node *next;   /**< 다음 노드를 가리키는 포인터 */
    struct __node *prev;   /**< 이전 노드를 가리키는 포인터 */
} Dnode;

/**
 * @struct Dlist
 * @brief 원형 이중 연결 리스트 관리 구조체
 */
typedef struct {
    Dnode *head;           /**< 리스트의 더미 노드(Dummy Node)를 가리키는 포인터 */
    Dnode *crnt;           /**< 현재 선택된 노드(Current Node)를 가리키는 포인터 */
} Dlist;

/* ========================================================================== */
/* 초기화 및 해제 함수 목록                          */
/* ========================================================================== */

/**
 * @brief 원형 이중 연결 리스트를 초기화합니다.
 * @param list 초기화할 리스트의 포인터
 * @details 내부적으로 내부 동적 할당 함수를 통해 더미 노드를 생성합니다.
 * 초기 상태에서 더미 노드의 prev와 next는 자기 자신을 가리키며, 
 * crnt 포인터 역시 더미 노드를 가리키도록 설정됩니다.
 */
void init_Dlist(Dlist *list);

/**
 * @brief 리스트 내의 모든 데이터 노드를 삭제하고 비웁니다.
 * @param list 비울 리스트의 포인터
 * @details 더미 노드를 제외한 모든 진짜 데이터 노드를 순차적으로 메모리 해제합니다.
 * 동작이 완료되면 리스트는 비어있는(Empty) 상태가 되며 crnt는 head를 가리킵니다.
 */
void clear(Dlist *list);

/**
 * @brief 원형 이중 연결 리스트의 사용을 종료하고 메모리를 완전히 해제합니다.
 * @param list 종료할 리스트의 포인터
 * @details clear() 함수를 호출하여 모든 데이터 노드를 해제한 후, 
 * 마지막으로 남아있는 기준점인 더미 노드(head)까지 안전하게 free합니다.
 */
void terminate_Dlist(Dlist *list);

/* ========================================================================== */
/* 탐색 및 포인터 이동 함수                          */
/* ========================================================================== */

/**
 * @brief 조건에 맞는 데이터 노드를 순방향으로 검색합니다.
 * @param list 검색할 리스트의 포인터
 * @param x 검색하고자 하는 키 데이터의 포인터
 * @param compr 데이터를 비교할 함수 포인터 (두 데이터가 같으면 0을 반환해야 함)
 * @return 검색된 노드의 포인터 (찾지 못한 경우 NULL 반환)
 * @details head->next(첫 번째 데이터 노드)부터 시작하여 한 바퀴 돌아 head로 
 * 돌아올 때까지 일치하는 데이터를 찾습니다. 일치하는 노드를 찾으면 
 * crnt를 해당 노드로 갱신한 후 주소를 반환합니다.
 */
Dnode* search(Dlist *list, const member *x,
              int compr(const member *x, const member *y));

/**
 * @brief 현재 주목 노드(crnt)를 다음 노드로 이동시킵니다.
 * @param list 이동할 리스트의 포인터
 * @return 이동 성공 시 1, 리스트가 비어있어 실패 시 0 반환
 * @details 만약 이동할 다음 노드가 더미 노드(head)일 경우, 사용자가 더미 노드에 
 * 접근하지 않도록 무시하고 head->next(첫 번째 데이터 노드)로 건너뛰어 
 * 자연스러운 원형 순환이 이뤄지도록 처리합니다.
 */
int move_next(Dlist *list);

/**
 * @brief 현재 주목 노드(crnt)를 이전 노드로 이동시킵니다.
 * @param list 이동할 리스트의 포인터
 * @return 이동 성공 시 1, 리스트가 비어있어 실패 시 0 반환
 * @details 만약 이동할 이전 노드가 더미 노드(head)일 경우, 사용자가 더미 노드에 
 * 접근하지 않도록 무시하고 head->prev(마지막 데이터 노드)로 건너뛰어 
 * 자연스러운 역방향 원형 순환이 이뤄지도록 처리합니다.
 */
int move_prev(Dlist *list);

/* ========================================================================== */
/* 삽입 함수 목록                             */
/* ========================================================================== */

/**
 * @brief 지정한 노드(n)의 바로 뒤에 새로운 데이터를 삽입합니다.
 * @param list 리스트의 포인터
 * @param n 기준이 되는 노드의 포인터
 * @param x 삽입할 새로운 데이터의 포인터
 * @details 새 노드를 동적 할당한 뒤, 기존 n 노드와 n->next 노드 사이의 
 * 양방향 링크 관계를 안전하게 깨뜨리지 않고 중간에 끼워 넣습니다.
 * 삽입이 성공하면 crnt는 새로 삽입된 노드를 가리킵니다.
 */
void insert_after(Dlist *list, Dnode *n, const member *x);

/**
 * @brief 리스트의 맨 앞(첫 번째 데이터 노드 자리)에 데이터를 삽입합니다.
 * @param list 리스트의 포인터
 * @param x 삽입할 새로운 데이터의 포인터
 * @details 내부적으로 insert_after()를 재사용하여 더미 노드(head)의 
 * 바로 뒤에 새 노드를 배치합니다.
 */
void insert_front(Dlist *list, const member *x);

/**
 * @brief 리스트의 맨 뒤(마지막 데이터 노드 자리)에 데이터를 삽입합니다.
 * @param list 리스트의 포인터
 * @param x 삽입할 새로운 데이터의 포인터
 * @details 내부적으로 insert_after()를 재사용하여 마지막 노드인 
 * head->prev 노드의 바로 뒤에 새 노드를 배치합니다.
 */
void insert_rear(Dlist *list, const member *x);

/* ========================================================================== */
/* 삭제 함수 목록                             */
/* ========================================================================== */

/**
 * @brief 지정한 특정 노드(n)를 리스트에서 안전하게 삭제하고 메모리를 해제합니다.
 * @param list 리스트의 포인터
 * @param n 삭제할 노드의 포인터
 * @details 대상 노드의 앞뒤 링크를 직접 연결해 노드를 고립시킨 뒤 free합니다.
 * 삭제 후 crnt는 n->prev로 이동하되, 만약 이로 인해 crnt가 head가 되고 
 * 리스트에 다른 데이터가 남아있다면 head->next로 자동 보정됩니다.
 * @note 삭제하려는 노드(n)가 더미 노드(head)일 경우 경고 문구를 출력하고 
 * 해당 요청을 거부하는 방어 코드가 포함되어 있습니다.
 */
void remove_Dnode(Dlist *list, Dnode *n);

/**
 * @brief 리스트의 맨 앞 노드(첫 번째 데이터 노드)를 삭제합니다.
 * @param list 리스트의 포인터
 * @details 리스트가 비어있지 않다면 head->next 노드를 remove_Dnode()로 전달하여 삭제합니다.
 */
void remove_front(Dlist *list);

/**
 * @brief 리스트의 맨 뒤 노드(마지막 데이터 노드)를 삭제합니다.
 * @param list 리스트의 포인터
 * @details 리스트가 비어있지 않다면 head->prev 노드를 remove_Dnode()로 전달하여 삭제합니다.
 */
void remove_rear(Dlist *list);

/**
 * @brief 현재 주목하고 있는 노드(crnt)를 리스트에서 삭제합니다.
 * @param list 리스트의 포인터
 * @details 주목 노드가 유효하고 더미 노드(head)가 아닐 때만 remove_Dnode()를 호출해 제거합니다.
 */
void remove_current(Dlist *list);

/* ========================================================================== */
/* 출력 함수 목록                             */
/* ========================================================================== */

/**
 * @brief 단일 노드의 상세 정보와 메모리 주소 링크 상태를 출력합니다.
 * @param n 출력할 노드의 포인터
 * @details 개별 노드가 가지고 있는 member 데이터 내용과 함께 해당 노드의 주소, 
 * next 주소, prev 주소를 완전한 포인터 형태(%p)로 출력하여 
 * 구조적 무결성을 디버깅할 수 있게 돕습니다.
 */
void print_Dnode(const Dnode *n);

/**
 * @brief 현재 주목하고 있는 노드(crnt)의 정보를 출력합니다.
 * @param list 리스트의 포인터
 * @details 리스트가 비어있거나 crnt가 유효하지 않은 노드(head 등)를 가리킨다면 
 * 안내 메시지를 출력하고, 그렇지 않으면 주목 노드를 상세 출력합니다.
 */
void print_current(const Dlist *list);

/**
 * @brief 리스트 내의 모든 데이터 노드를 순방향으로 출력합니다.
 * @param list 출력할 리스트의 포인터
 * @details head->next 노드부터 시작하여 순방향(next)으로 원형 회전하며 
 * head를 다시 만날 때까지 존재하는 모든 데이터 노드를 출력합니다.
 */
void print_list(const Dlist *list);

/**
 * @brief 리스트 내의 모든 데이터 노드를 역방향으로 출력합니다.
 * @param list 출력할 리스트의 포인터
 * @details head->prev 노드부터 시작하여 역방향(prev)으로 역회전하며 
 * head를 다시 만날 때까지 존재하는 모든 데이터 노드를 역순으로 출력합니다.
 */
void print_list_rsv(const Dlist *list);

#endif /* CIRC_DB_LINKED_LIST_H */