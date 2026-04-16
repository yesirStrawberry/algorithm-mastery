/*
Ring Queue를 구현하고 test한다. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

void print_select_menu(IntQueue *q, int *menu_p);

int main()
{
    IntQueue q; int x; int menu; int qi;
    if(init_IntQueue(&q, 5) == -1){
        puts("Queue intialize fail"); 
        return 0; 
    }
    
    while(1){ 
        print_select_menu(&q, &menu);
        if(menu == 0) break;
        
        switch(menu){
            case 1 :
                printf("data : "); scanf("%d", &x); 
                if(enqueue(&q, x) == -1) puts("enqueue failed"); 
                break; 
            case 2 : 
                if(dequeue(&q, &x) == -1) puts("dequeue failed");
                else printf("Pop data : %d\n", x); 
                break; 
            case 3 : 
                if(peek(&q, &x) == -1) puts("Peek failed"); 
                else printf("Peek data : %d\n", x); 
                break; 
            case 4 : 
                clear(&q); 
                break; 
            case 5 : 
                printf("Capacity : %d\n", capacity(&q)); 
                break;
            case 6 : 
                printf("size : %d\n", size(&q));
                break;
            case 7 : 
                if(is_empty(&q)) puts("is empty"); 
                else puts("is not empty"); 
                break;
            case 8 : 
                if(is_full(&q)) puts("is full"); 
                else puts("is not full"); 
                break;
            case 9 : 
                printf("key : "); scanf("%d", &x);
                qi = search(&q, x);
                if(qi == -1) puts("Can't find"); 
                else printf("q->que[%d] : %d\n", qi, x); 
                break; 
            case 10 : 
                printf("key : "); scanf("%d", &x);
                qi = search2(&q, x);
                if(qi == -1) puts("Can't find"); 
                else printf("%d번째 dequeue 시 출력 : %d\n", qi, x); 
                break; 
            case 11 : print_IntQueue(&q); break; 
        }
    }
    
    terminate(&q); 
    return 0;
}

void print_select_menu(IntQueue *q, int *menu_p){
    puts("-------------------------------------------------");
    printf("current data number : %d/%d\n", q->num, q->max); 
    puts("(00) stop\n(01) enqueue\n(02) dequeue\n(03) peek\n(04) clear");
    puts("(05) Capacity\n(06) Size\n(07) IsEmpty\n(08) IsFull");
    puts("(09) search\n(10) search2\n(11) print");
    printf("menu : "); scanf("%d", menu_p); 
}
