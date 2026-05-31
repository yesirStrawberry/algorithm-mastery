/**
 * @file bm_match.h
 * @brief Boyer-Moore (Bad Character Shift) 문자열 매칭 알고리즘 헤더 파일
 * @author DoItC
 * @date 2026-05-31
 */

#ifndef BM_MATCH_H
#define BM_MATCH_H

/**
 * @brief Boyer-Moore 알고리즘(Bad Character Heuristic)을 이용해 문자열을 탐색합니다.
 * @details 패턴의 오른쪽 끝부터 왼쪽으로 비교를 수행하며, 불일치 발생 시 
 * 배드 캐릭터 테이블(skip)을 참조하여 건너뜀 거리를 계산합니다.
 * * @param txt 탐색 대상이 되는 전체 본문(Text) 문자열 (Null-terminated)
 * @param pat 찾고자 하는 패턴(Pattern) 문자열 (Null-terminated)
 * @return int 패턴이 매칭된 본문의 시작 인덱스, 매칭 실패 시 -1 반환
 * * @note 오버플로우 방지를 위해 입력 문자열의 길이는 인덱스 범위 내에 있어야 합니다.
 */
int bm_match(const char txt[], const char pat[]);

/**
 * @brief C 표준 strstr 함수를 Boyer-Moore(Bad Character) 알고리즘으로 모방하여 구현한 함수
 * @details 본문(txt) 내에서 패턴(pat)이 처음 등장하는 위치의 포인터를 반환합니다.
 * C99/C11 표준 명세에 따라 pat이 빈 문자열일 경우 txt의 주소를 즉시 반환합니다.
 * * @param txt 탐색 대상이 되는 부호 없는 문자열 (Null-terminated)
 * @param pat 찾고자 하는 서브 문자열 (Null-terminated)
 * @return char* 매칭된 문자열의 시작 주소 포인터, 매칭 실패 시 NULL 반환
 */
char* str_str(const char txt[], const char pat[]);

/**
 * @brief 문자열 매칭 진행 과정을 시각적으로 출력하는 유틸리티 함수
 * * @param txt 전체 본문(Text) 문자열
 * @param pat 찾고자 하는 패턴(Pattern) 문자열
 * @param t_idx 현재 비교 중인 본문(Text)의 인덱스
 * @param p_idx 현재 비교 중인 패턴(Pattern)의 인덱스
 * @return int 성공 시 항상 0을 반환
 */
int print_progress(const char txt[], const char pat[], int t_idx, int p_idx);

#endif /* BM_MATCH_H */
