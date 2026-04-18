#include <stdio.h>

int factorial(int x){
    if(x > 0) return x*factorial(x-1); 
    return 1; 
}

int main(void){
    int x; 
    printf("x : "); scanf("%d", &x); 
    printf("%d! : %d", x, factorial(x)); 
    
    return 0; 
}
