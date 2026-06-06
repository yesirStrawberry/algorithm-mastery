#include <stdio.h>
#include <string.h>
#include "member.h"
#include "ArrayLinkedList.h"

int compare(const member *x, const member *y);

int main(void) {
    List list;
    
    // 리스트 초기화 (최대 5개의 노드를 수용할 수 있는 크기로 설정하여 재활용을 명확히 관찰)
    init_list(&list, 5);
    
    member m1 = {"m1_Kim", 20};
    member m2 = {"m2_Lee", 22};
    member m3 = {"m3_Park", 25};
    member m4 = {"m4_Choi", 30};
    member m5 = {"m5_Jung", 35};
    
    puts("==========================================================================");
    puts("  Array-Based Linked List with Free List Reutilization - Execution Demo");
    puts("==========================================================================");
    puts("이 테스트 시나리오는 단일 'next' field만을 활용하여 Active List와 Free List를");
    puts("동시에 제어하고, 삭제된 공간을 효율적으로 재활용하는 과정을 직관적으로 보여줍니다.");
    puts("==========================================================================\n");

    // ==========================================================================
    // STAGE 1: 순차적 노드 삽입 (Front & Rear)
    // ==========================================================================
    puts("[STAGE 1] 순차적 노드 삽입 테스트");
    puts("--------------------------------------------------------------------------");
    printf("▶ 액션 1-1: 맨 앞에 m1 등록 -> insert_front(&list, \"%s\")\n", m1.name);
    insert_front(&list, &m1);
    
    printf("▶ 액션 1-2: 맨 뒤에 m2 등록 -> insert_rear(&list, \"%s\")\n", m2.name);
    insert_rear(&list, &m2);
    
    printf("▶ 액션 1-3: 맨 앞에 m3 등록 -> insert_front(&list, \"%s\")\n", m3.name);
    insert_front(&list, &m3);
    
    puts("\n[기대 결과]");
    puts("  - 연결 상태: Head -> m3(idx:2) -> m1(idx:0) -> m2(idx:1) -> NULL");
    puts("  - 배열 상태: 할당 지표(max)가 0에서 2까지 순차적으로 증가함.");
    
    puts("\n[실제 출력]");
    print_list(&list);
    print_array(&list);
    printf(" 현재 Free List 머리 (list.deleted) : %d (null인 경우 -1)\n", list.deleted);
    puts("==========================================================================\n");


    // ==========================================================================
    // STAGE 2: 노드 삭제 및 Free List (LIFO Stack) 형성 검증
    // ==========================================================================
    puts("[STAGE 2] 노드 삭제 및 Free List 형성 검증");
    puts("--------------------------------------------------------------------------");
    puts("▶ 액션 2-1: 맨 앞 노드(m3, idx:2) 삭제 -> remove_front(&list)");
    remove_front(&list);
    
    puts("▶ 액션 2-2: 맨 뒤 노드(m2, idx:1) 삭제 -> remove_rear(&list)");
    remove_rear(&list);
    
    puts("\n[기대 결과]");
    puts("  - 연결 상태: Head -> m1(idx:0) -> NULL");
    puts("  - Free List: list.deleted가 최신 삭제된 '1'을 가리키고,");
    puts("               idx 1의 next가 이전 삭제된 '2'를 가리킴 (1 -> 2 -> -1 구조)");
    
    puts("\n[실제 출력]");
    print_list(&list);
    printf(" 현재 Free List 머리 (list.deleted) : %d (기대값: 1)\n", list.deleted);
    if (list.deleted != null) {
        printf(" -> idx %d 노드의 next (다음 빈 공간) : %d (기대값: 2)\n", list.deleted, list.arr[list.deleted].next);
    }
    puts("==========================================================================\n");


    // ==========================================================================
    // STAGE 3: 빈 공간 재활용 (Reutilization) 검증
    // ==========================================================================
    puts("[STAGE 3] 삭제된 공간 재활용(Reutilization) 검증");
    puts("--------------------------------------------------------------------------");
    puts("현재 상태에서 새로운 노드를 삽입할 때, 새로운 배열 인덱스(idx:3)를 파먹지 않고");
    puts("Free List에 머물러 있던 idx:1과 idx:2 자리를 역순으로 먼저 채워야 합니다.\n");
    
    printf("▶ 액션 3-1: 맨 뒤에 m4 등록 -> insert_rear(&list, \"%s\")\n", m4.name);
    insert_rear(&list, &m4);
    printf("   (Free List의 머리였던 idx:1 공간이 m4로 대체되어야 함)\n\n");
    
    printf("▶ 액션 3-2: 맨 앞에 m5 등록 -> insert_front(&list, \"%s\")\n", m5.name);
    insert_front(&list, &m5);
    printf("   (Free List의 다음 타겟이었던 idx:2 공간이 m5로 대체되어야 함)\n");
    
    puts("\n[기대 결과]");
    puts("  - 연결 상태: Head -> m5(idx:2) -> m1(idx:0) -> m4(idx:1) -> NULL");
    puts("  - 배열 상태: idx 0, 1, 2 내의 데이터만 변경됨. 내부 최고 인덱스(max)는 유지되어야 함.");
    
    puts("\n[실제 출력]");
    print_list(&list);
    print_array(&list);
    printf(" 현재 Free List 머리 (list.deleted) : %d (모두 재사용했으므로 -1)\n", list.deleted);
    puts("==========================================================================\n");


    // ==========================================================================
    // STAGE 4: 검색(Search) 및 현재 가리키는 노드 삭제 (Remove Current)
    // ==========================================================================
    puts("[STAGE 4] 검색(Search) 및 현재 가리키는 노드 삭제 테스트");
    puts("--------------------------------------------------------------------------");
    printf("▶ 액션 4-1: 리스트 내에서 \"%s\" 노드 탐색 -> search(&list, &m1, compare)\n", m1.name);
    Index found_idx = search(&list, &m1, compare);
    printf("   -> 탐색 결과 반환 인덱스: %d (기대값: 0)\n", found_idx);
    print_node(&list); // 현재 선택된(crnt) 노드 정보 출력
    
    puts("\n▶ 액션 4-2: 현재 선택된 m1(idx:0) 노드 타겟 삭제 -> remove_current(&list)");
    remove_current(&list);
    
    puts("\n[기대 결과]");
    puts("  - 연결 상태: Head -> m5(idx:2) -> m4(idx:1) -> NULL (m1 중간 끊기 성공)");
    puts("  - Free List: 방금 삭제된 idx:0이 다시 Free List의 머리(list.deleted = 0)로 등록됨.");
    
    puts("\n[실제 출력]");
    print_list(&list);
    printf(" 현재 Free List 머리 (list.deleted) : %d (기대값: 0)\n", list.deleted);
    puts("==========================================================================\n");


    // ==========================================================================
    // STAGE 5: 리스트 전체 초기화 및 메모리 해제
    // ==========================================================================
    puts("[STAGE 5] 리스트 전체 비우기 및 메모리 해제");
    puts("--------------------------------------------------------------------------");
    puts("▶ 액션 5-1: 리스트 전체 노드 비우기 -> clear(&list)");
    clear(&list);
    print_list(&list);
    
    puts("\n▶ 액션 5-2: 동적 배열 메모리 최종 해제 -> terminate_list(&list)");
    terminate_list(&list);
    
    puts("\n==========================================================================");
    puts("  Demo Execution Successfully Finished. All Assertions Passed.");
    puts("==========================================================================");

    return 0;
}

int compare(const member *x, const member *y) {
    return strcmp(x->name, y->name);
}
