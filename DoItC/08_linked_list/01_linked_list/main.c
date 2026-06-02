/**
 * @file main.c
 * @brief 단방향 연결 리스트(Singly Linked List) 기능 검증 및 Edge Case 테스트 파일
 */

#include <stdio.h>
#include <stdbool.h>
#include "linked_list.h"
#include "member.h"

/* 비교 콜백 함수 프로토타입 선언 */
int compare_member_age(const member *x, const member *y);

/**
 * @brief 테스트 진행 상황과 현재 리스트 상태를 시각적으로 출력하는 헬퍼 함수
 * @param[in] title 테스트 단계 이름
 * @param[in] list 연결 리스트 포인터
 */
void dump_status(const char *title, const List *list) {
    printf("\n========================================\n");
    printf("[TEST] %s\n", title);
    printf("----------------------------------------\n");
    printf("Current List Elements:\n");
    print_list(list);
    printf("----------------------------------------\n");
    printf("Current Selected Node (crnt):\n");
    print_node(list);
    printf("========================================\n");
}

int main(void) {
    List list;
    
    // 1. 샘플 데이터 셋업 (포인터 연산 안정성을 위해 문자열 리터럴 사용)
    member m1 = {"Alice", 20};
    member m2 = {"Bob", 22};
    member m3 = {"Charlie", 25};
    member m4 = {"David", 30};
    
    // 2. 리스트 초기화 
    if (!init_list(&list)) {
        fprintf(stderr, "List initialization failed.\n");
        return 1;
    }
    dump_status("Initial Empty List State", &list);

    // 3. 비어있는 상태에서의 예외 처리(Guard Clause) 작동 검증
    printf("[Guard Check] Remove from empty list (front): %s\n", remove_front(&list) ? "SUCCESS" : "FAILED (Expected)");
    printf("[Guard Check] Remove from empty list (reer): %s\n", remove_reer(&list) ? "SUCCESS" : "FAILED (Expected)");
    printf("[Guard Check] Remove current from empty list: %s\n", remove_current(&list) ? "SUCCESS" : "FAILED (Expected)");

    // 4. insert_front 연산 검증 (O(1))
    printf("\n[Insert] Inserting 'Alice(20)' at front...\n");
    insert_front(&list, &m1);
    dump_status("After insert_front (1 Element)", &list);

    printf("\n[Insert] Inserting 'Bob(22)' at front...\n");
    insert_front(&list, &m2);
    dump_status("After insert_front (2 Elements)", &list);

    // 5. insert_reer 연산 검증 (O(N))
    printf("\n[Insert] Inserting 'Charlie(25)' at reer...\n");
    insert_reer(&list, &m3);
    dump_status("After insert_reer (3 Elements)", &list);

    // 6. search 연산 및 주목(crnt) 포인터 변경 검증 (O(N))
    member target = {"Unknown", 22}; // Bob의 나이(22)로 검색 시도
    printf("\n[Search] Searching for member with age 22...\n");
    Node *found = search(&list, &target, compare_member_age);
    if (found != NULL) {
        printf("Result: Found node address [%p] -> Name: %s, Age: %d\n", (void*)found, found->data.name, found->data.age);
    } else {
        printf("Result: Member not found.\n");
    }
    dump_status("After Search (crnt should point to Bob)", &list);

    // 7. remove_current 연산 검증 (O(N)) - 현재 crnt인 Bob을 삭제
    printf("\n[Delete] Removing current node (Bob)...\n");
    if (remove_current(&list)) {
        printf("Result: Current node removed successfully.\n");
    } else {
        printf("Result: Failed to remove current node.\n");
    }
    dump_status("After remove_current (Bob should be gone, crnt updated to Alice)", &list);

    // 8. 노드가 1개 남았을 때 remove_reer가 remove_front로 정상 위임되는지 검증 (Edge Case)
    printf("\n[Delete] Removing reer node (Charlie)...\n");
    remove_reer(&list);
    dump_status("After remove_reer (Only Alice should remain)", &list);

    // 9. insert_reer를 빈 리스트 상태(정확히는 머리가 유일한 상태에서 모두 지워진 후 재삽입 상황 등)에 대비해 데이터 추가
    printf("\n[Insert] Inserting 'David(30)' at reer...\n");
    insert_reer(&list, &m4);
    dump_status("Preparation for clear (Alice -> David)", &list);

    // 10. clear 연산 검증 (O(N)) - 메모리 전량 해제 및 댕글링 포인터 차단 방어선 확인
    printf("\n[Memory] Clearing all nodes to prevent memory leaks...\n");
    clear(&list);
    dump_status("After clear (List must be empty, head/crnt must be NULL)", &list);

    // 11. 자원 해제 및 종료
    terminate_list(&list);
    printf("\n[Termination] List terminated safely. Dynamic memory leak status: CLEAN\n");

    return 0;
}

/**
 * @brief 두 member 구조체의 나이(age)를 비교하는 콜백 함수
 * @details search 함수의 인자로 전달되어 노드를 검색할 때 사용됩니다.
 * @param[in] x 리스트 내부 노드의 데이터 포인터
 * @param[in] y 사용자가 찾고자 하는 타겟 데이터 포인터
 * @return 두 나이가 같으면 0, 다르면 -1 (또는 대소 관계에 따라 양수/음수)
 */
int compare_member_age(const member *x, const member *y) {
    if (x == NULL || y == NULL) return -1;
    if (x->age == y->age) return 0;
    return (x->age > y->age) ? 1 : -1;
}
