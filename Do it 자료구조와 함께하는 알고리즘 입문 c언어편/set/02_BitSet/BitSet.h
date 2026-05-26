/**
 * @file BitSet.h
 * @brief 비트 연산을 이용한 고속 집합(Set) 라이브러리
 * @details 32비트 unsigned long 타입을 활용하여 0부터 31까지의 정수를
 * 원소로 가질 수 있는 집합 자료구조를 제공합니다.
 */

#ifndef BITSET
#define BITSET

 /**
  * @brief 집합을 나타내는 비트셋 타입 (32비트 부호 없는 정수)
  */
typedef unsigned long BitSet;

#define BitSetNull (BitSet)0  /**< 빈 집합을 나타내는 상수 */
#define BitSetBits 32         /**< 집합이 가질 수 있는 최대 원소 개수 (비트 수) */

/**
 * @brief 지정된 위치의 비트 마스크를 생성하는 매크로
 * @param no 비트 위치 (원소 값, 0 ~ 31)
 */
#define SetOf(no) ((BitSet)1 << no)

 /**
  * @brief 집합에 특정 원소가 포함되어 있는지 확인합니다.
  * @param s 검사할 비트셋 집합
  * @param n 확인하려는 원소 (비트 번호)
  * @return int 원소가 존재하면 0이 아닌 값(비트 마스크 값), 존재하지 않으면 0 반환
  */
int is_member(BitSet s, int n);

/**
 * @brief 집합에 새로운 원소를 추가합니다.
 * @details 이미 존재하는 원소인 경우 집합의 특성상 변화가 없습니다.
 * @param s 변경할 비트셋의 포인터
 * @param n 추가할 원소 (비트 번호)
 */
void add_bset(BitSet* s, int n);

/**
 * @brief 집합에서 특정 원소를 제거합니다.
 * @details 존재하지 않는 원소인 경우 아무런 변화가 없습니다.
 * @param s 변경할 비트셋의 포인터
 * @param n 제거할 원소 (비트 번호)
 */
void remove_bset(BitSet* s, int n);

/**
 * @brief 집합에 포함된 총 원소의 개수를 구합니다.
 * @details Brian Kernighan의 비트 카운팅 알고리즘(bs &= bs - 1)을 사용하여
 * 켜져 있는 비트(1)의 개수를 빠르게 계산합니다.
 * @param s 원소 개수를 샐 비트셋 집합 (상수)
 * @return int 집합에 포함된 원소의 개수
 */
int size_bset(const BitSet s);

/**
 * @brief 집합의 모든 원소를 중괄호 형태로 표준 출력에 출력합니다.
 * @details 예: { 3 7 15 } 형태로 출력됩니다.
 * @param s 출력할 비트셋 집합 (상수)
 */
void print_bset(const BitSet s);

#endif // !BITSET
