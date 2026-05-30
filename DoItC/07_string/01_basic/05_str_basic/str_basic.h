/**
 * @file str_basic.h
 * @brief 기초 문자열 처리 함수군 정의 및 문서화
 */

#ifndef STR_BASIC_H
#define STR_BASIC_H

#include <stddef.h> // size_t 정의를 위함

/**
 * @brief 문자열의 길이를 계산합니다.
 * @param s 길이를 잴 문자열 포인터
 * @return int 문자열의 길이 (널 문자 제외)
 * @note 시간 복잡도: O(N), 공간 복잡도: O(1)
 */
int str_len(const char *s);

/**
 * @brief 문자열에서 특정 문자가 처음 나타나는 주소를 찾습니다.
 * @param s 검색할 문자열
 * @param c 찾을 문자 (int로 전달되나 내부에서 char로 처리)
 * @return char* 문자를 찾은 위치의 포인터, 없으면 NULL
 * @note 시간 복잡도: O(N), 공간 복잡도: O(1)
 */
char *str_chr(const char *s, int c);

/**
 * @brief 문자열에서 특정 문자가 마지막으로 나타나는 주소를 찾습니다.
 * @param s 검색할 문자열
 * @param c 찾을 문자
 * @return char* 문자를 찾은 위치의 포인터, 없으면 NULL
 * @note 시간 복잡도: O(N), 공간 복잡도: O(1)
 */
char *str_rchr(const char *s, int c);

/**
 * @brief 두 문자열을 사전식으로 비교합니다.
 * @return int s1 > s2면 양수, s1 < s2면 음수, 같으면 0
 * @note 시간 복잡도: O(N), 공간 복잡도: O(1)
 */
int str_cmp(const char *s1, const char *s2);

/**
 * @brief 최대 n개 문자까지 두 문자열을 비교합니다.
 * @note 시간 복잡도: O(min(N, n)), 공간 복잡도: O(1)
 */
int str_ncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief 대소문자 구분 없이 두 문자열을 비교합니다.
 */
int str_cmpic(const char *s1, const char *s2);

/**
 * @brief 대소문자 구분 없이 최대 n개 문자까지 두 문자열을 비교합니다.
 */
int str_ncmpic(const char *s1, const char *s2, size_t n);

/**
 * @brief 두 문자열 포인터 자체를 교환합니다. (Call by Reference)
 */
void swap_ptr(char **x, char **y);

/**
 * @brief 두 포인터가 가리키는 실제 메모리의 문자열 내용을 교환합니다.
 * @warning 충분한 버퍼 크기가 확보되어 있어야 하며, 문자열 리터럴은 인자로 전달될 수 없습니다.
 */
void swap_str(char *x, char *y);

/**
 * @brief 문자열 내 각 문자의 비트 패턴(2진수)과 16진수 값을 덤프합니다.
 */
void str_dump(const char *s);

#endif
