/**
 * @file    IntSet.h
 * @brief   동적 배열을 이용한 정수형 집합(Set) 라이브러리
 * @details 중복을 허용하지 않고 순서가 없는 집합 자료구조를 배열로 구현한 헤더 파일입니다.
 */

#ifndef INT_SET_H
#define INT_SET_H

/**
 * @struct IntSet
 * @brief  정수형 집합을 관리하는 구조체
 */
typedef struct {
    int max;   /**< 집합이 담을 수 있는 최대 원소 개수 (배열 크기) */
    int num;   /**< 현재 집합에 저장된 원소의 개수 */
    int *set;  /**< 정수 데이터를 저장할 동적 할당 배열의 포인터 */
} IntSet; 


/**
 * @brief  집합 구조체의 메모리를 할당하고 초기화한다.
 * @param  s: 초기화할 집합 구조체의 포인터
 * @param  max: 집합의 최대 용량 (배열 크기)
 * @return int: 성공 시 1, 메모리 할당 실패 시 -1
 * @note   사용 후 메모리 누수를 방지하기 위해 반드시 terminate_intSet()을 호출해야 합니다.
 */
int init_IntSet(IntSet *s, int max);

/**
 * @brief  집합 내에 특정 정수 원소가 존재하는지 검사한다.
 * @param  s: 검사할 집합의 포인터
 * @param  n: 찾고자 하는 정수 값
 * @return int: 원소가 존재하면 해당 원소의 배열 인덱스(0 이상), 존재하지 않으면 -1
 */
int is_member(const IntSet *s, int n);

/**
 * @brief  집합이 꽉 찼는지 확인한다.
 * @param  s: 확인할 집합의 포인터
 * @return int: 꽉 찼으면 1, 여유 공간이 있으면 0
 */
int is_full(const IntSet *s);

/**
 * @brief  집합의 모든 원소를 지우고 비운다.
 * @param  s: 비울 집합의 포인터
 * @note   배열의 메모리를 해제하는 것이 아니라 현재 크기(num)만 0으로 초기화합니다.
 */
void clear_set(IntSet *s);

/**
 * @brief  집합에 새로운 원소를 추가한다.
 * @param  s: 원소를 추가할 집합의 포인터
 * @param  n: 추가할 정수 값
 * @return int: 성공 시 1, 실패(용량 초과 또는 이미 존재하는 원소) 시 -1
 * @see    is_full, is_member
 */
int add_ele(IntSet *s, int n);

/**
 * @brief  집합에서 특정 원소를 제거한다.
 * @param  s: 원소를 제거할 집합의 포인터
 * @param  n: 제거할 정수 값
 * @note   원소 제거 후 빈자리는 배열의 가장 마지막 원소를 옮겨와 채웁니다. (O(1) 연산)
 */
void remove_ele(IntSet *s, int n);

/**
 * @brief  집합이 가질 수 있는 최대 원소 개수(용량)를 반환한다.
 * @param  s: 확인할 집합의 포인터
 * @return int: 집합의 최대 용량 (max)
 */
int capacity(const IntSet *s);

/**
 * @brief  집합에 현재 저장된 원소의 개수를 반환한다.
 * @param  s: 확인할 집합의 포인터
 * @return int: 현재 원소 개수 (num)
 */
int size(const IntSet *s);

/**
 * @brief  원본 집합의 내용을 대상 집합에 복사(대입)한다.
 * @param  s1: 데이터가 복사될 대상(Destination) 집합의 포인터
 * @param  s2: 복사할 원본(Source) 집합의 포인터
 * @note   s1의 용량이 s2의 원소 개수보다 작다면 s1의 용량만큼만 복사됩니다.
 */
void assign(IntSet *s1, const IntSet *s2);

/**
 * @brief  두 집합이 서로 같은 집합인지 동등성을 검사한다.
 * @param  s1: 비교할 첫 번째 집합의 포인터
 * @param  s2: 비교할 두 번째 집합의 포인터
 * @return int: 두 집합의 원소가 완전히 일치하면 1, 하나라도 다르면 0 (배열 내 순서는 상관없음)
 */
int is_equal(const IntSet *s1, const IntSet *s2);

/**
 * @brief  두 집합의 합집합을 구하여 지정된 집합에 저장한다. (s1 = s2 ∪ s3)
 * @param  s1: 연산 결과(합집합)를 저장할 집합의 포인터
 * @param  s2: 첫 번째 원본 집합의 포인터
 * @param  s3: 두 번째 원본 집합의 포인터
 * @return IntSet*: 연산 결과가 저장된 s1의 포인터
 */
