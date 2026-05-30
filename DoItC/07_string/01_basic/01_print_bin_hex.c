/* 문자열 literal을 16진수와 2진수로 출력한다. */

/* output
S 53 01010011
T 54 01010100
R 52 01010010
I 49 01001001
N 4E 01001110
G 47 01000111
 00 00000000
*/

#include <stdio.h>
#include <limits.h>

void str_dump(const char *s){
    do{
        int i; 
        
        /* char을 16진수로 출력
        * %c <-> *s 해당하는 char 출력
        * %0*X 
        * 중간의 *은 (CHAR_BIT + 3) / 4과 연결되어, 
          만일 CHAR_BIT가 9인 경우에 3자리로 16진수가 출력되게 한다.
        * X는 hexadecimal로 출력되게한다. 
        */
        printf("%c %0*X ", *s, (CHAR_BIT + 3) / 4, *s);
        
        /* char을 2진수로 출력
        * MSB부터 LSB까지 접근한다
        * *s >> i을 확인하고자하는 비트를 LSB로 보낸다
        * 이를 1U(unsigned 1, 00000001)과 비트연산의 결과를 활용하여, 1혹은 0을 출력한다.
        */
        for(i = CHAR_BIT - 1; i >= 0; i--)
            putchar(((*s >> i) & 1U) ? '1' : '0');
        putchar('\n');
    }while(*s++ != '\0'); 
}


int main()
{
    str_dump("STRING");
    return 0;
}
