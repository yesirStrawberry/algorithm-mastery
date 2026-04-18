/*
두 수의 최소공약수를 구하는 알고리즘인 유클리드 호제법을 제귀로 구현한다. 
*/

#include <stdio.h>

int gcd(int x, int y){
    printf("x : %d, y : %d\n", x, y);
    
    if(y == 0) return x; 
    else return gcd(y,x%y); 
}


int main(void){
    int x, y; 
    printf("x : "); scanf("%d", &x); 
    printf("y : "); scanf("%d", &y); 
    
    printf("%d와 %d의 최소공약수 : %d", x, y, gcd(x,y));
    
    return 0; 
}
