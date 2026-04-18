/*
Deque(Double Ended Queue)를 구현한다.
이를 테스트하기 위한 main.c이다. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "IntDeque.h"

int main()
{
    IntDque dq; int x; 
    
    init_Dque(&dq, 8); 
    
    for(int i = 0; i < 5; i++){
        if(push_front(&dq, 10+i) == -1) puts("push_front failed"); 
    }
    print_IntDeque(&dq); 
    
    for(int i = 0; i < 5; i++){
        if(push_rear(&dq, 20+i) == -1) puts("push_rear failed"); 
    }
    print_IntDeque(&dq); 
    
    for(int i = 0; i < 2; i++){
        if(pop_front(&dq, &x) == -1) puts("pop_front failed");
        printf("pop front dque : %d\n", x); 
    }
    print_IntDeque(&dq); 
    
    for(int i = 0; i < 2; i++){
        if(pop_rear(&dq, &x) == -1) puts("pop_rear failed");
        printf("pop rear dque : %d\n", x); 
    }
    print_IntDeque(&dq); 
    
    return 0;
}
