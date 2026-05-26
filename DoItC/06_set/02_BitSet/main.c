#include <stdio.h>
#include "BitSet.h" 

int main() {
    BitSet mySet = BitSetNull;

    printf("=== BitSet 함수 테스트 ===\n\n");

    // 1. 초기 상태 확인
    printf("[1] 초기화 확인\n");
    printf("초기 집합 출력: ");
    print_bset(mySet); // 변경된 함수명 적용
    printf("원소 개수 (예상: 0): %d\n\n", size_bset(mySet));

    // 2. add_bset 함수 테스트 (포인터 전달)
    printf("[2] 원소 추가 테스트 (3, 7, 31 추가)\n");
    add_bset(&mySet, 3);
    add_bset(&mySet, 7);
    add_bset(&mySet, 31); // 32비트 기준 최대 인덱스 경계값

    printf("집합 출력: ");
    print_bset(mySet);
    printf("원소 개수 (예상: 3): %d\n\n", size_bset(mySet));

    // 3. 비정상 파라미터 경계값 테스트
    printf("[3] 비정상 범위 파라미터 예외 테스트\n");
    printf("범위 초과 원소(32) 추가 시도...\n");
    add_bset(&mySet, 32);
    printf("음수 원소(-5) 추가 시도...\n");
    add_bset(&mySet, -5);

    printf("집합 출력 (변화가 없어야 함): ");
    print_bset(mySet);
    printf("원소 개수 (예상: 3): %d\n\n", size_bset(mySet));

    // 4. is_member 함수 테스트
    printf("[4] 원소 존재 여부 확인 테스트\n");
    printf("7 존재 여부 (예상: 1): %d\n", is_member(mySet, 7));
    printf("5 존재 여부 (예상: 0): %d\n", is_member(mySet, 5));
    printf("32(범위 초과) 존재 여부 (예상: 0): %d\n\n", is_member(mySet, 32));

    // 5. remove_bset 함수 테스트 (포인터 전달)
    printf("[5] 원소 삭제 테스트\n");
    remove_bset(&mySet, 7);
    printf("7 삭제 후 집합: ");
    print_bset(mySet);

    printf("없는 원소(7) 다시 삭제 시도...\n");
    remove_bset(&mySet, 7);
    printf("존재하지 않는 범위(40) 삭제 시도...\n");
    remove_bset(&mySet, 40);

    // 6. 최종 결과 확인
    printf("\n[6] 최종 결과\n");
    printf("최종 집합 출력 (예상: 3, 31): ");
    print_bset(mySet);
    printf("최종 원소 개수 (예상: 2): %d\n", size_bset(mySet));

    return 0;
}
