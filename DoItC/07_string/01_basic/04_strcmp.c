/** @file 04_strcmp.c 
 * @brief 두 문자열의 비교를 수행하는 함수를 작성한다. 
 */

/**
 * output
=== String Comparison Functions Test ===

[str_cmp 테스트]
[Equal] 결과: 0 (동일)
[Different] 결과: -20 (s2가 큼)
[Extended ASCII] 결과: 63 (s1이 큼)

[str_ncmp 테스트]
[Adc vs Add (n=2)] 결과: 0 (동일)
[Adc vs Add (n=3)] 결과: -1 (s2가 큼)

[str_cmpic 테스트]
[APPLE vs apple] 결과: 0 (동일)
[Banana vs BAND] 결과: -3 (s2가 큼)

[str_ncmpic 테스트]
[COMPputer vs compUTING (n=4)] 결과: 0 (동일)
[ABC vs abd (n=3)] 결과: -1 (s2가 큼)
 */

#include <stdio.h>
#include <stddef.h>

/**
 * @brief 두 문자열을 사전식 순서로 비교합니다.
 * 
 * @param s1 비교할 첫 번째 문자열 포인터
 * @param s2 비교할 두 번째 문자열 포인터
 * @return int s1 > s2면 양수, s1 < s2면 음수, 같으면 0
 * 
 * @details
 * - 시간 복잡도: O(N) (N은 두 문자열 중 짧은 쪽의 길이)
 * - 공간 복잡도: O(1)
 * - 정수 승격(Integer Promotion) 규칙에 의해 (unsigned char) 간의 뺄셈 결과는 
 *   안전하게 int형 음수/양수로 반환됩니다. [1]
 */
int str_cmp(const char *s1, const char *s2) {
    if(s1 == NULL || s2 == NULL) return -1; 
    
    while (*s1 == *s2) {
        if (*s1 == '\0') return 0;
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

/**
 * @brief 두 문자열을 최대 n개의 문자까지 사전식으로 비교합니다.
 * 
 * @param s1 비교할 첫 번째 문자열 포인터
 * @param s2 비교할 두 번째 문자열 포인터
 * @param n 비교할 최대 문자 수
 * @return int n개 내에서 다르면 차이값 반환, 모두 같으면 0
 * 
 * @details
 * - 시간 복잡도: O(min(N, n))
 * - 공간 복잡도: O(1)
 * - 루프 탈출 조건에서 단락 평가(Short-circuit)를 활용하여 효율성을 높였습니다.
 */
int str_ncmp(const char *s1, const char *s2, size_t n) {
    if(s1 == NULL || s2 == NULL) return -1;
    
    while (n-- > 0) {
        if (*s1 == '\0' || *s1 != *s2)
            return (unsigned char)*s1 - (unsigned char)*s2;
        s1++;
        s2++;
    }
    return 0;
}

/**
 * @brief 대소문자를 구분하지 않고 두 문자열을 비교합니다.
 * 
 * @param s1 비교할 첫 번째 문자열 포인터
 * @param s2 비교할 두 번째 문자열 포인터
 * @return int 대소문자 무시 시 s1 > s2면 양수, s1 < s2면 음수, 같으면 0
 * 
 * @details
 * - 시간 복잡도: O(N)
 * - 공간 복잡도: O(1)
 * - ASCII 'A'-'Z' 범위를 'a'-'z' 범위로 정규화(Normalization)하여 비교합니다.
 * - do-while 문을 사용하여 최소 1회의 비교(널 문자 포함)를 보장합니다.
 */
int str_cmpic(const char *s1, const char *s2) {
    if(s1 == NULL || s2 == NULL) return -1;
    
    unsigned char c1, c2;

    do {
        c1 = (unsigned char)*s1++;
        c2 = (unsigned char)*s2++;

        if ('A' <= c1 && c1 <= 'Z') c1 += 32;
        if ('A' <= c2 && c2 <= 'Z') c2 += 32;

        if (c1 == '\0' || c1 != c2) break;
    } while (1);
    return (int)c1 - (int)c2;
}

/**
 * @brief 대소문자를 구분하지 않고 두 문자열을 최대 n개까지 비교합니다.
 * 
 * @param s1 비교할 첫 번째 문자열 포인터
 * @param s2 비교할 두 번째 문자열 포인터
 * @param n 비교할 최대 문자 수
 * @return int n개 내에서 다르면 정규화된 차이값 반환, 같으면 0
 * 
 * @details
 * - 시간 복잡도: O(min(N, n))
 * - 공간 복잡도: O(1)
 * - n이 0일 경우 루프를 진입하지 않으며, 마지막 비교 문자의 차이를 반환합니다.
 */
int str_ncmpic(const char *s1, const char *s2, size_t n) {
    if(s1 == NULL || s2 == NULL) return -1;
    
    unsigned char c1 = 0, c2 = 0;

    while (n > 0) {
        c1 = (unsigned char)*s1;
        c2 = (unsigned char)*s2;

        if ('A' <= c1 && c1 <= 'Z') c1 += 32;
        if ('A' <= c2 && c2 <= 'Z') c2 += 32;

        if (c1 == '\0' || c1 != c2) break;

        s1++;
        s2++;
        n--;
    }

    return (n == 0) ? 0 : (int)c1 - (int)c2;
}

// 테스트 결과를 깔끔하게 출력하기 위한 보조 함수
void test_result(const char* test_name, int result) {
    printf("[%s] 결과: %d (%s)\n", test_name, result, 
           (result == 0) ? "동일" : (result > 0 ? "s1이 큼" : "s2가 큼"));
}

int main(void) {
    printf("=== String Comparison Functions Test ===\n\n");

    // 1. str_cmp 테스트
    printf("[str_cmp 테스트]\n");
    test_result("Equal", str_cmp("apple", "apple"));
    test_result("Different", str_cmp("apple", "apply"));
    test_result("Extended ASCII", str_cmp("\x80", "A")); // 128 vs 65

    // 2. str_ncmp 테스트 (질문하신 사례 포함)
    printf("\n[str_ncmp 테스트]\n");
    test_result("Adc vs Add (n=2)", str_ncmp("Adc", "Add", 2)); // 0 출력 기대
    test_result("Adc vs Add (n=3)", str_ncmp("Adc", "Add", 3)); // 'c'-'d' = -1

    // 3. str_cmpic 테스트 (대소문자 무시)
    printf("\n[str_cmpic 테스트]\n");
    test_result("APPLE vs apple", str_cmpic("APPLE", "apple"));
    test_result("Banana vs BAND", str_cmpic("Banana", "BAND")); // 'a' vs 'n'

    // 4. str_ncmpic 테스트
    printf("\n[str_ncmpic 테스트]\n");
    test_result("COMPputer vs compUTING (n=4)", str_ncmpic("COMPputer", "compUTING", 4));
    test_result("ABC vs abd (n=3)", str_ncmpic("ABC", "abd", 3));

    return 0;
}
