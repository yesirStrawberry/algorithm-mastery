/*
p.182 Q5  재귀함수를 비재귀적으로 변환하라
재귀함수
void recur(int n){
    if(n > 1){
        recur(n - 2); 
        recur(n - 1); 
        puts(n); 
    }
}
를 비재귀적으로 변환하시오.
*/

/*
stack에다 넣고, stack이 비워질때까지 while문 사용
*/

#include <stdio.h>

void recur(int n){
    if(n > 1){
        recur(n - 2); 
        recur(n - 1); 
        printf("%d", n); 
    }
}

typedef struct{
    int val; 
    int is_ready_to_print; 
}Node;

void recur_iterative(int n){
    int top = -1; // stack pointer, index
    Node stack[100]; 
    
    stack[++top] = (Node){n, 0}; 
    
    while(top != -1){
        Node curr = stack[top--]; 
        
        if(curr.val <= 1) continue; 
        
        if(curr.is_ready_to_print == 1){
            printf("%d", curr.val);
        }
        else{
            stack[++top] = (Node){curr.val, 1}; 
            stack[++top] = (Node){curr.val - 1, 0};
            stack[++top] = (Node){curr.val - 2, 0};
        }
    }
}

int main(void){
    int n; 
    printf("n : "); scanf("%d", &n);
    
    recur_iterative(n); 
    putchar('\n');
    recur(n);
    
    return 0; 
}



