#include <stdio.h>
#include "str_match.h"

int main()
{
    const char text[] = "abcdabcdebcd";
    const char pattern[] = "abcd";
    int result;

    printf("========================================\n");
    printf(" 테스트 1: 순방향 탐색 (bf_match)\n");
    printf(" 텍스트: %s, 패턴: %s\n", text, pattern);
    printf("========================================\n");
    
    result = bf_match(text, pattern);
    printf("순방향 탐색 매칭 결과 인덱스: %d\n\n", result);


    printf("========================================\n");
    printf(" 테스트 2: 역방향 탐색 (bf_matchr)\n");
    printf(" 텍스트: %s, 패턴: %s\n", text, pattern);
    printf("========================================\n");
    
    result = bf_matchr(text, pattern);
    printf("역방향 탐색 매칭 결과 인덱스: %d\n\n", result);


    printf("========================================\n");
    printf(" 테스트 3: 예외 케이스 (존재하지 않는 패턴 탐색)\n");
    printf(" 텍스트: %s, 패턴: %s\n", text, "efg");
    printf("========================================\n");
    
    result = bf_match(text, "efg");
    printf("매칭 결과 인덱스 (기대값 -1): %d\n", result);

    return 0;
}
