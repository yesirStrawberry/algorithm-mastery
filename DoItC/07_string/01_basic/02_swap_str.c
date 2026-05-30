#include <stdio.h>
#include <string.h>
/**
 * output
=== 1. SWAP 매크로 검증 (정수형 변수 교환) ===
[전] num1 = 10, num2 = 20
[후] num1 = 20, num2 = 10

=== 2. swap_ptr 검증 (포인터 주소 교환) ===
[전] ptr1이 가리키는 곳: Apple, ptr2가 가리키는 곳: Banana
[후] ptr1이 가리키는 곳: Banana, ptr2가 가리키는 곳: Apple

=== 3. swap_str 검증 (배열 내부 값 교환) ===
[전] array1 데이터: Red, array2 데이터: Blue
[후] array1 데이터: Blue, array2 데이터: Red
 */


/**
 * @brief  자료형에 안전한 범용 값 교환(Swap) 매크로
 * @details do-while(0) 구조를 사용하여 if-else 제어문 내부 등 
 * 어떤 문법적 상황에서도 세미콜론이 안전하게 확장되도록 설계된 매크로입니다.
 * * @tparam type 교환할 변수의 자료형 (예: int, double, char 등)
 * @param  x    교환할 첫 번째 변수
 * @param  y    교환할 두 번째 변수
 */
#define SWAP(type, x, y) do { type t = x; x = y; y = t; } while(0)

/**
 * @brief  두 문자열 포인터의 가리키는 주소 자체를 교환하는 함수
 * @details 실제 데이터가 저장된 메모리 영역을 수정하지 않고, 문자열을 가리키는 
 * 포인터(화살표 방향)만 서로 바꿉니다. 데이터 복사가 일어나지 않아 속도가 매우 빠르며,
 * 수정이 불가능한 '문자열 리터럴(Read-only memory)'을 스왑할 때 필수적으로 사용됩니다.
 * * @param[in,out] x 주소값을 교환할 첫 번째 문자열 포인터의 주소 (더블 포인터)
 * @param[in,out] y 주소값을 교환할 두 번째 문자열 포인터의 주소 (더블 포인터)
 */
void swap_ptr(char **x, char **y) {
    char *tmp = *x;
    *x = *y;
    *y = tmp; 
}

/**
 * @brief  두 char 배열 내부의 문자열 데이터(메모리 내용물)를 직접 교환하는 함수
 * @details 포인터의 위치(주소)는 그대로 유지한 채, 각 포인터가 가리키고 있는 
 * 메모리 버퍼 안의 실제 값들을 복사하여 바꿉니다. 
 * 내부적으로 각 문자열의 크기(널 문자 포함)를 구한 뒤 memcpy를 통해 교환을 수행합니다.
 * * @note   이 함수는 반드시 수정 가능한 메모리 공간(char 배열 등)을 대상으로 호출해야 합니다.
 * 문자열 리터럴을 전달할 경우 세그멘테이션 폴트(Segmentation fault)가 발생합니다.
 * * @param[in,out] x 데이터를 교환할 첫 번째 char 배열 영역의 시작 주소
 * @param[in,out] y 데이터를 교환할 두 번째 char 배열 영역의 시작 주소
 */
void swap_str(char *x, char *y) {
    char tmp[256]; 
    int cnt_x = 0;
    int cnt_y = 0; 
    
    // x 문자열의 글자 수 측정 (널 문자 자리 포함)
    for(char *c = x; *c != '\0'; c++) cnt_x++;
    cnt_x++;
    
    // y 문자열의 글자 수 측정 (널 문자 자리 포함)
    for(char *c = y; *c != '\0'; c++) cnt_y++;
    cnt_y++;
    
    // 메모리 블록 데이터를 통째로 맞바꾸기
    memcpy(tmp, x, cnt_x);
    memcpy(x, y, cnt_y);
    memcpy(y, tmp, cnt_x);
}


int main(void) {
    printf("=== 1. SWAP 매크로 검증 (정수형 변수 교환) ===\n");
    int num1 = 10, num2 = 20;
    printf("[전] num1 = %d, num2 = %d\n", num1, num2);
    SWAP(int, num1, num2);
    printf("[후] num1 = %d, num2 = %d\n\n", num1, num2);


    printf("=== 2. swap_ptr 검증 (포인터 주소 교환) ===\n");
    // 읽기 전용 영역(Text)의 데이터를 가리키는 포인터
    char *ptr1 = "Apple";
    char *ptr2 = "Banana";
    printf("[전] ptr1이 가리키는 곳: %s, ptr2가 가리키는 곳: %s\n", ptr1, ptr2);
    
    // 포인터 자체의 메모리 주소를 넘겨주어야 하므로 주소 연산자(&) 사용
    swap_ptr(&ptr1, &ptr2);
    printf("[후] ptr1이 가리키는 곳: %s, ptr2가 가리키는 곳: %s\n\n", ptr1, ptr2);


    printf("=== 3. swap_str 검증 (배열 내부 값 교환) ===\n");
    // 값 변경이 가능한 스택(Stack) 영역의 char 배열 버퍼 생성
    char array1[256] = "Red";
    char array2[256] = "Blue";
    printf("[전] array1 데이터: %s, array2 데이터: %s\n", array1, array2);
    
    // 배열의 이름은 그 자체로 주소값이므로 바로 전달
    swap_str(array1, array2);
    printf("[후] array1 데이터: %s, array2 데이터: %s\n", array1, array2);

    return 0;
}
