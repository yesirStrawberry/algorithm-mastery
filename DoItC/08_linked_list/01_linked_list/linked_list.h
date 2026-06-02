/**
 * @file linked_list.h
 * @brief 단방향 연결 리스트(Singly Linked List)의 인터페이스를 정의하는 헤더 파일
 */

#ifndef __linked_list
#define __linked_list

#include <stdbool.h>
#include "member.h"

/**
 * @struct __node
 * @brief 연결 리스트를 구성하는 개별 노드 구조체
 */
typedef struct __node {
    member data;           /**< 노드에 저장될 회원 데이터 */
    struct __node *next;   /**< 다음 노드를 가리키는 포인터 */
} Node; 

/**
 * @struct List
 * @brief 연결 리스트 관리 구조체
 */
typedef struct {
    Node *head;            /**< 리스트의 첫 번째 노드를 가리키는 포인터 */
    Node *crnt;            /**< 현재 주목(선택)하고 있는 노드를 가리키는 포인터 */
} List;

/**
 * @brief 연결 리스트를 초기화합니다.
 * @param[out] list 초기화할 리스트 포인터
 * @return 초기화 성공 시 true, list가 NULL이면 false 반환
 */
bool init_list(List *list);

/**
 * @brief 비교 함수를 기반으로 리스트 내부의 노드를 선형 검색합니다.
 * @details 검색 성공 시 해당 노드를 주목(crnt) 포인터로 설정합니다. (시간 복잡도: O(N))
 * @param[in,out] list 검색을 진행할 리스트 포인터
 * @param[in] x 찾고자 하는 타겟 데이터 포인터
 * @param[in] compare 데이터 비교를 위한 콜백 함수 포인터 (일치 시 0 반환)
 * @return 일치하는 데이터가 있는 노드의 주소값, 리스트가 비어있거나 찾지 못하면 NULL 반환
 */
Node* search(List *list, const member* x, int compare(const member *x, const member *y));

/**
 * @brief 리스트의 맨 앞(head)에 새로운 노드를 삽입합니다.
 * @details 삽입된 새 노드가 머리(head)이자 주목(crnt) 노드가 됩니다. (시간 복잡도: O(1))
 * @param[in,out] list 삽입을 진행할 리스트 포인터
 * @param[in] x 삽입할 데이터 포인터
 * @return 삽입 성공 시 true, 인자가 NULL이거나 메모리 할당 실패 시 false 반환
 */
bool insert_front(List *list, const member *x);

/**
 * @brief 리스트의 맨 끝(tail)에 새로운 노드를 삽입합니다.
 * @details 리스트가 비어있으면 insert_front를 수행하며, 삽입 완료 후 새 노드가 주목(crnt) 노드가 됩니다. (시간 복잡도: O(N))
 * @param[in,out] list 삽입을 진행할 리스트 포인터
 * @param[in] x 삽입할 데이터 포인터
 * @return 삽입 성공 시 true, 메모리 할당 실패나 노드 세팅 실패 시 false 반환
 */
bool insert_reer(List *list, const member *x);

/**
 * @brief 리스트의 맨 앞(head) 노드를 삭제합니다.
 * @details 삭제 후 head와 crnt 포인터는 기존 머리의 다음 노드로 이동합니다. (시간 복잡도: O(1))
 * @param[in,out] list 삭제를 진행할 리스트 포인터
 * @return 삭제 성공 시 true, 리스트가 비어있거나 NULL이면 false 반환
 */
bool remove_front(List *list);

/**
 * @brief 리스트의 맨 끝(tail) 노드를 삭제합니다.
 * @details 노드가 1개만 존재할 경우 remove_front로 위임합니다. 삭제 완료 후 crnt는 tail 이전 노드를 가리킵니다. (시간 복잡도: O(N))
 * @param[in,out] list 삭제를 진행할 리스트 포인터
 * @return 삭제 성공 시 true, 리스트가 비어있으면 false 반환
 */
bool remove_reer(List *list);

/**
 * @brief 현재 주목(crnt)하고 있는 노드를 삭제합니다.
 * @details 머리 노드가 crnt이거나 노드가 1개뿐이면 remove_front를 수행합니다. 삭제 완료 후 crnt는 이전 노드로 후퇴합니다. (시간 복잡도: O(N))
 * @param[in,out] list 삭제를 진행할 리스트 포인터
 * @return 삭제 성공 시 true, 리스트가 비어있으면 false 반환
 */
bool remove_current(List *list);

/**
 * @brief 리스트 내부의 모든 노드를 순회하며 동적 할당을 해제(free)합니다.
 * @details 완료 후 head와 crnt 포인터는 전량 NULL로 초기화됩니다. (시간 복잡도: O(N))
 * @param[in,out] list 비울 리스트 포인터
 */
void clear(List *list);

/**
 * @brief 현재 주목(crnt)하고 있는 노드의 데이터를 표준 출력(stdout)에 표시합니다.
 * @param[in] list 출력할 리스트 포인터
 */
void print_node(const List *list);

/**
 * @brief 리스트 내 머리(head)부터 끝(tail)까지의 모든 노드 데이터를 순차적으로 출력합니다.
 * @param[in] list 출력할 리스트 포인터
 */
void print_list(const List *list);

/**
 * @brief 연결 리스트 사용을 종료하고 자원을 해제합니다.
 * @details 내부적으로 clear() 함수를 호출하여 메모리 누수를 원천 차단합니다.
 * @param[in,out] list 종료할 리스트 포인터
 */
void terminate_list(List *list); 

#endif