IntSet* union_set(IntSet *s1, const IntSet *s2, const IntSet *s3);

/**
 * @brief  기존 집합에 다른 집합의 모든 원소를 누적하여 합친다. (s1 = s1 ∪ s2)
 * @param  s1: 원소가 누적 추가될 집합이자 기준 집합의 포인터
 * @param  s2: 더할 집합의 포인터
 * @return IntSet*: 연산 결과가 저장된 s1의 포인터
 */
IntSet* to_union_set(IntSet *s1, const IntSet *s2);

/**
 * @brief  두 집합의 교집합을 구하여 지정된 집합에 저장한다. (s1 = s2 ∩ s3)
 * @param  s1: 연산 결과(교집합)를 저장할 집합의 포인터
 * @param  s2: 첫 번째 원본 집합의 포인터
 * @param  s3: 두 번째 원본 집합의 포인터
 * @return IntSet*: 연산 결과가 저장된 s1의 포인터
 */
IntSet* intersect_set(IntSet* s1, const IntSet *s2, const IntSet *s3);

/**
 * @brief  기준 집합에서 다른 집합과 공통으로 갖지 않은 원소들을 제거한다. (s1 = s1 ∩ s2)
 * @param  s1: 연산 결과가 반영될 기준 집합의 포인터
 * @param  s2: 비교할 집합의 포인터
 * @return IntSet*: 연산 결과가 저장된 s1의 포인터
 */
IntSet* to_intersect_set(IntSet *s1, const IntSet *s2);

/**
 * @brief  두 집합의 차집합을 구하여 지정된 집합에 저장한다. (s1 = s2 - s3)
 * @param  s1: 연산 결과(차집합)를 저장할 집합의 포인터
 * @param  s2: 기준이 되는 원본 집합의 포인터
 * @param  s3: 차감할 원본 집합의 포인터
 * @return IntSet*: 연산 결과가 저장된 s1의 포인터
 */
IntSet* difference_set(IntSet *s1, const IntSet *s2, const IntSet *s3);

/**
 * @brief  기준 집합에서 다른 집합에 포함된 모든 원소를 제거한다. (s1 = s1 - s2)
 * @param  s1: 원소가 제거될 기준 집합의 포인터
 * @param  s2: 차감할 원소들을 가진 집합의 포인터
 * @return IntSet*: 연산 결과가 저장된 s1의 포인터
 */
IntSet* to_difference_set(IntSet *s1, const IntSet *s2);

/**
 * @brief  두 집합의 대칭차집합을 구하여 지정된 집합에 저장한다. (s1 = (s2 - s3) ∪ (s3 - s2))
 * @param  s1: 연산 결과(대칭차집합)를 저장할 집합의 포인터
 * @param  s2: 첫 번째 원본 집합의 포인터
 * @param  s3: 두 번째 원본 집합의 포인터
 * @return IntSet*: 연산 결과가 저장된 s1의 포인터
 */
IntSet* symetric_difference_set(IntSet *s1, const IntSet *s2, const IntSet *s3);

/**
 * @brief  첫 번째 집합이 두 번째 집합의 부분집합인지 검사한다. (s1 ⊆ s2)
 * @param  s1: 부분집합인지 검사할 집합의 포인터
 * @param  s2: 모집합(전체 범위를 담은 집합)의 포인터
 * @return int: 부분집합이 맞으면 1, 아니면 0
 */
int is_subset(const IntSet *s1, const IntSet *s2);

/**
 * @brief  첫 번째 집합이 두 번째 집합의 진부분집합인지 검사한다. (s1 ⊂ s2)
 * @param  s1: 진부분집합인지 검사할 집합의 포인터
 * @param  s2: 모집합의 포인터
 * @return int: 진부분집합이 맞으면 1, 아니면 0 (두 집합이 완전히 같으면 0 반환)
 */
int is_subset_proper(const IntSet *s1, const IntSet *s2);

/**
 * @brief  집합 내부의 모든 원소를 콘솔 형식 `{ 1 2 3 }`으로 출력한다.
 * @param  s: 출력할 집합의 포인터
 */
void print_set(const IntSet *s); 

/**
 * @brief  집합에 할당된 동적 메모리를 해제하고 구조체를 최적화한다.
 * @param  s: 소멸시킬 집합의 포인터
 * @note   Dangling Pointer 방지를 위해 메모리 해제 후 내부 포인터를 NULL로 초기화합니다.
 */
void terminate_intSet(IntSet *s); 

#endif
