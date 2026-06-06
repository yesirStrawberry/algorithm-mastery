#include <stdio.h>
#include <string.h>
#include "member.h"
#include "ArrayLinkedList.h"

int compare(const member *x, const member *y);

int main(void) {   
    List list;
    init_list(&list, 200);
    
    member m1 = {"m1", 20};
    member m2 = {"m2", 22};
    member m3 = {"m3", 25};
    member m4 = {"m4", 30};
    member m5 = {"m5", 35};
    
    // ==========================================
    // TEST 1: 초기 삽입 및 연결 관계 검증
    // ==========================================
    puts("\n==================================================================");
    puts("[TEST 1] 순차적 삽입 테스트");
    puts("  - 작업 내용: insert_front(m1) -> insert_rear(m2) -> insert_front(m3)");
    puts("  - 예상 결과: Head -> m3(idx:2) -> m1(idx:0) -> m2(idx:1) -> NULL");
    puts("==================================================================");
    
    insert_front(&list, &m1); 
    insert_rear(&list, &m2);  
    insert_front(&list, &m3); 
    
    puts("\n[TEST 1 실제 출력]");
    print_list(&list);
    print_array(&list);
    
    // ==========================================
    // TEST 2: 삭제 기능 및 Free List(deleted) 검증
    // ==========================================
    puts("\n==================================================================");
    puts("[TEST 2] 삭제 및 Free List 연결 테스트");
    puts("  - 작업 내용: remove_front() [m3 삭제] -> remove_rear() [m2 삭제]");
    puts("  - 예상 결과: Head -> m1(idx:0) -> NULL");
    puts("               (Free List 머리 list->deleted는 방금 삭제된 idx 1을 가리켜야 함)");
    puts("==================================================================");
    
    remove_front(&list); 
    remove_rear(&list);  
    
    puts("\n[TEST 2 실제 출력]");
    print_list(&list);
    // 현재 deleted 변수 상태를 직접 확인하기 위해 출력문 추가
    printf("-> 현재 list->deleted 인덱스 상태 (예상: 1) : %d\n", list.deleted);
    if (list.deleted != null) {
        printf("-> idx 1의 Dnext 상태 (예상: 2) : %d\n", list.arr[list.deleted].Dnext);
    }
    
    // ==========================================
    // TEST 3: 공간 재활용(Free List 할당) 검증
    // ==========================================
    puts("\n==================================================================");
    puts("[TEST 3] 삭제된 공간 재활용 검증");
    puts("  - 작업 내용: insert_rear(m4) -> insert_front(m5)");
    puts("  - 예상 결과: Head -> m5(idx:2) -> m1(idx:0) -> m4(idx:1) -> NULL");
    puts("               *주의* 새로 배열을 파먹지 않고 idx 1과 2를 그대로 재활용해야 함!");
    puts("==================================================================");
    
    insert_rear(&list, &m4); 
    insert_front(&list, &m5); 
    
    puts("\n[TEST 3 실제 출력]");
    print_list(&list);
    print_array(&list);
    
    // ==========================================
    // TEST 4: 검색 및 현재 노드 삭제 검증
    // ==========================================
    puts("\n==================================================================");
    puts("[TEST 4] 검색(search) 및 현재 노드 삭제");
    puts("  - 작업 내용: search(m1) 수행 후 remove_current()로 m1 삭제");
    puts("  - 예상 결과: 검색 인덱스: 0");
    puts("               삭제 후 최종 리스트: Head -> m5(idx:2) -> m4(idx:1) -> NULL");
    puts("==================================================================");
    
    Index search_idx = search(&list, &m1, compare);
    printf("\n-> m1 검색 결과 인덱스 (예상: 0) : %d\n", search_idx);
    
    remove_current(&list);
    
    puts("\n[TEST 4 실제 출력]");
    print_list(&list);
    
    terminate_list(&list);
    return 0;
}

int compare(const member *x, const member *y) {
    return strcmp(x->name, y->name); 
}
