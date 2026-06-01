#include <string.h>
#include <stdio.h>
#include "member.h"

void print_member(const member *x){
    puts("--------------"); 
    printf("name : %s\n", x->name); 
    printf("age  : %d\n", x->age); 
}
