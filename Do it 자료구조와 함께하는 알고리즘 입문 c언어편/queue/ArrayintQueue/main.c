#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

int main(void){
    IntQueue q; int x;  
    if(init_IntQueue(&q, 10) == -1){
        puts("initialize failed"); return 0;
    }
    
    for(int i = 0; i < 5; i++){
        printf("data : "); scanf("%d", &x); 
        if(enqueue(&q, x) == -1){
            puts("enqueue failed"); 
            return 0; 
        }
    }
    print_IntQueue(&q); 
    
    if(dequeue(&q, &x) == -1){
        puts("dequeue failed"); 
        return 0; 
    }
    else printf("dequeue x : %d\n", x); 
    print_IntQueue(&q); 
    
    return 0; 
}
