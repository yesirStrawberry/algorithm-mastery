/**
 * @file main.c
 * @brief Boyer-Moore 알고리즘의 tx 인덱스 역전 및 중복 탐색 검증을 위한 메인 드라이버
 * @note C99/C11 표준 준수
 */

#include "bm_match.h"
#include <stdio.h>

/**
 * @brief 테스트 케이스를 실행하고 결과를 포맷팅하여 출력하는 함수
 * @param case_num 테스트 케이스 번호
 * @param description 테스트 목적 및 설명
 * @param txt 본문 문자열 (Text)
 * @param pat 매칭할 패턴 문자열 (Pattern)
 */
void run_detailed_test(int case_num, const char *description, const char *txt, const char *pat) {
    printf("======================================================================\n");
    printf("[Test Case %d] %s\n", case_num, description);
    printf("Text   : \"%s\"\n", txt);
    printf("Pattern: \"%s\"\n", pat);
    printf("======================================================================\n");
    printf("Shifts & Matching Progress:\n");
    printf("----------------------------------------------------------------------\n");
    printf("Idx  Text Pointer & Pattern Alignments\n");
    printf("----------------------------------------------------------------------\n");
    
    int result = bm_match(txt, pat);
    
    printf("----------------------------------------------------------------------\n");
    if (result != -1) {
        printf(">>> [SUCCESS] Pattern found starting at index [%d]\n", result);
    } else {
        printf(">>> [FAILURE] Pattern NOT found within the text (-1)\n");
    }
    printf("======================================================================\n\n");
}

int main(void) {
    printf("======================================================================\n");
    printf("    Boyer-Moore Bad Character Shift Index Regression Verification     \n");
    printf("======================================================================\n\n");

    // [User Proposed Case] tx 역전 및 무한 루프 위험성 검증 케이스
    // 본문 중간에 'b'가 있고 패턴은 'b'로 시작하여 뒤가 모두 'a'인 구조
    run_detailed_test(1, 
                      "User Case: tx Pointer Regression & Redundant Comparison Test", 
                      "aaaaaabaaaaaaaa", 
                      "baaaaaa");

    // [Comparison Case] 일반적인 성능 우위 케이스 (Sub-linear 무한 스킵)
    run_detailed_test(2, 
                      "Standard Case: Ideal Bad Character Shift (O(N/M))", 
                      "abecdabce", 
                      "abcd");

    // [Edge Case] 텍스트 전체가 동일 문자로 반복될 때의 경계 조건
    run_detailed_test(3, 
                      "Edge Case: Worst-case Single Character Repeated", 
                      "aaaaaaaaaaaaaaa", 
                      "aaaa");

    return 0;
}
