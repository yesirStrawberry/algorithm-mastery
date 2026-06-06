#include <stdio.h>
#include <string.h>
#include "member.h"
#include "ArrayLinkedList.h"

int compare(const member *x, const member *y);

int main(void)
{   
    List list;
    init_list(&list, 200);
    
    // 1. 샘플 데이터 셋업 (포인터 연산 안정성을 위해 문자열 리터럴 사용)
    member m1 = {"m1", 20};
    member m2 = {"m2", 22};
    member m3 = {"m3", 25};
    member m4 = {"m4", 30};
    
    puts("1111111111111111");
    print_list(&list);
    insert_front(&list, &m1); 
    print_list(&list);
    print_node(&list);
    
    
    
    puts("2222222222222222");
    insert_rear(&list, &m2); 
    print_list(&list);
    print_node(&list); 
    
    puts("3333333333333333");
    insert_rear(&list, &m3);
    insert_front(&list, &m4);
    print_list(&list);
    print_node(&list);
    
    puts("4444444444444444");
    search(&list, &m1, compare);
    print_node(&list);
    
    
    puts("5555555555555555");
    remove_current(&list); 
    print_list(&list);

    
    return 0;
}


int compare(const member *x, const member *y){
    return strcmp(x->name, y->name); 
}
