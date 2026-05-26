/*
하나의 배열을 공유하여 2개의 스택을 구현하는 스택 프로그램을 만드시오
스택이 저장하는 데이터는 int형입니다. 
스택의 시작점은 각각 배열의 맨 앞 부분과 맨 끝 부분입니다. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "DualStack.h"

int main(void){
    DualStack s; int x; 
    init_DualStack(&s, 10); 
    
    if(push1(&s, 8) == -1){
        puts("array boom "); return 0; 
    };
    if(push1(&s, 7) == -1){
        puts("array boom "); return 0; 
    }; 
    if(push1(&s, 6) == -1){
        puts("array boom "); return 0; 
    }; 
    if(push1(&s, 5) == -1){
        puts("array boom "); return 0; 
    }; 
    if(push2(&s, 1) == -1){
        puts("array boom "); return 0; 
    }; 
    if(push2(&s, 2) == -1){
        puts("array boom "); return 0; 
    }; 
    if(push2(&s, 3) == -1){
        puts("array boom "); return 0; 
    }; 
    
    print_dualStack(&s); 
    
    pop1(&s, &x); printf("pop x : %d\n", x); 
    print_dualStack(&s);
    
    pop2(&s, &x); printf("pop x : %d\n", x); 
    print_dualStack(&s);
    
    
    return 0; 
}
