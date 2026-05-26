#include <stdio.h>
#include "IntSet.h"

int main(void) {
    // 1. 집합 객체 선언 및 초기화
    IntSet s1, s2, s3, s4;
    
    // 최대 10개의 원소를 담을 수 있도록 초기화
    if (init_IntSet(&s1, 10) == -1 || init_IntSet(&s2, 10) == -1 || 
        init_IntSet(&s3, 10) == -1 || init_IntSet(&s4, 10) == -1) {
        printf("집합 초기화 실패!\n");
        return -1;
    }

    printf("=== [1] 기본 기능 및 예외 처리 테스트 ===\n");
    // 원소 추가
    add_ele(&s1, 10);
    add_ele(&s1, 20);
    add_ele(&s1, 30);
    add_ele(&s1, 40);
    printf("s1에 10, 20, 30, 40 추가 후: ");
    print_set(&s1);

    // 중복 추가 테스트
    if (add_ele(&s1, 20) == -1) {
        printf("-> [확인] 20 중복 추가 차단 성공\n");
    }

    // 원소 검색 및 삭제 테스트
    int target = 30;
    int idx = is_member(&s1, target);
    printf("-> s1에서 %d의 위치(인덱스): %d\n", target, idx);

    remove_ele(&s1, target);
    printf("%d 삭제 후 s1 (마지막 원소가 빈자리 채움): ", target);
    print_set(&s1);
    printf("s1의 현재 원소 개수: %d, 최대 용량: %d\n\n", size(&s1), capacity(&s1));


    printf("=== [2] 대입 및 비교 테스트 ===\n");
    // s2에 원소 구성
    add_ele(&s2, 10);
    add_ele(&s2, 40);
    add_ele(&s2, 20);
    printf("s2 원소 구성: ");
    print_set(&s2);

    // 집합 동등 비교 (순서가 달라도 원소가 같으면 같아야 함)
    if (is_equal(&s1, &s2)) {
        printf("-> [확인] s1과 s2는 같은 집합입니다.\n");
    } else {
        printf("-> [오류] s1과 s2가 다르다고 판정됨.\n");
    }

    // 집합 대입 (assign)
    assign(&s3, &s1);
    printf("s1을 s3에 대입한 후 s3: ");
    print_set(&s3);
    printf("\n");


    printf("=== [3] 부분집합 검사 테스트 ===\n");
    clear_set(&s3); // s3 비우기
    add_ele(&s3, 10);
    add_ele(&s3, 20);
    printf("s1: "); print_set(&s1);
    printf("s3: "); print_set(&s3);
    
    printf("s3은 s1의 부분집합인가? %s\n", is_subset(&s3, &s1) ? "Yes" : "No");
    printf("s3은 s1의 진부분집합인가? %s\n", is_subset_proper(&s3, &s1) ? "Yes" : "No");
    printf("s1은 s2의 진부분집합인가? %s (원소 개수가 같으므로 No여야 함)\n\n", is_subset_proper(&s1, &s2) ? "Yes" : "No");


    printf("=== [4] 집합 연산 테스트 (합/교/차/대칭차) ===\n");
    // 테스트용 집합 데이터 재정의
    clear_set(&s2); clear_set(&s3);
    
    // S2 = {1, 2, 3, 4}
    add_ele(&s2, 1); add_ele(&s2, 2); add_ele(&s2, 3); add_ele(&s2, 4);
    // S3 = {3, 4, 5, 6}
    add_ele(&s3, 3); add_ele(&s3, 4); add_ele(&s3, 5); add_ele(&s3, 6);

    printf("기준 집합 A: "); print_set(&s2);
    printf("기준 집합 B: "); print_set(&s3);
    printf("----------------------------------------\n");

    // 합집합 (s4 = s2 U s3)
    union_set(&s4, &s2, &s3);
    printf("A U B (합집합): "); print_set(&s4);

    // 교집합 (s4 = s2 n s3)
    intersect_set(&s4, &s2, &s3);
    printf("A n B (교집합): "); print_set(&s4);

    // 차집합 (s4 = s2 - s3)
    difference_set(&s4, &s2, &s3);
    printf("A - B (차집합): "); print_set(&s4);

    // 대칭차집합 (s4 = (A-B) U (B-A))
    symetric_difference_set(&s4, &s2, &s3);
    printf("A ⊙ B (대칭차집합): "); print_set(&s4);
    printf("\n");


    printf("=== [5] 누적(To_) 연산 테스트 ===\n");
    printf("현재 s1 상태: "); print_set(&s1); // {10, 40, 20} 상태
    
    // s1에 s2{1, 2, 3, 4}를 누적 합집합
    to_union_set(&s1, &s2);
    printf("s1에 A를 누적 합집합한 결과: "); print_set(&s1);

    // s1과 s3{3, 4, 5, 6}의 누적 교집합
    to_intersect_set(&s1, &s3);
    printf("그 결과에 B를 누적 교집합한 결과: "); print_set(&s1);
    printf("\n");


    printf("=== [6] 메모리 해제 및 댕글링 포인터 검증 ===\n");
    terminate_intSet(&s1);
    terminate_intSet(&s2);
    terminate_intSet(&s3);
    terminate_intSet(&s4);

    printf("모든 집합 메모리 해제 완료.\n");

    return 0;
}
