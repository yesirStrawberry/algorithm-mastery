/**
 * @file bm_match.h
 * @brief Boyer-Moore (Bad Character Shift) 문자열 매칭 알고리즘 헤더 파일
 * @author DoItC
 * @date 2026-05-31
 */

#ifndef BM_MATCH_H
#define BM_MATCH_H

/**
 * @brief 문자열 매칭 진행 과정을 시각적으로 출력하는 유틸리티 함수
 * * @param txt 전체 본문(Text) 문자열
 * @param pat 찾고자 하는 패턴(Pattern) 문자열
 * @param t_idx 현재 비교 중인 본문(Text)의 인덱스
 * @param p_idx 현재 비교 중인 패턴(Pattern)의 인덱스
 * @return int 성공 시 항상 0을 반환
 */
int print_progress(const char txt[], const char pat[], int t_idx, int p_idx);

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

#endif /* BM_MATCH_H */
