/*문자열에서 문자를 찾는 함수을 작성하시오
* string.h 의 strlen, strchr, strrchr 을 모방하여 작성하시오
*/

/**
 * output
테스트 문자열: "apple computer"
문자열 길이 (str_len): 14

--- str_chr 테스트 ---
문자 'p' 발견 주소의 문자열: "pple computer" (인덱스: 1)
문자 'z'를 찾지 못했습니다. (정상 결과)
널 문자('\0') 발견 인덱스: 14 (정상 결과)

--- str_rchr 테스트 ---
뒤에서부터 'p' 발견 주소의 문자열: "puter" (인덱스: 9)
문자 'z'를 찾지 못했습니다. (정상 결과)
뒤에서부터 널 문자('\0') 발견 인덱스: 14 (정상 결과)
 */

#include <stdio.h>

int str_len(const char *s){
    int idx = 0; 
    while(s[idx] != '\0'){
        idx++; 
    }
    return idx; 
}

char *str_chr(const char *s, int c){
    int idx = 0; 
    c = (char)c;
    
    while(s[idx] != c){
        if(s[idx] == '\0'){
            return NULL;
        }
        idx++;
    }
    
    return (char*)(s + idx); 
}

char *str_rchr(const char *s, int c){
    int idx = str_len(s); 
    c = (char)c;
    
    while(idx >= 0){
        if(s[idx] == c) return (char*)(s + idx); 
        idx--;
    }
    
    return NULL; 
}


int main(void) {
    const char *str = "apple computer";
    char target1 = 'p';
    char target2 = 'z';
    char target3 = '\0'; // 널 문자 검색 테스트용

    printf("테스트 문자열: \"%s\"\n", str);
    printf("문자열 길이 (str_len): %d\n\n", str_len(str));

    // --- str_chr 테스트 (앞에서부터 검색) ---
    printf("--- str_chr 테스트 ---\n");
    char *res_chr1 = str_chr(str, target1);
    if (res_chr1 != NULL) {
        printf("문자 '%c' 발견 주소의 문자열: \"%s\" (인덱스: %ld)\n", target1, res_chr1, res_chr1 - str);
    } else {
        printf("문자 '%c'를 찾지 못했습니다.\n", target1);
    }

    char *res_chr2 = str_chr(str, target2);
    if (res_chr2 != NULL) {
        printf("문자 '%c' 발견 주소의 문자열: \"%s\"\n", target2, res_chr2);
    } else {
        printf("문자 '%c'를 찾지 못했습니다. (정상 결과)\n", target2);
    }
    
    char *res_chr3 = str_chr(str, target3);
    if (res_chr3 != NULL) {
        printf("널 문자('\\0') 발견 인덱스: %ld (정상 결과)\n\n", res_chr3 - str);
    }

    // --- str_rchr 테스트 (뒤에서부터 검색) ---
    printf("--- str_rchr 테스트 ---\n");
    char *res_rchr1 = str_rchr(str, target1);
    if (res_rchr1 != NULL) {
        // 'apple computer'에서 뒤에서부터 'p'를 찾으면 'computer' 앞의 'apple'의 두 번째 'p'가 잡힙니다.
        printf("뒤에서부터 '%c' 발견 주소의 문자열: \"%s\" (인덱스: %ld)\n", target1, res_rchr1, res_rchr1 - str);
    } else {
        printf("문자 '%c'를 찾지 못했습니다.\n", target1);
    }

    char *res_rchr2 = str_rchr(str, target2);
    if (res_rchr2 != NULL) {
        printf("뒤에서부터 '%c' 발견 주소의 문자열: \"%s\"\n", target2, res_rchr2);
    } else {
        printf("문자 '%c'를 찾지 못했습니다. (정상 결과)\n", target2);
    }

    char *res_rchr3 = str_rchr(str, target3);
    if (res_rchr3 != NULL) {
        printf("뒤에서부터 널 문자('\\0') 발견 인덱스: %ld (정상 결과)\n", res_rchr3 - str);
    }

    return 0;
}
