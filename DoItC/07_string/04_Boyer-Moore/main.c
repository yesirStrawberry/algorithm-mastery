/**
 * @file main.c
 * @brief Boyer-Moore 알고리즘 및 str_str 함수의 동작 검증을 위한 종합 테스트 벤치
 * @details 일반적인 매칭 케이스, 매칭 실패 케이스, C 표준 규격을 따르는 빈 문자열(Edge Case) 케이스,
 * 그리고 포인터 반환형 매커니즘의 정상 작동 여부를 다각도로 테스트합니다.
 * @author 이예성
 * @date 2026-05-31
 */

#include <stdio.h>
#include <string.h>
#include "bm_match.h"

/**
 * @brief 테스트 화면의 가독성을 높이기 위해 전처리 매커니즘을 이용한 구분선 매크로
 * @details 컴파일 전 단순 치환(Substitution)을 통해 오버헤드 없이 깔끔한 결과 창을 구성합니다.
 */
#define PRINT_SECTION(title) \
    printf("\n==================================================\n"); \
    printf("  SECTION: %s\n", title); \
    printf("==================================================\n")

int main(void) {
    // 1. 테스트를 위한 본문(Text)과 다양한 패턴(Pattern) 정의
    const char text[] = "VISION WITHOUT ACTION IS A DAYDREAM.";
    
    const char pat_success[] = "ACTION";    // 일반적인 매칭 성공 케이스
    const char pat_fail[]    = "REALITY";   // 매칭 실패 케이스
    const char pat_empty[]   = "";          // C 표준 명세 검증을 위한 빈 문자열 (Edge Case)
    const char pat_edge[]    = "DAYDREAM."; // 본문 맨 끝 자락 매칭 케이스

    PRINT_SECTION("Boyer-Moore 알고리즘 (bm_match 인덱스 기반) 테스트");
    {
        int idx;

        // Case A: 매칭 성공 (정수 인덱스 반환 검증)
        idx = bm_match(text, pat_success);
        printf("[SUCCESS CASE] 패턴 \"%s\" 탐색 결과\n", pat_success);
        if (idx != -1) {
            printf("-> 매칭 성공! 시작 인덱스: %d (본문 일치 확인: %s)\n\n", idx, &text[idx]);
        } else {
            printf("-> 오류: 매칭되어야 하는 패턴을 찾지 못했습니다.\n\n");
        }

        // Case B: 매칭 실패 (-1 반환 검증)
        idx = bm_match(text, pat_fail);
        printf("[FAILURE CASE] 패턴 \"%s\" 탐색 결과\n", pat_fail);
        if (idx == -1) {
            printf("-> 매칭 실패 확인 (예상대로 -1이 올바르게 반환되었습니다.)\n\n");
        } else {
            printf("-> 오류: 존재하지 않는 패턴에 인덱스(%d)가 반환되었습니다.\n\n", idx);
        }
        
        // Case C: 본문 후미 매칭
        idx = bm_match(text, pat_edge);
        printf("[EDGE CASE] 후미 패턴 \"%s\" 탐색 결과\n", pat_edge);
        if (idx != -1) {
            printf("-> 매칭 성공! 시작 인덱스: %d\n\n", idx);
        }
    }

    PRINT_SECTION("Boyer-Moore 기반 맞춤형 str_str (포인터 반환 기반) 테스트");
    {
        char *ptr;

        // Case A: 표준 strstr과 동일하게 매칭된 메모리 주소(Pointer) 반환 검증
        ptr = str_str(text, pat_success);
        printf("[SUCCESS CASE] str_str(\"%s\") 탐색 결과\n", pat_success);
        if (ptr != NULL) {
            printf("-> 반환된 포인터 주소: %p\n", (void*)ptr);
            printf("-> 포인터 역참조 출력(역산 검증): %s\n", ptr);
            printf("-> 본문 시작점과의 오프셋 주소차(인덱스 변환): %td\n\n", ptr - text);
        } else {
            printf("-> 오류: NULL 포인터가 반환되었습니다.\n\n");
        }

        // Case B: 탐색 실패 시 규격대로 NULL 반환하는지 검증
        ptr = str_str(text, pat_fail);
        printf("[FAILURE CASE] str_str(\"%s\") 탐색 결과\n", pat_fail);
        if (ptr == NULL) {
            printf("-> 매칭 실패 확인: NULL 포인터가 정확히 반환되었습니다.\n\n");
        } else {
            printf("-> 오류: NULL이 반환되어야 하나 유효하지 않은 주소(%p)가 반환됨.\n\n", (void*)ptr);
        }

        // Case C: 헤더 명세 및 C99/C11 표준(pat이 빈 문자열일 때 txt 주소 즉시 반환) 검증
        ptr = str_str(text, pat_empty);
        printf("[CRITICAL EDGE CASE] 빈 문자열 패턴 str_str(\"\") 탐색 결과\n", pat_empty);
        printf("-> 본문(text)의 원본 시작 주소 : %p\n", (void*)text);
        printf("-> str_str이 반환한 포인터 주소: %p\n", (void*)ptr);
        if (ptr == text) {
            printf("-> 표준 명세 준수 확인 완료: 빈 패턴 입력 시 본문의 시작 주소를 오프셋 없이 즉시 반환함.\n\n");
        } else {
            printf("-> 오류: 표준 규격을 만족하지 못했습니다.\n\n");
        }
    }

    PRINT_SECTION("전체 테스트 프로세스 종료");
    return 0;
}
