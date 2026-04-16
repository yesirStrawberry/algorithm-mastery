#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

void print_select_menu(IntStack *s, int *menu_p){
    puts("-------------------------------------------------");
    printf("current data number : %d/%d\n", s->ptr, s->max); 
    puts("(0) stop\n(1) push\n(2) pop\n(3) peek\n(4) clear");
    puts("(5) Capacity\n(6) Size\n(7) IsEmpty\n(8) IsFull\n(9) search\n(10) print");
    printf("menu : "); scanf("%d", menu_p); 
}

int main()
{
    IntStack s; int x; int menu; 
    if(Initialize(&s, 64) == -1){
        puts("stack intialize fail"); 
        return 0; 
    }
    
    while(1){ 
        print_select_menu(&s, &menu);
        if(menu == 0) break;
        
        switch(menu){
            case 1 :
                printf("data : "); scanf("%d", &x); 
                if(Push(&s, x) == -1) puts("Push failed\n"); 
                break; 
            case 2 : 
                if(Pop(&s, &x) == -1) puts("Pop failed\n");
                else printf("Pop data : %d\n", x); 
                break; 
            case 3 : 
                if(Peek(&s, &x) == -1) puts("Peek failed\n"); 
                else printf("Peek data : %d\n", x); 
                break; 
            case 4 : 
                Clear(&s); 
                break; 
            case 5 : 
                printf("Capacity : %d\n", Capacity(&s)); 
                break;
            case 6 : 
                printf("size : %d\n", Size(&s));
                break;
            case 7 : 
                if(IsEmpty(&s) == 0) puts("Stack is empty\n"); 
                else puts("Stack is not empty\n"); 
                break;
            case 8 : 
                if(IsFull(&s) == 0) puts("Stack is full\n"); 
                else puts("Stack is not full\n"); 
                break;
            case 9 : 
                printf("key : "); scanf("%d", &x);
                int si = Search(&s, x);
                if(si == -1) puts("Can't find\n"); 
                else printf("s->stk[%d] : %d\n", si, x); 
                break; 
            case 10 : print(&s); break; 
        }
    }
    
    Terminate(&s); 

    return 0;
}
