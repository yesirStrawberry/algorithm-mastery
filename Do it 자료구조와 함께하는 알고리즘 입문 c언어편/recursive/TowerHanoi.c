/*
p.181 하노이의 탑의 제귀적 구현
*/
#include <stdio.h>

void move(int n, int s, int e){
    int m = 6 - s - e; 
    if(n > 1) move(n - 1, s, m); 
    printf("원반[%d]가 %d 에서 %d로 옮겨짐\n", n, s, e); 
    if(n > 1) move(n - 1, m, e); 
}

int main()
{
    int n; 
    printf("n : "); scanf("%d", &n); 
    move(n,1,3); 
    return 0;
}
