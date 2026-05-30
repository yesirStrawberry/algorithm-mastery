/**
 * @file main.c
 * @brief str_basic.h 에 정의된 문자열 처리 함수군의 철저한 검증을 위한 테스트 시나리오
 */

#include <stdio.h>
#include <string.h>
#include "str_basic.h"

// 출력을 깔끔하게 분리하기 위한 매크로 함수
#define PRINT_SECTION(title) printf("\n========================================\n  [TEST] %s\n========================================\n", title)

int main(void) {
    printf("=== 기초 문자열 처리 함수군 디테일 테스트 시작 ===\n");

    // ----------------------------------------------------
    // 1. str_len 테스트
    // ----------------------------------------------------
    PRINT_SECTION("str_len (문자열 길이 계산)");
    {
        const char *s1 = "Hello, World!";
        const char *s2 = "";          // 빈 문자열
        const char *s3 = "A\0B\0C";   // 중간에 널 문자가 있는 경우

        printf("[정상 문자열] \"%s\" -> 길이: %d (예상: 13)\n", s1, str_len(s1));
        printf("[빈 문자열  ] \"%s\" -> 길이: %d (예상: 0)\n", s2, str_len(s2));
        printf("[중간 널문자] -> 길이: %d (예상: 1)\n", str_len(s3));
    }

    // ----------------------------------------------------
    // 2. str_chr & str_rchr 테스트
    // ----------------------------------------------------
    PRINT_SECTION("str_chr & str_rchr (문자 검색)");
    {
        const char *base = "apple computer";
        printf("대상 문자열: \"%s\" (시작 주소: %p)\n\n", base, (void*)base);

        // Case A: 중간에 존재하는 일반 문자 검색 ('p')
        char *ptr_chr = str_chr(base, 'p');
        char *ptr_rchr = str_rchr(base, 'p');
        
        printf("[str_chr ] 'p' 검색 -> 주소: %p (인덱스: %ld), 남은 문자열: \"%s\"\n", 
               (void*)ptr_chr, ptr_chr ? (ptr_chr - base) : -1, ptr_chr ? ptr_chr : "NULL");
        printf("[str_rchr] 'p' 검색 -> 주소: %p (인덱스: %ld), 남은 문자열: \"%s\"\n", 
               (void*)ptr_rchr, ptr_rchr ? (ptr_rchr - base) : -1, ptr_rchr ? ptr_rchr : "NULL");

        // Case B: 존재하지 않는 문자 검색 ('z')
        char *ptr_not_found = str_chr(base, 'z');
        printf("\n[str_chr ] 존재하지 않는 'z' 검색 -> 결과: %s\n", ptr_not_found ? "실패(위치 찾음)" : "NULL (정상)");

        // Case C: 문자열의 끝인 널 문자('\0') 검색 테스트
        // 표준 strchr과 strrchr은 널 문자도 검색 대상에 포함하여 그 주소를 반환해야 합니다.
        char *ptr_null_chr = str_chr(base, '\0');
        char *ptr_null_rchr = str_rchr(base, '\0');
        printf("\n[str_chr ] '\\0' 검색 -> 인덱스: %ld (예상: 14)\n", ptr_null_chr ? (ptr_null_chr - base) : -1);
        printf("[str_rchr] '\\0' 검색 -> 인덱스: %ld (예상: 14)\n", ptr_null_rchr ? (ptr_null_rchr - base) : -1);
    }

    // ----------------------------------------------------
    // 3. str_cmp & str_ncmp 테스트
    // ----------------------------------------------------
    PRINT_SECTION("str_cmp & str_ncmp (사전식 비교)");
    {
        const char *abc1 = "abc";
        const char *abc2 = "abcdef";
        const char *abd  = "abd";

        printf("[str_cmp]  \"abc\" vs \"abc\"    -> 결과: %d (예상: 0)\n", str_cmp(abc1, abc1));
        printf("[str_cmp]  \"abc\" vs \"abcdef\" -> 결과: %d (예상: 음수)\n", str_cmp(abc1, abc2));
        printf("[str_cmp]  \"abd\" vs \"abc\"    -> 결과: %d (예상: 양수)\n", str_cmp(abd, abc1));

        printf("\n[str_ncmp] \"abc\" vs \"abcdef\" (n=3) -> 결과: %d (예상: 0)\n", str_ncmp(abc1, abc2, 3));
        printf("[str_ncmp] \"abc\" vs \"abcdef\" (n=5) -> 결과: %d (예상: 음수)\n", str_ncmp(abc1, abc2, 5));
        printf("[str_ncmp] \"abc\" vs \"abd\"    (n=2) -> 결과: %d (예상: 0)\n", str_ncmp(abc1, abd, 2));
        printf("[str_ncmp] \"abc\" vs \"abd\"    (n=0) -> 결과: %d (예상: 0)\n", str_ncmp(abc1, abd, 0));
    }

    // ----------------------------------------------------
    // 4. str_cmpic & str_ncmpic 테스트
    // ----------------------------------------------------
    PRINT_SECTION("str_cmpic & str_ncmpic (대소문자 무시 비교)");
    {
        const char *upper = "HELLO";
        const char *lower = "hello";
        const char *mix1  = "HellO WOrld";
        const char *mix2  = "hello world!!";

        printf("[str_cmpic]  \"HELLO\" vs \"hello\"       -> 결과: %d (예상: 0)\n", str_cmpic(upper, lower));
        printf("[str_cmpic]  \"HellO WOrld\" vs \"hello...\" -> 결과: %d (예상: 음수 - ' '와 '!' 비교)\n", str_cmpic(mix1, mix2));
        
        printf("\n[str_ncmpic] \"HellO WOrld\" vs \"hello...\" (n=11) -> 결과: %d (예상: 0)\n", str_ncmpic(mix1, mix2, 11));
        printf("[str_ncmpic] \"HellO WOrld\" vs \"hello...\" (n=5)  -> 결과: %d (예상: 0)\n", str_ncmpic(mix1, mix2, 5));
    }

    // ----------------------------------------------------
    // 5. swap_ptr 테스트 (Call by Reference 포인터 자체 교환)
    // ----------------------------------------------------
    PRINT_SECTION("swap_ptr (문자열 포인터 자체 교환)");
    {
        char *ptr_a = "String A (Apple)";
        char *ptr_b = "String B (Banana)";

        printf("[교환 전] ptr_a: %p (\"%s\"), ptr_b: %p (\"%s\")\n", (void*)ptr_a, ptr_a, (void*)ptr_b, ptr_b);
        
        swap_ptr(&ptr_a, &ptr_b);
        
        printf("[교환 후] ptr_a: %p (\"%s\"), ptr_b: %p (\"%s\")\n", (void*)ptr_a, ptr_a, (void*)ptr_b, ptr_b);
        printf("-> 주소값 자체가 서로 완전히 바뀌었는지 확인하세요.\n");
    }

    // ----------------------------------------------------
    // 6. swap_str 테스트 (실제 메모리 버퍼 내용 교환)
    // ----------------------------------------------------
    PRINT_SECTION("swap_str (메모리 버퍼 내용 교환)");
    {
        // 리터럴을 쓰면 상수 영역이라 crash가 나므로 수정 가능한 배열 버퍼 확보
        char buf_x[30] = "Cat";
        char buf_y[30] = "Elephant";

        printf("[교환 전] buf_x: \"%s\" (주소: %p), buf_y: \"%s\" (주소: %p)\n", buf_x, (void*)buf_x, buf_y, (void*)buf_y);
        
        swap_str(buf_x, buf_y);
        
        printf("[교환 후] buf_x: \"%s\" (주소: %p), buf_y: \"%s\" (주소: %p)\n", buf_x, (void*)buf_x, buf_y, (void*)buf_y);
        printf("-> 주소는 그대로이되, 각 배열 안의 '문자열 내용물'이 바뀌었는지 확인하세요.\n");
    }

    // ----------------------------------------------------
    // 7. str_dump 테스트
    // ----------------------------------------------------
    PRINT_SECTION("str_dump (문자열 데이터 덤프)");
    {
        const char *dump_target = "ABC 12"; 
        printf("덤프 대상 문자열: \"%s\"\n", dump_target);
        printf("--- 덤프 출력 시작 ---\n");
        str_dump(dump_target);
        printf("--- 덤프 출력 종료 ---\n");
    }

    printf("\n========================================\n");
    printf("=== 모든 시나리오 테스트 출력 완료 ===\n");
    return 0;
}
