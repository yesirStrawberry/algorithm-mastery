/*
stdlib.h의 qsort를 사용해본다. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_cmp(const char** a, const char** b){
    return strcmp(*a, *b);
}


int main()
{
    char* data[] = {
        "Apple", 
        "Banana", 
        "C", 
        "Data Structure", 
        "QuickSort", 
        "AI"
    };  
    int n = sizeof(data)/sizeof(data[0]); 
    
    qsort(data, 
          n,
          sizeof(char*),
          (int(*)(const void *, const void *))string_cmp
          ); 
    
    for(int i = 0; i < n; i++) printf(" %s",data[i]); 
    putchar('\n'); 
    
    return 0;
}
