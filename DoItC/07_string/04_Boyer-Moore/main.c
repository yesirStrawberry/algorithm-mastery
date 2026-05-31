/**
 * @file main.c
 * @brief Boyer-Moore 알고리즘 검증을 위한 상세 테스트 드라이버
 */

#include "bm_match.h"
#include <stdio.h>

void run_test_case(int case_num, const char *description, const char *txt, const char *pat) {
    printf("==================================================\n");
    printf("[Test Case %d] %s\n", case_num, description);
    printf("Text   : \"%s\"\n", txt);
    printf("Pattern: \"%s\"\n", pat);
    printf("==================================================\n");
    
    int result = bm_match(txt, pat);
    
    if (result != -1) {
        printf(">>> Result: Pattern found at starting index [%d]\n", result);
    } else {
        printf(">>> Result: Pattern NOT found (-1)\n");
    }
    printf("==================================================\n\n");
}

int main(void) {
    printf("=== Boyer-Moore String Matching Simulation Start ===\n\n");

    // Case 1: 기본 제공 케이스 (부분 매칭 후 실패, 이후 완전 매칭 성공)
    run_test_case(1, "Original Provided Code Test", "abecdabce", "abcd");

    // Case 2: 매칭 실패 케이스 (존재하지 않는 문자 포함)
    run_test_case(2, "Match Failure Scenario", "abcdefg", "xyz");

    // Case 3: 텍스트 중간과 끝에 여러 번 매칭 기회가 있는 케이스
    run_test_case(3, "Multiple Partial Matches", "aaaaabacada", "abac");

    return 0;
}
