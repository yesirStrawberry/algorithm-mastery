/**
 * @file ArrayLinkedList.h
 * @brief 배열을 이용한 선형 연결 리스트(Array-Based Linked List) 구현 헤더
 * @details 단일 'next' 필드만을 공유하여 사용 중인 노드 체인(Active List)과
 * 삭제된 노드 빈 공간 체인(Free List)을 효율적으로 제어하는 구조를 가집니다.
 * 동적 할당 오버헤드를 최소화하고 메모리 공간 재활용을 보장합니다.
 */

#ifndef __ArrayLinkedList
#define __ArrayLinkedList

#include "member.h"

/**
 * @brief 비어있는 포인터(인덱스)를 나타내는 매크로 상숫값
 */
#define null -1

/**
 * @brief 배열 내의 위치를 지칭하는 인덱스 타입 정의
 */
typedef int Index; 

/**
 * @brief 리스트를 구성하는 개별 노드 구조체
 * @details 노드의 논리적 상태에 따라 next 변수의 의미가 다르게 해석됩니다.
 * - 사용 중(Active): 실제 선형 리스트 상의 다음 데이터 노드 인덱스
 * - 삭제됨(Free): Free List 상에서 다음에 재사용할 빈 노드 인덱스
 */
typedef struct {
    member data;  /**< 회원 정보 데이터 */
    Index next;   /**< 다음 노드 혹은 다음 빈 공간을 가리키는 인덱스 포인터 */
} Node; 

/**
 * @brief 배열 연결 리스트를 관리하는 메인 제어 구조체
 */
typedef struct {
    Node *arr;     /**< 노드들을 저장할 동적 배열의 시작 주소 */
    Index size;    /**< 할당된 동적 배열의 최대 수용 크기 */
    Index head;    /**< 리스트의 첫 번째 노드를 가리키는 인덱스 */
    Index crnt;    /**< 현재 주목(선택)하고 있는 노드의 인덱스 */
    Index max;     /**< 사용 이력이 있는 배열 공간 중 가장 큰 인덱스 상한선 */
    Index deleted; /**< 삭제된 빈 공간 체인(Free List)의 머리(Head) 인덱스 */
} List;

/**
 * @brief 리스트 관리 구조체 및 내부 동적 배열을 초기화합니다.
 * @param list 초기화할 리스트 구조체의 포인터
 * @param size 리스트가 수용할 수 있는 최대 노드 개수 (배열 크기)
 */
void init_list(List *list, Index size);

/**
 * @brief 리스트 내에서 조건에 맞는 데이터를 검색합니다.
 * @details 검색에 성공하면 리스트의 현재 주목 노드(crnt)가 해당 위치로 갱신됩니다.
 * @param list 검색을 수행할 리스트 구조체의 포인터
 * @param x 검색 기준이 될 데이터가 담긴 member 구조체의 포인터
 * @param compr 두 데이터를 비교하여 일치하면 0을 반환하는 콜백 함수 포인터
 * @return 검색된 노드의 배열 인덱스 (찾지 못한 경우 null 반환)
 */
Index search(List *list, const member *x, int compr(const member *x, const member *y));

/**
 * @brief 리스트의 맨 앞(Head 포지션)에 새로운 데이터를 삽입합니다.
 * @details Free List(deleted)에 자원이 있으면 우선 재활용하고, 없으면 max를 증가시켜 할당합니다.
 * @param list 삽입을 수행할 리스트 구조체의 포인터
 * @param x 리스트에 새롭게 추가할 데이터의 포인터
 */
void insert_front(List *list, const member *x);

/**
 * @brief 리스트의 맨 뒤(Tail 포지션)에 새로운 데이터를 삽입합니다.
 * @details Free List(deleted)에 자원이 있으면 우선 재활용하고, 없으면 max를 증가시켜 할당합니다.
 * @param list 삽입을 수행할 리스트 구조체의 포인터
 * @param x 리스트에 새롭게 추가할 데이터의 포인터
 */
void insert_rear(List *list, const member *x);

/**
 * @brief 리스트의 맨 앞(Head 포지션)에 위치한 노드를 제거합니다.
 * @details 삭제된 노드의 인덱스는 가용 공간 재활용을 위해 Free List의 맨 앞으로 회수됩니다.
 * @param list 삭제를 수행할 리스트 구조체의 포인터
 */
void remove_front(List *list);

/**
 * @brief 리스트의 맨 뒤(Tail 포지션)에 위치한 노드를 제거합니다.
 * @details 삭제된 노드의 인덱스는 가용 공간 재활용을 위해 Free List의 맨 앞으로 회수됩니다.
 * @param list 삭제를 수행할 리스트 구조체의 포인터
 */
void remove_rear(List *list); 

/**
 * @brief 현재 주목(선택)하고 있는 노드(crnt)를 리스트에서 제거합니다.
 * @details 삭제된 노드의 인덱스는 가용 공간 재활용을 위해 Free List의 맨 앞으로 회수됩니다.
 * @param list 삭제를 수행할 리스트 구조체의 포인터
 */
void remove_current(List *list);

/**
 * @brief 리스트에 연결된 모든 Active 노드를 순차적으로 해제하여 빈 리스트로 만듭니다.
 * @details 모든 배열 공간은 Free List 체인으로 편입되어 재사용 가능한 상태가 됩니다.
 * @param list 전체를 비울 리스트 구조체의 포인터
 */
void clear(List *list); 

/**
 * @brief 현재 주목 노드(crnt)의 상세 정보와 연결 상태를 표준 출력에 표시합니다.
 * @param list 정보를 출력할 리스트 구조체의 포인터
 */
void print_node(const List *list);

/**
 * @brief 리스트의 Head 노드부터 순서대로 순회하며 Active 상태의 전체 데이터를 출력합니다.
 * @param list 정보를 출력할 리스트 구조체의 포인터
 */
void print_list(const List *list);

/**
 * @brief 현재 물리 배열(arr)에 할당되어 사용 중인 상한선(max)까지의 로우 데이터를 출력합니다.
 * @details 데이터를 가진 노드뿐 아니라 파편화되거나 삭제 대기 중인 인덱스의 상태까지 시각화합니다.
 * @param list 정보를 출력할 리스트 구조체의 포인터
 */
void print_array(const List *list);

/**
 * @brief 리스트의 모든 데이터를 소거하고 내부 동적 할당 배열 메모리를 완전히 해제합니다.
 * @param list 자원을 해제하고 종료할 리스트 구조체의 포인터
 */
void terminate_list(List *list); 

#endif /*__ArrayLinkedList*/
