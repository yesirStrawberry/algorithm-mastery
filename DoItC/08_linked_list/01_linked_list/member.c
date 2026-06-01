#include <string.h>
#include <stdio.h>
#include "member.h"

void print_member(const member *x){
    puts("--------------"); 
    printf("name : %s\n", (x == NULL) ? "NULL" : x->name); 
    printf("age  : %d\n", (x == NULL) ? -1 : x->age); 
}
