/**
 * @file str_match.h
 * @brief 브루트 포스(Brute Force) 알고리즘을 이용한 문자열 검색 함수 헤더
 */

#ifndef STR_MATCH_H
#define STR_MATCH_H

/**
 * @brief 텍스트의 처음부터 문자열을 순방향으로 탐색하는 브루트 포스 함수
 * * @param txt 검색 대상이 되는 전체 텍스트 문자열
 * @param pat 찾고자 하는 패턴 문자열
 * @return int 패턴이 일치하는 첫 번째 문자열의 시작 인덱스 (찾지 못하거나 빈 문자열이면 -1 반환)
 */
int bf_match(const char txt[], const char pat[]);

/**
 * @brief 텍스트의 끝부터 문자열을 역방향으로 탐색하는 브루트 포스 함수
 * * @param txt 검색 대상이 되는 전체 텍스트 문자열
 * @param pat 찾고자 하는 패턴 문자열
 * @return int 역방향 탐색 시 가장 먼저 일치하는 패턴의 시작 인덱스 (찾지 못하거나 빈 문자열이면 -1 반환)
 */
int bf_matchr(const char txt[], const char pat[]);

/**
 * @brief 문자열 탐색 진행 과정을 시각적으로 출력하는 함수
 * * @param txt 검색 대상 텍스트 문자열
 * @param pat 패턴 문자열
 * @param t_idx 현재 비교 중인 텍스트의 인덱스
 * @param p_idx 현재 비교 중인 패턴의 인덱스
 * @return int 출력 성공 여부 혹은 상태 값 (형식 유지용)
 */
int print_progress(const char txt[], const char pat[], int t_idx, int p_idx);

/**
 * @brief 문자열의 길이를 계산하는 함수
 * * @param s 길이를 측정할 문자열 포인터
 * @return int 문자열의 길이 (널 문자 제외)
 */
int str_len(const char *s);

#endif // STR_MATCH_H
