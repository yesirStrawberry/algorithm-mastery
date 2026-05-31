/**
 * @file kmp.h
 * @brief KMP(Knuth-Morris-Pratt) 문자열 검색 알고리즘 및 진행 상황 시각화 모듈
 * @author Computer Science Student
 * @date 2026-05-31
 */

#ifndef STR_KMP_H
#define STR_KMP_H

#include <stddef.h>

/**
 * @brief 대상 텍스트 내에서 지정된 패턴 문자열의 첫 번째 매칭 위치를 검색합니다.
 * @details 내부적으로 패턴 문자열에 대한 실패 함수(Skip Table)를 생성하여 
 * 불일치 발생 시 텍스트 포인터를 후퇴시키지 않고 선형 시간 내에 검색을 수행합니다.
 * @param[in] txt 검색 대상이 되는 전체 본문 문자열 (Null-terminated)
 * @param[in] pat 본문 내에서 찾고자 하는 패턴 문자열 (Null-terminated)
 * @return int 매칭 성공 시 텍스트 내 시작 인덱스(0 기반), 실패 시 -1을 반환합니다.
 * @note 내부적으로 동적 할당(calloc)된 skip 배열은 함수 종료 전 자원을 완전 해제(free)합니다.
 */
int kmp_match(const char txt[], const char pat[]);

/**
 * @brief KMP 문자열 탐색의 실시간 매칭 상태 및 포인터 위치를 표준 출력(stdout)에 시각화합니다.
 * @details 현재 텍스트 포인터(t_idx)와 패턴 포(p_idx)의 대조 상황을 '+', '|' 기호 및 
 * 정렬된 문자열 형태로 콘솔에 직관적으로 덤프합니다.
 * @param[in] txt 대조 중인 원본 본문 문자열
 * @param[in] pat 대조 중인 타겟 패턴 문자열
 * @param[in] t_idx 현재 검사 중인 텍스트의 인덱스 포인터
 * @param[in] p_idx 현재 검사 중인 패턴의 인덱스 포인터
 * @return int 상시 0을 반환합니다.
 */
int print_progress(const char txt[], const char pat[], int t_idx, int p_idx);

/**
 * @brief 주어진 문자열의 순수 문자 길이를 계산합니다.
 * @param[in] s 길이를 측정할 문자열 포인터 (Null-terminated)
 * @return int 문자열의 총 길이 (널 문자 제외)
 */
int str_len(const char *s);

#endif /* KMP_H */
